import pulp

problem = pulp.LpProblem("problem", pulp.LpMaximize)

lista_brinquedos = []
lista_quantidades = []

input_inicial = input()
valores = input_inicial.split()
num_brinquedos, num_pacotes, max_brinquedos_dia = map(int, valores)

for i in range(num_brinquedos):
    info_brinquedos = input()
    valores_brinquedos = info_brinquedos.split()
    lucro, capacidade = map(int, valores_brinquedos)
    quantity_variable = pulp.LpVariable(f"q{i}", lowBound=0, upBound=capacidade, cat="Integer")
    lista_quantidades.append(quantity_variable)
    lista_brinquedos.append(quantity_variable * lucro)


problem += pulp.lpSum(lista_brinquedos)

problem += pulp.lpSum(lista_quantidades) <= max_brinquedos_dia

status = problem.solve(pulp.GLPK(msg=0))
print("Status:", pulp.LpStatus[status])
print("Optimal Objective Value:", pulp.value(problem.objective))

"(POR FAZER!!!!!!)usar este for para os pacotes"

'''
for j in range(num_pacotes):
    info_pacotes = input()
    valores_pacotes = info_pacotes.split()
    brinquedo1, brinquedo2, brinquedo3, lucro_pacote = map(int,valores_pacotes)
    lista_pacotes.append([brinquedo1, brinquedo2, brinquedo3, lucro_pacote])
'''