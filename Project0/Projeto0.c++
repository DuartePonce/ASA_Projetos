#include <iostream>
#include <list>
#include <vector>
using namespace std;


/*
hstograma 1 tem o numero de vertices do grafo da maneira
numero de relacoes      n de vertices output
0                           2
1                           0
2                           1    
*/

/*
histograma 2 tem o n de pessoas que gostam de um vertice
n de amigos     n de vertices 
0                       1
1                       2
2                       0

input n de vertices depois n de realcoes
    1   2   3
1   
2
3
*/

//Funcao que le o input de relacoes
void readFunction(int numberR, list<int> *listaRelacoes,  list<int> *listaRelacoesBack) {
    int vertice, verticeRelacao;
    for (int i = 0; i < numberR; i++) {
        cin >> vertice >> verticeRelacao;

        listaRelacoes[vertice].push_front(verticeRelacao);
        listaRelacoesBack[verticeRelacao].push_front(vertice);
    }
}

void printFunction1(int numberV, list<int> *listaRelacoes) {
    cout << "Histograma 1\n";
    for (int i = 0; i < numberV; i++) {
        int res = 0;
        for (int j = 1; j <= numberV; j++) {
            if (listaRelacoes[j].size() == (long unsigned)i) {
                res++;
            }
        }
        cout << res << "\n";
    }
}

void printFunction2(int numberV, list<int> *listaRelacoesBack) {
    cout << "Histograma 2\n";
    for (int i = 0; i < numberV; i++) {
        int res = 0;
        for (int j = 1; j <= numberV; j++) {
            if (listaRelacoesBack[j].size() == (long unsigned)i) {
                res++;
            }
        }
        cout << res << "\n";
    }
}

void printMatrix(int numberV, list<int> *listaRelacoes) {
    cout << "Matrix: \n";
    for (int i = 1; i <= numberV; i++) {

        for (int j = 1; j <= numberV; j++) {

            int res = 0;

            for (std::list<int>::iterator it = listaRelacoes[i].begin(); it != listaRelacoes[i].end(); ++it) {    
                
                
                for (std::list<int>::iterator it2 = listaRelacoes[j].begin(); it2 != listaRelacoes[j].end(); ++it2) {
                    if (*it == *it2) {
                        res++;
                    }
                }

            }
            cout << res << "  ";
        }  
        cout << "\n";
    }

}

int main() {
    int numberV, numberR;
    char a;

    cin >> numberV; 
    cin >> a;
    cin >> numberR;

    std::list<int> *listaRelacoes = new std::list<int>[numberV + 1];
    std::list<int> *listaRelacoesBack = new std::list<int>[numberV + 1];

    readFunction(numberR, listaRelacoes, listaRelacoesBack);
    printFunction1(numberV, listaRelacoes);
    printFunction2(numberV, listaRelacoesBack);
    printMatrix(numberV, listaRelacoes);

    return 0;
}