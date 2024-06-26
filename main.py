import copy
import random
import signal

from path_helper import build_trace_program
from pycparser import c_generator, c_ast, c_parser
from combine_asts import crossover, Chromosome
import subprocess
import os

def create_individual(chromosome):
    statements = chromosome.statements
    statement_ids = chromosome.statement_ids
    insert_pool = chromosome.insert_pool

    statement_id = statement_ids[random.choice(list(statement_ids.keys()))] #statement_ids[random.randint(1, len(statement_ids) - 1)]
    statement = statements[statement_id]

    operation = random.choice([0, 1, 2])
    if operation == 0:
        # insert
        new_statement_id = random.randint(0, len(insert_pool) - 1)
        new_statement = copy.deepcopy(insert_pool[new_statement_id])
        insert_statement_after(chromosome, statement_id, new_statement)
        pass
    elif operation == 1:
        # update
        # alter the statement by either simple alter or replace it with another statement
        # alter statement for now
        alter_statement(statement, chromosome)
    else:
        # delete
        delete_statement_id = statement_ids[random.choice(list(statement_ids.keys()))]
        delete_statement(chromosome, delete_statement_id, statements[delete_statement_id])

    return chromosome


def initialise_population(chromosome, population_size):
    population = [create_individual(copy.deepcopy(chromosome)) for _ in range(population_size)]
    return population


def minimize(solution):
    return solution


def compile_c_program(source_file, output_file):
    subprocess.run(["gcc", source_file, "-o", output_file], check=True, stderr=subprocess.PIPE)


def save_traced_program(program, submission_id):
    with open("./traced_programs/" + str(submission_id) + ".c", "w") as file:
        file.write("#include <stdio.h>\n")
        file.write("FILE* file_pointer;\n")
        file.write(program)


def are_files_identical(file_path1, file_path2):
    try:
        # Open and read the content of both files
        with open(file_path1, 'rb') as file1, open(file_path2, 'rb') as file2:
            content1 = file1.read()
            content1 = content1.rstrip()
            content2 = file2.read()
            content2 = content2.rstrip()

            if content1 == content2:
                return True
            else:
                return False
    except FileNotFoundError:
        print("One or both files not found.")
        return False


def execute_tests(problem_id, submission_id):
    test_result_file_path = "./test_result/" + str(submission_id) + ".out"
    test_input_folder = "./tests/" + str(problem_id) + "/input"
    test_output_folder = "./tests/" + str(problem_id) + "/output"

    for input_filename, output_filename in zip(os.listdir(test_input_folder), os.listdir(test_output_folder)):
        input_filename_path = os.path.join(test_input_folder, input_filename)
        output_filename_path = os.path.join(test_output_folder, output_filename)
        test_result_file_path = "./test_result/" + str(submission_id) + ".out"
        try:
            with open(test_result_file_path, "w") as output_file:
                process = subprocess.Popen(["./traced_programs/" + str(submission_id) + "_compiled"],
                                           stdin=open(input_filename_path), stdout=output_file)
            process.wait()
            identical_files = are_files_identical(test_result_file_path, output_filename_path)
            insert = ""
            if identical_files:
                insert = "s\n"
            else:
                insert = "f\n"
            with open("./traced_tests/" + str(submission_id) + ".out", "a") as f:
                f.write(insert)

            # insereaza in 0.out din traced tests s/f\n
        except subprocess.CalledProcessError as e:
            print("Error:", e)


