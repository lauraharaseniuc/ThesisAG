import copy

from pycparser import parse_file, c_generator, c_parser, c_ast
statement_count= 1
statements = {}
parent = {}
pos_in_parent = {}


def printf_node(statement_count):
    parser = c_parser.CParser()
    child_ast = parser.parse('int main() {fprintf(file_pointer, "%d ", '+str(statement_count)+');}')
    child = child_ast.ext[0].body.block_items[0]
    return child


def traverse_statement(stmt, copy_stmt):
    global statement_count
    global statements
    global parent
    global pos_in_parent

    for node, copy_node in zip(stmt, copy_stmt):
        if isinstance(node, c_ast.Compound):
            size = len(node.block_items)
            i=0
            child_no=0

            #pt intrarea in if for while sa vad daca se intra prima data
            node.block_items.insert(child_no, printf_node(statement_count))
            statement_count += 1

            child_no+=1

            while i<size:
                if not (isinstance(node.block_items[child_no], c_ast.For) or isinstance(node.block_items[child_no], c_ast.While) or isinstance(node.block_items[child_no], c_ast.If)):
                    child_no+=1
                    node.block_items.insert(child_no, printf_node(statement_count))

                    # add statement in dictionary based on id (statement_count)
                    statements[statement_count] = copy_node.block_items[i]
                    parent[statement_count] = copy_node.block_items
                    pos_in_parent[statement_count] = i

                    statement_count+=1
                    child_no +=1
                elif isinstance(node.block_items[child_no], c_ast.For) or isinstance(node.block_items[child_no], c_ast.While) or isinstance(node.block_items[child_no], c_ast.If):
                    if isinstance(node.block_items[child_no], c_ast.For):
                        statements[statement_count] = copy_node.block_items[i].init
                                                    # [copy_node.block_items[i].init,
                                                    #    copy_node.block_items[i].cond,
                                                    #    copy_node.block_items[i].next]
                        parent[statement_count] = copy_node.block_items
                        pos_in_parent[statement_count] = i
                    traverse_statement(node.block_items[child_no], copy_node.block_items[i])
                    child_no += 1
                i+=1


def build_trace_program(file, submission_id, traced_tests_path):
    global statement_count
    global statements
    global parent
    global pos_in_parent

    initial_ast = parse_file(file, use_cpp=True)
    copy_ast = copy.deepcopy(initial_ast)
    parser = c_parser.CParser()
    child_ast = parser.parse('int main() {file_pointer = fopen("'+str(traced_tests_path)+str(submission_id)+'.out", "a");}')
    trace_result_fp = child_ast.ext[0].body.block_items[0]

    for node, copy_node in zip(initial_ast.ext, copy_ast.ext):
        size = len(node.body.block_items)
        i=0
        child_no = 0
        while i<size:
            if not (isinstance(node.body.block_items[child_no], c_ast.For) or isinstance(node.body.block_items[child_no], c_ast.While) or isinstance(node.body.block_items[child_no], c_ast.If)):
                child_no+=1

                node.body.block_items.insert(child_no,printf_node(statement_count))

                #add statement in dictionary based on id (statement_count)
                statements[statement_count] = copy_node.body.block_items[i]
                parent[statement_count] = copy_node.body.block_items
                pos_in_parent[statement_count] = i

                statement_count += 1
                child_no+=1
            elif isinstance(node.body.block_items[child_no], c_ast.For) or isinstance(node.body.block_items[child_no], c_ast.While) or isinstance(node.body.block_items[child_no], c_ast.If):
                if isinstance(node.body.block_items[child_no], c_ast.For):
                    statements[statement_count] = copy_node.body.block_items[i] #[copy_node.body.block_items[i].init, copy_node.body.block_items[i].cond, copy_node.body.block_items[i].next]
                    parent[statement_count] = copy_node.body.block_items
                    pos_in_parent[statement_count] = i
                traverse_statement(node.body.block_items[child_no], copy_node.body.block_items[i])
                child_no += 1
            else:
                child_no+=1
            i+=1

    # for key, value in statements.items():
    #     print(key)
    #     if isinstance(value, list):
    #         print(value)
    #     else:
    #         print(value.show())
    #     print()
    initial_ast.ext[0].body.block_items.insert(0, trace_result_fp)

    return {'traced_program': initial_ast, 'statement_count': statement_count, 'statements': statements, 'initial_ast':copy_ast, 'parent':parent, 'pos_in_parent':pos_in_parent}

