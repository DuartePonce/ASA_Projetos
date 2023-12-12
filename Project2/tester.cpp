#include <iostream>
#include <algorithm>
#include <vector>

void grafo_esparso(int n, int m) {
    std::vector<std::vector<int>> grafo(n + 1);
    int v1, v2;
    for (int i = 0; i <= m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2); 
    }
}

void grafo_denso(int n, int m) {
    int v1, v2;
    int** grafo = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        grafo[i] = new int[n + 1];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1][v2] = 1;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    double densidade = (2.0 * m) / (n * (n - 1));
    if (densidade >= 0.5) { //Caso denso
        grafo_denso(n, m);
    } else {// Caso esparso
        grafo_esparso(n, m);
    }
    return 0;
}