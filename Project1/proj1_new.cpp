#include <iostream>
using namespace std;

// Função para calcular o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função que implementa o algoritmo para maximizar o valor da mochila
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    // Preenchendo a tabela dp[][] de maneira bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Retornando o valor máximo obtido para o peso W
}

int main() {
    int W = 50; // Peso máximo da mochila
    int weights[] = {10, 20, 30}; // Pesos das peças
    int values[] = {60, 100, 120}; // Valores das peças
    int n = sizeof(values) / sizeof(values[0]); // Número total de peças

    cout << "O valor máximo que pode ser obtido é: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
