import copy
import random
from difflib import SequenceMatcher

from pycparser import c_ast, c_parser, c_generator

from path_helper import is_scanf_or_printf


class Chromosome:
    def initialise_insert_pool(self, statements):
        return [copy.deepcopy(value) for key, value in statements.items()]

    def add_elem_in_pool(self, elem, pool, show):
        if str(elem) not in show:
            pool.append(elem)
            show.append(str(elem))

    def initialise_pools(self, statements):
        r_values_show = []
        l_values_show = []
        unary_op_show = []

        for key, value in statements.items():
            if isinstance(value, c_ast.For):
                if isinstance(value.next, c_ast.UnaryOp):
                    self.add_elem_in_pool(copy.deepcopy(value.next), self.unary_expr_pool, unary_op_show)
                elif isinstance(value.next, c_ast.Assignment):
                    self.add_elem_in_pool(copy.deepcopy(value.next.rvalue), self.rvalues_pool, r_values_show)
                    self.add_elem_in_pool(copy.deepcopy(value.next.lvalue), self.rvalues_pool, r_values_show)
                    self.add_elem_in_pool(copy.deepcopy(value.next.lvalue), self.lvalues_pool, l_values_show)
                if isinstance(value.init, c_ast.DeclList):
                    self.add_elem_in_pool(copy.deepcopy(value.init.decls[0].init), self.rvalues_pool, r_values_show)
                elif isinstance(value.init, c_ast.Assignment):
                    self.add_elem_in_pool(copy.deepcopy(value.init.lvalue), self.lvalues_pool, l_values_show)
                    self.add_elem_in_pool(copy.deepcopy(value.init.lvalue), self.rvalues_pool, r_values_show)
                    self.add_elem_in_pool(copy.deepcopy(value.init.rvalue), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.right), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.left), self.lvalues_pool, l_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.left), self.rvalues_pool, r_values_show)
            elif isinstance(value, c_ast.Assignment):
                self.add_elem_in_pool(copy.deepcopy(value.lvalue), self.lvalues_pool, l_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.lvalue), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.rvalue), self.rvalues_pool, r_values_show)
            elif isinstance(value, c_ast.UnaryOp):
                self.add_elem_in_pool(copy.deepcopy(value), self.unary_expr_pool, unary_op_show)

    def initialise_components(self):
        for key, _ in self.statements.items():
            self.statement_ids[key] = key
            self.insert_pool = [copy.deepcopy(value) for _, value in self.statements.items()]
        self.initialise_pools(self.statements)

    def __init__(self, statements, weights, parent, pos_in_parent, statement_count, ast):
        self.statements = statements
        self.weights = weights
        self.parent = parent
        self.pos_in_parent = pos_in_parent
        self.statement_count = statement_count
        self.initial_statement_count = statement_count
        self.ast = ast
        self.statement_ids = {}
        self.unary_expr_pool = []
        self.operators_pool = []
        self.rvalues_pool = []
        self.lvalues_pool = []
        self.exprs_show = []
        self.relational_op_pool = ['<', '>', '<=', '>=']
        self.fitness = None
        self.initialise_components()


def traverse_statement1(stmt):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights

    initial_statement_count = copy.deepcopy(statement_count)


    for node in stmt:
        if isinstance(node, c_ast.Compound):
            size = len(node.block_items)
            i=0
            statement_count += 1

            while i<size:
                if not (isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If) or isinstance(node.block_items[i], c_ast.Decl) or is_scanf_or_printf(node.block_items[i])):
                    # add statement in dictionary based on id (statement_count)
                    statements[statement_count] = node.block_items[i]
                    parents[statement_count] = node.block_items
                    pos_in_parent[statement_count] = i
                    weights[statement_count] = random.randint(0,1)
                    # weights[statement_count] = parent_weights[statement_count]

                    statement_count+=1
                elif isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If):
                    if isinstance(node.block_items[i], c_ast.For):
                        statements[statement_count] = node.block_items[i]
                                                    # [copy_node.block_items[i].init,
                                                    #    copy_node.block_items[i].cond,
                                                    #    copy_node.block_items[i].next]
                        parents[statement_count] = node.block_items
                        pos_in_parent[statement_count] = i
                        weights[statement_count] = random.randint(0,1)

                    traverse_statement1(node.block_items[i])
                elif is_scanf_or_printf(node.block_items[i]):
                    if initial_statement_count in statements:
                        del statements[initial_statement_count]
                i+=1


