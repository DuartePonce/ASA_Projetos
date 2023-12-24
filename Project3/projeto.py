import pulp

def main():
    lista_brinquedos = []
    lista_pacotes = []
    input_inicial= input()
    valores = input_inicial.split()
    num_brinquedos, num_pacotes, max_brinquedos_dia = map(int, valores)
    for i in range(num_brinquedos):
        info_brinquedos = input()
        valores_brinquedos = info_brinquedos.split()
        lucro, capacidade = map(int,valores_brinquedos)
        lista_brinquedos.append([i+1,lucro,capacidade])
        print(lista_brinquedos)
        i += 1
    for j in range(num_pacotes):
        info_pacotes = input()
        valores_pacotes = info_pacotes.split()
        brinquedo1, brinquedo2, brinquedo3, lucro_pacote = map(int,valores_pacotes)
        lista_pacotes.append([brinquedo1, brinquedo2, brinquedo3, lucro_pacote])
        print(lista_pacotes)
        j += 1
    return

main()