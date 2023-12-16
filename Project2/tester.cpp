#include <iostream>
#include <algorithm>
#include <vector>

int DFS_Visit() {
    return 0;
}

void DFS(int** grafo, int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {

    }
    printf("%d\n", res);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2;
    int** grafo = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        grafo[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1][v2] = 1;
    }



    for (int i = 1; i <= n; i++) {
        printf("%d -> ", i);
        for ( int j = 1; j <= n; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }



    DFS(grafo, n);
    return 0;
}