def traverse_statement2(stmt):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights
    global statement_count_parent2

    initial_statement_count = copy.deepcopy(statement_count)


    for node in stmt:
        if isinstance(node, c_ast.Compound):
            size = len(node.block_items)
            i=0
            statement_count += 1

            while i<size:
                if not (isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If) or isinstance(node.block_items[i], c_ast.Decl) or is_scanf_or_printf(node.block_items[i])):
                    # add statement in dictionary based on id (statement_count)
                    statements[statement_count] = node.block_items[i]
                    parents[statement_count] = node.block_items
                    pos_in_parent[statement_count] = i

                    # print(str(statement_count_parent2)+" "+str(len(parent_weights)))
                    weights[statement_count] = random.randint(0,1)
                    # statement_count_parent2 += 1

                    statement_count+=1
                elif isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If):
                    if isinstance(node.block_items[i], c_ast.For):
                        statements[statement_count] = node.block_items[i].init
                                                    # [copy_node.block_items[i].init,
                                                    #    copy_node.block_items[i].cond,
                                                    #    copy_node.block_items[i].next]
                        parents[statement_count] = node.block_items
                        pos_in_parent[statement_count] = i

                        weights[statement_count ] = random.randint(0,1)
                        # statement_count_parent2 += 1
                    traverse_statement2(node.block_items[i])
                elif is_scanf_or_printf(node.block_items[i]):
                    if initial_statement_count in statements:
                        del statements[initial_statement_count]
                i+=1


def traverse_ast(parent1, parent2, cut):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights
    global statement_count_parent2

    # copiaza in child1 parent1[:cut1]
    for i in range(cut):
        if not (isinstance(parent1.ext[0].body.block_items[i], c_ast.For) or isinstance(
                parent1.ext[0].body.block_items[i], c_ast.While) or isinstance(parent1.ext[0].body.block_items[i],
                                                                               c_ast.If) or isinstance(parent1.ext[0].body.block_items[i], c_ast.Decl) or is_scanf_or_printf(parent1.ext[0].body.block_items[i])):

            # add statement in dictionary based on id (statement_count)
            statements[statement_count] = parent1.ext[0].body.block_items[i]
            parents[statement_count] = parent1.ext[0].body.block_items
            pos_in_parent[statement_count] = i
            weights[statement_count] = random.randint(0,1)

            # weights[statement_count] = weights1[statement_count]

            statement_count += 1
        elif isinstance(parent1.ext[0].body.block_items[i], c_ast.For) or isinstance(parent1.ext[0].body.block_items[i],
                                                                                     c_ast.While) or isinstance(
                parent1.ext[0].body.block_items[i], c_ast.If):
            if isinstance(parent1.ext[0].body.block_items[i], c_ast.For):
                statements[statement_count] = parent1.ext[0].body.block_items[
                    i]
                parents[statement_count] = parent1.ext[0].body.block_items
                pos_in_parent[statement_count] = i
                weights[statement_count] = random.randint(0,1)

            traverse_statement1(parent1.ext[0].body.block_items[i])

    parent1.ext[0].body.block_items = parent1.ext[0].body.block_items[:cut]

    for i in range(cut, len(parent2.ext[0].body.block_items)):
        if not (isinstance(parent2.ext[0].body.block_items[i], c_ast.For) or isinstance(
                parent2.ext[0].body.block_items[i], c_ast.While) or isinstance(parent2.ext[0].body.block_items[i],
                                                                               c_ast.If) or isinstance(parent2.ext[0].body.block_items[i], c_ast.Decl) or is_scanf_or_printf(parent2.ext[0].body.block_items[i])):

            # add statement in dictionary based on id (statement_count)
            statements[statement_count] = parent2.ext[0].body.block_items[i]
            parents[statement_count] = parent2.ext[0].body.block_items
            pos_in_parent[statement_count] = i
            weights[statement_count] = random.randint(0,1)

            statement_count += 1
        elif isinstance(parent2.ext[0].body.block_items[i], c_ast.For) or isinstance(parent2.ext[0].body.block_items[i],
                                                                                     c_ast.While) or isinstance(
                parent2.ext[0].body.block_items[i], c_ast.If):
            if isinstance(parent2.ext[0].body.block_items[i], c_ast.For):
                statements[statement_count] = parent2.ext[0].body.block_items[
                    i]  # [node2.body.block_items[i].init, node2.body.block_items[i].cond, node2.body.block_items[i].next]
                parents[statement_count] = parent2.ext[0].body.block_items
                pos_in_parent[statement_count] = i

                weights[statement_count] = random.randint(0,1)
                # statement_count_parent2 += 1
            traverse_statement2(parent2.ext[0].body.block_items[i])

    parent1.ext[0].body.block_items.extend(parent2.ext[0].body.block_items[cut:])

    return {'child1': ""}


