from pulp import *
import time

class Chronometer:
    def __init__(self):
        self.start_time = None
        self.is_running = False

    def start(self):
        if not self.is_running:
            self.start_time = time.time()
            self.is_running = True
            print("Chronometer started.")

    def stop(self):
        if self.is_running:
            elapsed_time = time.time() - self.start_time
            self.is_running = False
            print(f"Chronometer stopped. Elapsed time: {elapsed_time:.2f} seconds")

    def reset(self):
        self.start_time = None
        self.is_running = False
        print("Chronometer reset.")

# Create a Chronometer instance
chronometer = Chronometer()

# Start the chronometer
chronometer.start()

problem = LpProblem("problem", LpMaximize)

brinquedos = {}
pacotes = {}

# Input
input_inicial = input()
valores = input_inicial.split()
num_brinquedos, num_pacotes, max_brinquedos_dia = map(int, valores)

for i in range(1, num_brinquedos + 1):
    info_brinquedos = input()
    valores_brinquedos = info_brinquedos.split()
    lucro, capacidade = map(int, valores_brinquedos)
    quantity_variable = LpVariable(f"q_{i}", lowBound = 0, upBound = capacidade, cat = "Integer")
    brinquedos[f'brinquedo_{i}'] = {'lucro': lucro, 'capacidade': capacidade, 'quantidade': quantity_variable, 'pacote': 0} # Criacao do dicionario

for j in range(1, num_pacotes + 1):
    info_pacotes = input()
    valores_pacotes = info_pacotes.split()
    package_variable = LpVariable(f"p_{j}", lowBound = 0, cat = "Integer")
    brinquedo1, brinquedo2, brinquedo3, lucro_pacote = map(int, valores_pacotes) 
    pacotes[f'pacote_{j}'] = {'lucro': lucro_pacote, 'quantidade' : package_variable, 
                            'brinquedo1': brinquedos[f'brinquedo_{brinquedo1}']['quantidade'], 
                            'brinquedo2': brinquedos[f'brinquedo_{brinquedo2}']['quantidade'], 
                            'brinquedo3': brinquedos[f'brinquedo_{brinquedo3}']['quantidade']
                            } # Criacao do dicionario
    brinquedos[f'brinquedo_{brinquedo1}']['pacote'] += package_variable
    brinquedos[f'brinquedo_{brinquedo2}']['pacote'] += package_variable
    brinquedos[f'brinquedo_{brinquedo3}']['pacote'] += package_variable


# Problem Formulation

for i in range(1, num_brinquedos + 1):
    problem += brinquedos[f'brinquedo_{i}']['quantidade'] + brinquedos[f'brinquedo_{i}']['pacote'] <= brinquedos[f'brinquedo_{i}']['capacidade']

problem += lpSum((brinquedos[toy]['quantidade'] for toy in brinquedos)) + lpSum((3 * pacotes[package]['quantidade'] for package in pacotes)) <= max_brinquedos_dia



problem += lpSum(brinquedos[toy]['lucro'] * brinquedos[toy]['quantidade'] for toy in brinquedos) + lpSum(pacotes[package]['lucro'] * pacotes[package]['quantidade'] for package in pacotes)


# Solve PULP_CBC_CMD
status = problem.solve(GLPK(msg=0))

chronometer.stop()

# Print the solution time
print("Solution time:")
#status = problem.solve(PULP_CBC_CMD(msg=False))
print(value(problem.objective))
#print("Status:", LpStatus[status])
#print("Optimal Objective Value:", value(problem.objective))
#print("take:", *[brinquedos[toy]['quantidade'].varValue for toy in brinquedos])
#print("take:", *[pacotes[toy]['quantidade'].varValue for toy in pacotes])