def calculate_suspiciousness(submission_id, statement_count):
    total_failed = 0
    total_successful = 0
    passed_stmts = [0 for _ in range(statement_count)]
    failed_stmts = [0 for _ in range(statement_count)]

    with open("./traced_tests/" + str(submission_id) + ".out", "r") as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip()
            statement_ids = line.split(" ")
            test_state = statement_ids[-1]
            passed = False
            if test_state == "s":
                passed = True
                total_successful += 1
            else:
                total_failed += 1
            statement_ids.pop()

            current_passed = {}
            current_failed = {}
            for statement_id in statement_ids:
                statement_id = int(statement_id)
                if passed and statement_id not in current_passed:
                    current_passed[statement_id] = 1
                if not passed and statement_id not in current_failed:
                    current_failed[statement_id] = 1

            for key, value in current_passed.items():
                passed_stmts[key] += 1
            for key, value in current_failed.items():
                failed_stmts[key] += 1

    suspiciousness = {}
    for i in range(1, statement_count):
        sus = 0.01
        if failed_stmts[i] == 0 and passed_stmts[i] == 0:
            sus = 0
        elif total_successful==0:
            sus = 1
        elif total_failed == 0:
            sus = 0
        else:
            sus = (failed_stmts[i] / total_failed) / (
                    passed_stmts[i] / total_successful + failed_stmts[i] / total_failed)
        suspiciousness[i] = sus

    return suspiciousness


def extract_statements_and_weights(submission_id, program_path, problem_id):
    # curatam fisierul unde se appenduiesc traceurile
    with open("./traced_tests/" + str(submission_id) + ".out", "w"):
        pass
    result = build_trace_program(program_path, submission_id, "./traced_tests/")
    traced_program = result['traced_program']
    statement_count = result['statement_count']
    statements = result['statements']
    initial_ast = result['initial_ast']
    parent = result['parent']
    pos_in_parent = result['pos_in_parent']

    generator = c_generator.CGenerator()
    traced_program_as_string = generator.visit(traced_program)
    save_traced_program(traced_program_as_string, submission_id)

    # inainte sa compilez programul ar trebui sa sterg vechea varianta compilata daca ea exista
    compile_c_program("./traced_programs/" + str(submission_id) + ".c",
                      "./traced_programs/" + str(submission_id) + "_compiled")
    execute_tests(problem_id, submission_id)
    suspiciousness = calculate_suspiciousness(submission_id, statement_count)

    return {'statements': statements, 'suspiciousness': suspiciousness, 'statement_count': statement_count,
            'initial_ast': initial_ast, 'parent': parent, 'pos_in_parent': pos_in_parent}


def change_for_init(init, chromosome):
    id = random.randint(0, len(chromosome.rvalues_pool) - 1)
    expr = copy.deepcopy(chromosome.rvalues_pool[id])
    init.decls[0].init = expr


def change_for_cond(cond, chromosome):
    cond.op = copy.deepcopy(chromosome.relational_op_pool[random.randint(0, len(chromosome.relational_op_pool) - 1)])
    cond.right = copy.deepcopy(chromosome.rvalues_pool[random.randint(0, len(chromosome.rvalues_pool) - 1)])


def alter_statement(statement, chromosome):
    if isinstance(statement, c_ast.For):
        # alteram tot for-ul
        change_for_init(statement.init, chromosome)
        change_for_cond(statement.cond, chromosome)
        statement.next = copy.deepcopy(
            chromosome.unary_expr_pool[random.randint(0, len(chromosome.unary_expr_pool) - 1)])
    elif isinstance(statement, c_ast.Assignment):
        operation = random.choice([0, 1, 2])
        if operation == 1:
            # alterez numai lvalue
            statement.lvalue = copy.deepcopy(
                chromosome.lvalues_pool[random.randint(0, len(chromosome.lvalues_pool) - 1)])
        elif operation == 2:
            # alterez numai rvalue
            statement.rvalue = copy.deepcopy(
                chromosome.rvalues_pool[random.randint(0, len(chromosome.rvalues_pool) - 1)])
        else:
            statement.rvalue = copy.deepcopy(
                chromosome.rvalues_pool[random.randint(0, len(chromosome.rvalues_pool) - 1)])
            statement.lvalue = copy.deepcopy(
                chromosome.lvalues_pool[random.randint(0, len(chromosome.lvalues_pool) - 1)])
    elif isinstance(statement, c_ast.UnaryOp):
        new_op = chromosome.unary_expr_pool[random.randint(0, len(chromosome.unary_expr_pool) - 1)]
        statement.op = new_op.op
        statement.expr.name = new_op.expr.name