def crossover(parent1, parent2):
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights
    global statement_count_parent2

    statement_count = 1
    statements = {}
    parents = {}
    pos_in_parent = {}
    weights = {}

    parent22=copy.deepcopy(parent2)
    parent11=copy.deepcopy(parent1)


    parent1_body_size = len(parent1.ext[0].body.block_items)
    parent2_body_size = len(parent2.ext[0].body.block_items)

    cut1 = random.randint(0, parent1_body_size-1)
    cut2 = random.randint(0, parent2_body_size-1)

    traverse_ast(parent1, parent2, cut1)
    child1 = Chromosome(statements, weights, parents, pos_in_parent, statement_count, parent1)

    statement_count = 1
    statements = {}
    parents = {}
    pos_in_parent = {}
    weights = {}

    traverse_ast(parent22, parent11, cut2)
    child2 = Chromosome(statements, weights, parents, pos_in_parent, statement_count, parent22)

    return {'child1':child1, 'child2':child2}


# def main():
#     p0i = """int main() {
#     int n, v[1001], k;
#     scanf("%d%d", &n, &k);
#     for (int i = 1; i <= n; i++) {
#         scanf("%d", &v[i]);
#     }
#     for (int i = n-1 ; i >= k; i--) {
#         v[i] = v[i + 1];
#     }
#
#     n--;
#     for (int i = 1; i <= n; i++) {
#         printf("%d ", v[i]);
#     }
#     return 0;
# }
# """
#
#     p0c = """int main() {
#     int n, v[1001], k;
#     scanf("%d%d", &n, &k);
#     for (int i = 1; i <= n; i++) {
#         scanf("%d", &v[i]);
#     }
#     for (int i = k ; i <= n-1; i++) {
#         v[i] = v[i + 1];
#     }
#
#     n--;
#     for (int i = 1; i <= n; i++) {
#         printf("%d ", v[i]);
#     }
#     return 0;
# }"""
#
#     p1i="""int main()
# {
#     int n, m, i, j, a[101][101], k, v[10001], p=0;
#     scanf("%d", &n);
#     for(i=1; i<=n; i++)
#     {
#         for(j=1; j<=n; j++)
#         {
#             scanf("%d", &a[i][j]);
#         }
#     }
#     for(i=1; i<=n; i++)
#     {
#         if(i%2==0)
#         {
#             for(j=i,k=1; j>=1; j--,k++)
#             {
#                 p++;
#                 v[p] = a[j][k];
#             }
#         }
#         else
#         {
#             for(j=i,k=1; j>=1; j--,k++)
#             {
#                 p++; v[p] = a[k][j];
#             }
#         }
#     }
#     for(j=1; j<=n-1; j++)
#     {
#         if((n%2==1 && j%2==0) || (n%2==0 && j%2==1))
#         {
#             for(i=j+1,k=n; i<=n; i++,k--)
#             {
#                 p++; v[p] = a[i][k];
#             }
#         }
#         else {
#             if((n%2==0 && j%2==0) || (n%2==1 && j%2==1))
#             {
#                 for(i=n,k=j+1;i>=j+1; i--,k++)
#                 {
#                     p++; v[p] = a[k][i];
#                 }
#             }
#         }
#     }
#     for (int i=1; i<=p; i++) {
#         printf("%d ", v[i]);
#     }
# return 0;
# }"""
#     p1c="""int main()
# {
#     int n, m, i, j, a[101][101], k, v[10001], p=0;
#     scanf("%d", &n);
#     for(i=1; i<=n; i++)
#     {
#         for(j=1; j<=n; j++)
#         {
#             scanf("%d", &a[i][j]);
#         }
#     }
#     for(i=1; i<=n; i++)
#     {
#         if(i%2==0)
#         {
#             for(j=i,k=1; j>=1; j--,k++)
#             {
#                 p++;
#                 v[p] = a[j][k];
#             }
#         }
#         else
#         {
#             for(j=i,k=1; j>=1; j--,k++)
#             {
#                 p++; v[p] = a[k][j];
#             }
#         }
#     }
#     for(j=1; j<=n-1; j++)
#     {
#         if((n%2==1 && j%2==0) || (n%2==0 && j%2==1))
#         {
#             for(i=j+1,k=n; i<=n; i++,k--)
#             {
#                 p++; v[p] = a[i][k];
#             }
#         }
#         else {
#             if((n%2==0 && j%2==0) || (n%2==1 && j%2==1))
#             {
#                 for(i=n,k=j+1;i>=j+1; i--,k++)
#                 {
#                     p++; v[p] = a[i][k];
#                 }
#             }
#         }
#     }
#     for (int i=1; i<=p; i++) {
#         printf("%d ", v[i]);
#     }
# return 0;
# }"""
#
#
#     p2i = """int main() {
#     int n, p, m, a[10001]={0}, b[10001]={0}, cont=0, x;
#     scanf("%d%d", &n, &p);
#     for (int i=1; i<=n; i++) {
#         scanf("%d", &x);
#         a[x]=a[x]+1;
#     }
#     scanf("%d", &m);
#     for (int i=1; i<=m; i++) {
#         scanf("%d", &x);
#        	b[x]=b[x]+1;
#     }
#     for (int i=0; i<=10000; i++) {
#         for (int j=0; j<=10000; j++) {
#             if (i*j>=p)
#             {
#                 cont+=a[i]*b[j];
#                 break;
#             }
#             j++;
#         }
#     }
#     printf("%d", cont);
#     return 0;
# }"""
#     p2c = """int main() {
#     int n, p, m, a[10001]={0}, b[10001]={0}, cont=0, x;
#     scanf("%d%d", &n, &p);
#     for (int i=1; i<=n; i++) {
#         scanf("%d", &x);
#         a[x]=a[x]+1;
#     }
#     scanf("%d", &m);
#     for (int i=1; i<=m; i++) {
#         scanf("%d", &x);
#        	b[x]=b[x]+1;
#     }
#     for (int i=0; i<=10000; i++) {
#         for (int j=0; j<=10000; j++) {
#             if (i*j>=p)
#             {
#                 break;
#             }
#             cont+=a[i]*b[j];
#         }
#     }
#     printf("%d", cont);
#     return 0;
# }"""
# #
# #     p3i = """int main() {
# #
# #     int v[1001], n, poz1=-1, s=0, poz2=-2;
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     for (int i=1; i<=n; i++) {
# #         if (i%2==0) {
# #             poz1 = i;
# # 			break;
# #         }
# #     }
# #
# #     for (int i=n; i>=1; i--) {
# #         if (v[i]%2 == 0) {
# #             poz2=i;
# #         }
# #     }
# #
# #     for (int i=poz1; i<=poz2; i++) {
# #         s+=v[i];
# #     }
# #
# #     if (poz1 == -1) printf("NU EXISTA");
# #     else printf("%d", s);
# #     return 0;
# # }"""
# #     p3c = """int main() {
# #     int v[1001], n, poz1=-1, s=0, poz2=-2;
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     for (int i=1; i<=n; i++) {
# #         if (v[i]%2==0) {
# #             poz1 = i;
# # 			break;
# #         }
# #     }
# #
# #     for (int i=n; i>=1; i--) {
# #         if (v[i]%2 == 0) {
# #             poz2=i;
# #             break;
# #         }
# #     }
# #
# #     for (int i=poz1; i<=poz2; i++) {
# #         s+=v[i];
# #     }
# #
# #     if (poz1 == -1) printf("NU EXISTA");
# #     else printf("%d", s);
# #     return 0;
# # }"""
# #
# #     p4i = """int main() {
# #     int n, v[201], cont=0;
# #     scanf( "%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int dr, st;
# #     dr=1; st=n;
# #     while (dr<st) {
# #         int a=v[dr];
# #         int b=v[st];
# #
# #         while (a==b) {
# #             if (a>b) b=b-a;
# #             else a=a-b;
# #         }
# #
# #         if (a==1) cont++;
# #         else {
# #             dr++;
# #             st--;
# #         }
# #
# #         dr++;
# #         st--;
# #     }
# #     printf("%d", cont);
# # 	return 0;
# # }"""
# #     p4c = """int main() {
# #     int n, v[201], cont=0;
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int dr, st;
# #     dr=1; st=n;
# #     while (dr<st) {
# #         int a=v[dr];
# #         int b=v[st];
# #
# #         while (a!=b) {
# #             if (a<b) b=b-a;
# #             else a=a-b;
# #         }
# #
# #         if (a==1) {cont++;}
# #
# #
# #         dr++;
# #         st--;
# #     }
# #     printf("%d", cont);
# # 	return 0;
# # }"""
# #
# #     p5i = """int main() {
# #     int n, v[101], ordonat = 1, prev;
# #
# #     scanf( "%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int ok_par=0;
# #     for (int i=1; i<=n; i++) {
# #         if (v[i]%2 == 0) {
# #             if (ok_par==0) { ok_par = 1;}
# #             if (ok_par==1 && v[i] > prev) { ordonat = 0; ok_par=0;}
# #             prev = v[i];
# #
# #         }
# #     }
# #
# #     if (ordonat==1) printf("DA");
# #     else printf("NU");
# #     return 0;
# # }"""
# #     p5c = """int main() {
# #     int n, v[101], ordonat = 1, prev;
# #
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int ok_par=0;
# #     for (int i=1; i<=n; i++) {
# #         if (v[i]%2 == 0) {
# #             if (ok_par==0) { ok_par = 1; prev=v[i];}
# #             if (ok_par==1 && v[i] < prev) { ordonat = 0;}
# #             prev = v[i];
# #
# #         }
# #     }
# #
# #     if (ordonat==1) printf("DA");
# #     else printf("NU");
# #     return 0;
# # }"""
# #
# #     p6i = """int main() {
# #     int n, v[101];
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int ok=1;
# #     for (int i=1; i<=n; i++) {
# #         int x=v[i], nr_cif=0;
# #         if (x>=0 && x<=9) nr_cif = 1;
# #         if (x==0) nr_cif = 1;
# #         while (x!=0) {
# #             nr_cif++;
# #             x=x/10;
# #         }
# #         if (nr_cif%2==1) {
# #             ok=1;
# #         }
# #     }
# #     if (ok==0) printf("DA");
# #     else printf("NU");
# #     return 0;
# # }"""
# #     p6c = """int main() {
# #     int n, v[101];
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int ok=1;
# #     for (int i=1; i<=n; i++) {
# #         int x=v[i], nr_cif=0;
# #         if (x==0) nr_cif = 1;
# #         while (x!=0) {
# #             nr_cif++;
# #             x=x/10;
# #         }
# #         if (nr_cif%2==1) {
# #             ok=0;
# #         }
# #     }
# #     if (ok==1) printf("DA");
# #     else printf("NU");
# #     return 0;
# # }"""
# #
# #     p7i = """int main() {
# #
# #     int n, v[1001];
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int minim = v[1];
# #     for (int i=1; i<=n; i++)
# #         if (v[i]<minim) minim=v[i];
# #
# #     int i=1;
# #     while (i<=n) {
# #         if (v[i] == minim) {
# #             v[n]=v[n+1];
# #             for (int k=i; k<=n; k++) {
# #                 v[k] = v[k+1];
# #             }
# #             n--;
# #         }
# #         i++;
# #     }
# #
# #     for (int i=1; i<=n; i++) printf("%d ", v[i]);
# #     return 0;
# # }"""
# #     p7c = """int main() {
# #     int n, v[1001];
# #     scanf("%d", &n);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     int minim = v[1];
# #     for (int i=1; i<=n; i++)
# #         if (v[i]<minim) minim=v[i];
# #
# #     int i=1;
# #     while (i<=n) {
# #         if (v[i] == minim) {
# #             for (int k=n; k>=i; k--) {
# #                 v[k+1] = v[k];
# #             }
# #             n++;
# #             i++;
# #         }
# #         i++;
# #     }
# #
# #     for (int i=1; i<=n; i++) printf("%d ", v[i]);
# #     return 0;
# # }"""
# #
# #     p8i = """int main() {
# #     int n, s, v[101];
# #     scanf("%d%d", &n, &s);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     for (int i=1; i<=n; i++) {
# #         int si=0;
# #         int j;
# #         j=1;
# #         while(j<=n && si<=s) {
# #             si=si+ v[j]; j++;
# #             if (v[i] > si) break;
# #         }
# #         j++;
# #         si=si-v[j-1];
# #         if (si==s) {
# #             printf("%d %d", i, j-2);
# #         }
# #     }
# #     printf("0 0");
# #     return 0;
# # }"""
# #     p8c = """int main() {
# #     int n, s, v[101];
# #     scanf("%d%d", &n, &s);
# #     for (int i=1; i<=n; i++) scanf("%d", &v[i]);
# #
# #     for (int i=1; i<=n; i++) {
# #         int si=0;
# #         int j=i;
# #         while(j<=n && si<=s) {
# #             si+=v[j]; j++;
# #         }
# #         si=si-v[j-1];
# #         if (si==s) {
# #             printf("%d %d", i, j-2);
# #             return 0;
# #         }
# #     }
# #     printf("0 0");
# #     return 0;
# # }"""
# #
# #     p9i = """int main() {
# #
# #     int x, n, m, a[101], b[101], v[201], k=0;
# #     scanf("%d%d", &x, &n);
# #     for (int i=1; i<=n; i++) scanf( "%d", &a[i]);
# #     scanf("%d", &m);
# #     for (int i=1; i<=m; i++) scanf("%d", &b[i]);
# #
# #     int i=1, j=1;
# #     while (i<=n && j<=m) {
# #         if (a[i]<b[j]) {
# #             if (a[i]%x==0) {
# #                 k++; v[k]=a[i];
# #             }
# #             i++;
# #         } else if (a[i]>b[j]) {
# #             if (b[j]%x==0) {
# #                 k++; v[k]=b[j];
# #             }
# #         } else {
# #             i--;
# #             j++;
# #         }
# #     }
# #     while (i<=n) {
# #         if (a[i]%x==0) {
# #             k++; v[k]=b[i];
# #         }
# #         i++;
# #     }
# #
# #     while (j<=m) {
# #         if (b[j]%x==0) {
# #             k++; v[k]=a[j];
# #         }
# #     }
# #
# #     for (int i=1; i<=k; i++) printf("%d ", v[i]);
# #     return 0;
# # }"""
# #     p9c = """int main() {
# #     int x, n, m, a[100001], b[100001], v[201], k=0;
# #     scanf("%d%d", &x, &n);
# #     for (int i=1; i<=n; i++) scanf( "%d", &a[i]);
# #     scanf("%d", &m);
# #     for (int i=1; i<=m; i++) scanf( "%d", &b[i]);
# #
# #     int i=1, j=1;
# #     while (i<=n && j<=m) {
# #         if (a[i]<b[j]) {
# #             if (a[i]%x==0) {
# #                 k++; v[k]=a[i];
# #             }
# #             i++;
# #         } else if (a[i]>b[j]) {
# #             if (b[j]%x==0) {
# #                 k++; v[k]=b[j];
# #             }
# #             j++;
# #         } else {
# #             i++;
# #             j++;
# #         }
# #     }
# #     while (i<=n) {
# #         if (a[i]%x==0) {
# #             k++; v[k]=a[i];
# #         }
# #         i++;
# #     }
# #
# #     while (j<=m) {
# #         if (b[j]%x==0) {
# #             k++; v[k]=b[j];
# #         }
# #         j++;
# #     }
# #
# #     for (int i=1; i<=k; i++) printf("%d ", v[i]);
# #     return 0;
# # }"""
# #
# #     parser = c_parser.CParser()
# #
# #     matcher = SequenceMatcher(None, p0i, p0c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 0: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p1i, p1c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 1: {similarity_ratio}")
# #
#     matcher = SequenceMatcher(None, p2i, p2c)
#
#     similarity_ratio = matcher.ratio()
#     print(f"Similarity ratio 22222222: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p3i, p3c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 3: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p4i, p4c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 4: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p5i, p5c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 5: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p6i, p6c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 6: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p7i, p7c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 7: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p8i, p8c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 8: {similarity_ratio}")
# #
# #     matcher = SequenceMatcher(None, p9i, p9c)
# #
# #     similarity_ratio = matcher.ratio()
# #     print(f"Similarity ratio 9: {similarity_ratio}")
#
#     sol="""int main()
# {
#   int n;
#   int m;
#   int i;
#   int j;
#   int a[101][101];
#   int k;
#   int v[10001];
#   int p = 0;
#   scanf("%d", &n);
#   for (i = 1; i <= n; i++)
#   {
#     for (j = 1; j <= n; j++)
#     {
#       scanf("%d", &a[i][j]);
#     }
#
#   }
#
#   for (i = 1; i <= n; i++)
#   {
#     if ((i % 2) == 0)
#     {
#       for (j = i, k = 1; j >= 1; j--, k++)
#       {
#         p++;
#         v[p] = a[k][i];
#       }
#
#     }
#     else
#     {
#       for (j = i, k = 1; j >= 1; j--, k++)
#       {
#         p++;
#         v[p] = a[k][j];
#       }
#
#     }
#   }
#
#   for (j = 1; j <= (n - 1); j++)
#   {
#     if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
#     {
#       for (i = j + 1, k = n; i <= n; i++, k--)
#       {
#         p++;
#         v[p] = a[i][k];
#       }
#
#     }
#     else
#     {
#       if ((((n % 2) == 0) && ((j % 2) == 0)) || (((n % 2) == 1) && ((j % 2) == 1)))
#       {
#         for (i = n, k = j + 1; i >= (j + 1); i--, k++)
#         {
#           p++;
#           v[p] = a[k][i];
#         }
#
#       }
#     }
#   }
#
#   for (int i = 1; i <= p; i++)
#   {
#     printf("%d ", v[i]);
#   }
#
#   return 0;
# }"""
#
#     initial = """int main()
# {
#   int n;
#   int m;
#   int i;
#   int j;
#   int a[101][101];
#   int k;
#   int v[10001];
#   int p = 0;
#   scanf("%d", &n);
#   for (i = 1; i <= n; i++)
#   {
#     for (j = 1; j <= n; j++)
#     {
#       scanf("%d", &a[i][j]);
#     }
#
#   }
#
#   for (i = 1; i <= n; i++)
#   {
#     if ((i % 2) == 0)
#     {
#       for (j = i, k = 1; j >= 1; j--, k++)
#       {
#         p++;
#         v[p] = a[j][k];
#       }
#
#     }
#     else
#     {
#       for (j = i, k = 1; j >= 1; j--, k++)
#       {
#         p++;
#         v[p] = a[k][j];
#       }
#
#     }
#   }
#
#   for (j = 1; j <= (n - 1); j++)
#   {
#     if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
#     {
#       for (i = j + 1, k = n; i <= n; i++, k--)
#       {
#         p++;
#         v[p] = a[i][k];
#       }
#
#     }
#     else
#     {
#       if ((((n % 2) == 0) && ((j % 2) == 0)) || (((n % 2) == 1) && ((j % 2) == 1)))
#       {
#         for (i = n, k = j + 1; i >= (j + 1); i--, k++)
#         {
#           p++;
#           v[p] = a[k][i];
#         }
#
#       }
#     }
#   }
#
#   for (int i = 1; i <= p; i++)
#   {
#     printf("%d ", v[i]);
#   }
#
#   return 0;
# }"""
#
#
#     matcher = SequenceMatcher(None, sol, initial)
#
#     similarity_ratio = matcher.ratio()
#     print(f"Similarity ratio 9: {similarity_ratio}")
#
#
# main()