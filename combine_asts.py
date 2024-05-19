import copy
import random

from pycparser import c_ast, c_parser, c_generator

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
                self.add_elem_in_pool(copy.deepcopy(value.init.decls[0].init), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.right), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.left), self.lvalues_pool, l_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.cond.left), self.rvalues_pool, r_values_show)
            elif isinstance(value, c_ast.Assignment):
                self.add_elem_in_pool(copy.deepcopy(value.lvalue), self.lvalues_pool, l_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.lvalue), self.rvalues_pool, r_values_show)
                self.add_elem_in_pool(copy.deepcopy(value.rvalue), self.rvalues_pool, r_values_show)
            elif isinstance(value, c_ast.UnaryOp):
                self.add_elem_in_pool(copy.deepcopy(value), self.unary_expr_pool, unary_op_show)

    def __init__(self, statements, weights, parent, pos_in_parent, statement_count, ast):
        self.statements = statements
        self.weights = weights
        self.parent = parent
        self.pos_in_parent = pos_in_parent
        self.statement_count = statement_count
        self.initial_statement_count = statement_count
        self.ast = ast
        self.statement_ids = {}
        for key, _ in statements.items():
            self.statement_ids[key] = key
        self.insert_pool = [copy.deepcopy(value) for _, value in statements.items()]
        self.unary_expr_pool = []
        self.operators_pool = []
        self.rvalues_pool = []
        self.lvalues_pool = []
        self.exprs_show = []
        self.relational_op_pool = ['<', '>', '<=', '>=']
        self.initialise_pools(statements)
        self.fitness = None


def traverse_statement1(stmt, parent_weights):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights


    for node in stmt:
        if isinstance(node, c_ast.Compound):
            size = len(node.block_items)
            i=0
            statement_count += 1

            while i<size:
                if not (isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If)):
                    # add statement in dictionary based on id (statement_count)
                    statements[statement_count] = node.block_items[i]
                    parents[statement_count] = node.block_items
                    pos_in_parent[statement_count] = i
                    # weights[statement_count] = parent_weights[statement_count]

                    statement_count+=1
                elif isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If):
                    if isinstance(node.block_items[i], c_ast.For):
                        statements[statement_count] = node.block_items[i].init
                                                    # [copy_node.block_items[i].init,
                                                    #    copy_node.block_items[i].cond,
                                                    #    copy_node.block_items[i].next]
                        parents[statement_count] = node.block_items
                        pos_in_parent[statement_count] = i
                        # weights[statement_count ] = parent_weights[statement_count]
                    traverse_statement1(node.block_items[i], parent_weights)
                i+=1


def traverse_statement2(stmt, parent_weights):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights
    global statement_count_parent2


    for node in stmt:
        if isinstance(node, c_ast.Compound):
            size = len(node.block_items)
            i=0
            statement_count += 1

            while i<size:
                if not (isinstance(node.block_items[i], c_ast.For) or isinstance(node.block_items[i], c_ast.While) or isinstance(node.block_items[i], c_ast.If)):
                    # add statement in dictionary based on id (statement_count)
                    statements[statement_count] = node.block_items[i]
                    parents[statement_count] = node.block_items
                    pos_in_parent[statement_count] = i

                    # print(str(statement_count_parent2)+" "+str(len(parent_weights)))
                    # weights[statement_count] = parent_weights[statement_count_parent2]
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

                        # weights[statement_count ] = parent_weights[statement_count_parent2]
                        # statement_count_parent2 += 1
                    traverse_statement2(node.block_items[i], parent_weights)
                i+=1


