#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> grafo(n + 1); // Initialize graph

    int v1, v2;
    for (int i = 0; i <= m; ++i) {
        std::cin >> v1 >> v2;
        grafo[v1].push_back(v2); // Add edge v1->v2
    }
    printf("ola\n");
    for (int i = 0; i <= n; ++i) {
        printf("%d --->", i);
        for (int j = 0; j <  (int) grafo[i].size(); ++j) { //int v : grafo[i]
            printf("%d -  ", grafo[i][j]);
        }
        printf("\n");
    }
    return 0;
}