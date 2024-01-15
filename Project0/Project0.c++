#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Function that reads the input of realtions
void readFunction(int numberR, list<int> *listaRelacoes,  list<int> *listaRelacoesBack) {
    int vertice, verticeRelacao;
    for (int i = 0; i < numberR; i++) {
        cin >> vertice >> verticeRelacao;

        listaRelacoes[vertice].push_front(verticeRelacao);
        listaRelacoesBack[verticeRelacao].push_front(vertice);
    }
}

// Function that prints Histograma1
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

// Function that prints Histograma2
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

// Function that prints the matrix
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