def traverse_ast(parent1, parent2, cut, weights1, weights2, statements2):
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
                                                                               c_ast.If)):

            # add statement in dictionary based on id (statement_count)
            statements[statement_count] = parent1.ext[0].body.block_items[i]
            parents[statement_count] = parent1.ext[0].body.block_items
            pos_in_parent[statement_count] = i

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
                # weights[statement_count] = weights1[statement_count]
            traverse_statement1(parent1.ext[0].body.block_items[i], weights1)

    parent1.ext[0].body.block_items = parent1.ext[0].body.block_items[:cut]
    weight1_id_start = 0
    weight1_id_stop = statement_count-1

    st_count=1
    for key in weights1.keys():
        if key>=weight1_id_start and key<=weight1_id_stop:
            weights[st_count] = weights1[key]
            st_count += 1

    weight2_id_start = 0

    for i in range(cut, len(parent2.ext[0].body.block_items)):
        if not (isinstance(parent2.ext[0].body.block_items[i], c_ast.For) or isinstance(
                parent2.ext[0].body.block_items[i], c_ast.While) or isinstance(parent2.ext[0].body.block_items[i],
                                                                               c_ast.If)):

            # add statement in dictionary based on id (statement_count)
            statements[statement_count] = parent2.ext[0].body.block_items[i]
            parents[statement_count] = parent2.ext[0].body.block_items
            pos_in_parent[statement_count] = i


            # weights[statement_count] = weights2[statement_count_parent2]
            # statement_count_parent2 += 1

            statement_count += 1
        elif isinstance(parent2.ext[0].body.block_items[i], c_ast.For) or isinstance(parent2.ext[0].body.block_items[i],
                                                                                     c_ast.While) or isinstance(
                parent2.ext[0].body.block_items[i], c_ast.If):
            if isinstance(parent2.ext[0].body.block_items[i], c_ast.For):
                statements[statement_count] = parent2.ext[0].body.block_items[
                    i]  # [node2.body.block_items[i].init, node2.body.block_items[i].cond, node2.body.block_items[i].next]
                parents[statement_count] = parent2.ext[0].body.block_items
                pos_in_parent[statement_count] = i


                # weights[statement_count] = weights2[statement_count_parent2]
                # statement_count_parent2 += 1
            traverse_statement2(parent2.ext[0].body.block_items[i], weights2)

    parent1.ext[0].body.block_items.extend(parent2.ext[0].body.block_items[cut:])

    if cut<= len(parent2.ext[0].body.block_items)-1:
        for key, value in statements2.items():
            if str(value) == str(parent2.ext[0].body.block_items[cut]):
                weight2_id_start = key
                break

        for key in weights2.keys():
            if key>=weight2_id_start:
                weights[st_count] = weights2[key]
                st_count += 1

    return {'child1': ""}


def crossover(parent1, parent2, weights1, weights2, statements1, statements2):
    global pos
    global statement_count
    global statements
    global parents
    global pos_in_parent
    global weights
    global statement_count_parent2

    pos=0
    statement_count = 1
    statements = {}
    parents = {}
    pos_in_parent = {}
    weights = {}
    statement_count_parent2 = 1

    parent1_copy = copy.deepcopy(parent1)
    parent2_copy = copy.deepcopy(parent2)



    parent1_body_size = len(parent1.ext[0].body.block_items)
    parent2_body_size = len(parent2.ext[0].body.block_items)

    cut1 = random.randint(0, parent1_body_size-1)
    cut2 = random.randint(0, parent2_body_size-1)
    traverse_ast(parent1, parent2, cut1, weights1, weights2, statements2)
    child1 = Chromosome(statements, weights, parents, pos_in_parent, statement_count, parent1)

    pos = 0
    statement_count = 1
    statements = {}
    parents = {}
    pos_in_parent = {}
    weights = {}
    statement_count_parent2 = 1

    traverse_ast(parent2_copy, parent1_copy, cut2, weights2, weights1, statements1)
    child2 = Chromosome(statements, weights, parents, pos_in_parent, statement_count, parent2_copy)

    return {'child1':child1, 'child2':child2}


def main():
    p1 = """int main() {
    int n, v[1001], k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = n-1 ; i >= k; i--) {
        v[i] = v[i + 1];
    }
    m++;
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    a--;
    l++;
    return 0;
    }"""

    p2 = """int main() {
        int m, v[1001], k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }
        for (int i = n-1 ; i >= k; i--) {
            v[i] = v[i + 1];
        }
        n--;
        i++;
        for (int i = 1; i <= n; i++) {
            printf("%d ", v[i]);
        }
        c--;
        return 0;
    }"""

    parser = c_parser.CParser()
    ast1 = parser.parse(p1)
    ast2 = parser.parse(p2)
    cut1=6
    cut2=7
    #res1 = crossover(copy.deepcopy(ast1), copy.deepcopy(ast2), cut1)

    # children = crossover(copy.deepcopy(ast1), copy.deepcopy(ast2), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16], [17, 18, 19,20,21,22,23,24,25, 26, 27, 29, 29, 30,31, 32, 33, 34])
    # child1 = children['child1']
    # child2 = children['child2']

    # child2.statements[12].expr.name='k'
    # print(child1.weights)
    # print(child2.weights)
    #
    generator = c_generator.CGenerator()
    # for key, value in child1.statements.items():
    #     print(str(key))
    #     print(value.show())


main()