def update_parents(chromosome, parent, inserted_position, new_statement_id):
    for key, value in chromosome.parent.items():
        if value == parent and chromosome.pos_in_parent[key] >= inserted_position and key != new_statement_id:
            chromosome.pos_in_parent[key] += 1


def insert_statement_after(chromosome, statement_id, new_statement):
    parent = chromosome.parent
    pos_in_parent = chromosome.pos_in_parent
    statements = chromosome.statements
    weights = chromosome.weights

    insertion_pos = pos_in_parent[statement_id] + 1
    parent[statement_id].insert(insertion_pos, new_statement)

    statements[chromosome.statement_count] = new_statement
    parent[chromosome.statement_count] = parent[statement_id]
    pos_in_parent[chromosome.statement_count] = pos_in_parent[statement_id] + 1

    weights[chromosome.statement_count] = weights[statement_id]
    chromosome.statement_count += 1

    update_parents(chromosome, parent[statement_id], pos_in_parent[statement_id] + 1, chromosome.statement_count - 1)


def update_parents_after_delete(chromosome, statement_id):
    for key, value in chromosome.parent.items():
        if value == chromosome.parent[statement_id] and chromosome.pos_in_parent[key] > chromosome.pos_in_parent[
            statement_id]:
            chromosome.pos_in_parent[key] -= 1

    chromosome.parent.pop(statement_id)
    chromosome.pos_in_parent.pop(statement_id)
    chromosome.statements.pop(statement_id)
    chromosome.statement_ids.pop(statement_id)



def delete_statement(chromosome, statement_id, statement):
    update_parents_after_delete(chromosome, statement_id)



def mutate(chromosome):
    w_mut = 0.06
    statement_count = chromosome.statement_count
    initial_statement_count = chromosome.initial_statement_count
    statements = chromosome.statements
    weights = chromosome.weights
    statement_ids = chromosome.statement_ids
    insert_pool = chromosome.insert_pool

    keys = copy.deepcopy(list(statement_ids.keys()))
    for statement_id in keys:
        if statement_id in statements:
            statement = statements[statement_id]
            try:
                prob = weights[statement_id]
            except KeyError:
                print(weights)
            if random.randint(0, 1) <= prob and random.randint(0, 1) <= w_mut:
                operation = random.choice([0, 1, 2])
                if operation == 0:
                    # insert
                    new_statement_id = random.randint(0, len(insert_pool) - 1)
                    new_statement = copy.deepcopy(insert_pool[new_statement_id])
                    insert_statement_after(chromosome, statement_id, new_statement)
                    pass
                elif operation == 1:
                    # update
                    # alter the statement by either simple alter or replace it with another statement
                    # alter statement for now
                    alter_statement(statement, chromosome)
                else:
                    # delete
                    delete_statement_id = statement_ids[random.choice(list(statement_ids.keys()))]
                    delete_statement(chromosome, delete_statement_id, statements[delete_statement_id])
                    #i -= 1
            #i += 1

    return chromosome


def save_C_code_in_file(ast):
    generator = c_generator.CGenerator()
    with open("./chromosomes/current_chromosome.c", "w") as file:
        file.write("#include <stdio.h>\n")
        file.write(generator.visit(ast))


