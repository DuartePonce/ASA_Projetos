from pulp import *

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
    quantity_variable = LpVariable(f"q_{i}", lowBound=0, upBound=capacidade, cat="Integer")
    brinquedos[f'brinquedo_{i}'] = {'lucro': lucro, 'capacidade': capacidade, 'quantidade': quantity_variable} # Criacao do dicionario
    problem += quantity_variable <= capacidade

for j in range(1, num_pacotes + 1):
    info_pacotes = input()
    valores_pacotes = info_pacotes.split()
    package_variable = LpVariable(f"p_{j}", lowBound=0, cat="Integer")
    brinquedo1, brinquedo2, brinquedo3, lucro_pacote = map(int, valores_pacotes)
    pacotes[f'pacote_{j}'] = {'lucro': lucro_pacote, 'quantidade' : package_variable, 
                            'brinquedo1': brinquedos[f'brinquedo_{brinquedo1}']['quantidade'], 
                            'brinquedo2': brinquedos[f'brinquedo_{brinquedo2}']['quantidade'], 
                            'brinquedo3': brinquedos[f'brinquedo_{brinquedo3}']['quantidade']
                            } # Criacao do dicionario


# Problem Formulation
problem += 3 * package_variable == brinquedos[f'brinquedo_{brinquedo1}']['quantidade'] + \
                                   brinquedos[f'brinquedo_{brinquedo2}']['quantidade'] + \
                                   brinquedos[f'brinquedo_{brinquedo3}']['quantidade']

problem += lpSum(brinquedos[toy]['quantidade'] for toy in brinquedos) <= max_brinquedos_dia

problem += lpSum(brinquedos[toy]['lucro'] * brinquedos[toy]['quantidade'] for toy in brinquedos) + lpSum(pacotes[package]['lucro'] * pacotes[package]['quantidade'] for package in pacotes)



# Solve PULP_CBC_CMD
# status = problem.solve(GLPK(msg=0))
status = problem.solve(PULP_CBC_CMD(msg=False))
print("Status:", LpStatus[status])
print("Optimal Objective Value:", value(problem.objective))
print("take:", *[brinquedos[toy]['quantidade'].varValue for toy in brinquedos])