def execute_fitness_tests(problem_id):
    fitness = 0
    test_result_file_path = "./chromosomes/result.out"
    test_input_folder = "./tests/" + str(problem_id) + "/input"
    test_output_folder = "./tests/" + str(problem_id) + "/output"

    for input_filename, output_filename in zip(os.listdir(test_input_folder), os.listdir(test_output_folder)):
        input_filename_path = os.path.join(test_input_folder, input_filename)
        output_filename_path = os.path.join(test_output_folder, output_filename)
        terminated = False
        with open(test_result_file_path, "w") as output_file:
            try:
                process = subprocess.Popen(["./chromosomes/compiled"], stdin=open(input_filename_path),
                                           stdout=open(test_result_file_path, "w"), stderr=subprocess.DEVNULL,
                                           )

                # Wait for the process to complete or timeout
                process.communicate(timeout=1)
            except subprocess.TimeoutExpired:
                print("Process timed out after", 1, "seconds. Terminating...")
                # Terminate the subprocess if it exceeds the timeout
                process.kill()
                terminated = True
        process.wait()
        if not terminated:
            identical_files = are_files_identical(test_result_file_path, output_filename_path)
            if identical_files:
                fitness = fitness + 1
    return fitness


def calculate_fitness(ast, problem_id):
    save_C_code_in_file(ast)
    compile_c_program("./chromosomes/current_chromosome.c", "./chromosomes/compiled")
    fitness = execute_fitness_tests(problem_id)
    return fitness


def sample(population, population_size):
    def custom_sort(chromosome):
        return chromosome.fitness  # Sort by the second element of each tuple

    # Sort the data using the custom comparison function
    sorted_data = sorted(population, key=custom_sort, reverse=True)

    return sorted_data[:population_size]


def ag(submission_id, problem_id, program_path, population_size):
    extracted = extract_statements_and_weights(submission_id, program_path, problem_id)
    statements = extracted['statements']
    weights = extracted['suspiciousness']
    statement_count = extracted['statement_count']
    initial_ast = extracted['initial_ast']
    parent = extracted['parent']
    pos_in_parent = extracted['pos_in_parent']

    chromosome = Chromosome(statements, weights, parent, pos_in_parent, statement_count, initial_ast)

    population = initialise_population(chromosome, population_size)

    for i in range(len(population)):
        try:
            population[i].fitness = calculate_fitness(population[i].ast, problem_id)
        except subprocess.CalledProcessError as e:
            population[i].fitness = 0

    solution_found = False
    solution = None

    max_fitness = 5

    while not solution_found:
        viable = [p for p in population if p.fitness > 0]
        population = []
        new_population = []
        # parintii se aleg din prima jumatate a populatie (cei cu fitness mai bun)
        parents = sample(viable, population_size // 2)
        for i in range(0, len(parents)-1, 2):
            parent1 = parents[i]
            parent2 = parents[i+1]
            children = crossover(parent1.ast, parent2.ast, parent1.weights, parent2.weights, parent1.statements, parent2.statements)
            child1 = children['child1']
            child2 = children['child2']

            new_population.append(parent1)
            new_population.append(parent2)
            new_population.append(child1)
            new_population.append(child2)

        for i in range(len(new_population)):
            if new_population[i].fitness is None:
                try:
                    new_population[i].fitness = calculate_fitness(new_population[i].ast, problem_id)
                except subprocess.CalledProcessError as e:
                    new_population[i].fitness = 0
        for p in new_population:
            if p.fitness == max_fitness:
                solution_found = True
                solution = p
                break
            population.append(mutate(p))
    return minimize(solution)

#     text="""int main()
# {
#   int n;
#   int v[1001];
#   int k;
#   for (int i = 1; i <= n; i++)
#   {
#     scanf("%d", &v[i]);
#   }
#
#   for (int i = n - 1; i >= k; i--)
#   {
#     v[i] = v[i + 1];
#   }
#
#   n--;
#   for (int i = 1; i <= n; i++)
#   {
#     printf("%d ", v[i]);
#   }
#
#   return 0;
# }
# """
#


if __name__ == "__main__":
    ag(0, 1, "problems/0.c", 10)

# print("After:")
# ast.show(offset=2)
