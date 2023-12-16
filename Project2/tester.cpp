#include <iostream>
#include <algorithm>
#include <vector>

int DFS_Visit(std::vector<std::vector<int>> grafo, std::vector<int> colors, int n, int i) {
    // a cena da cor é importante mas como?
    int res = 0;
    int prev = 0;
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            prev = DFS_Visit(grafo, colors, n, grafo[i][j]);
        }
        res = std::max(res, 1 + prev);
    }
    return res;
}

void DFS(std::vector<std::vector<int>> grafo, std::vector<int> colors, int n) {
    int res = 0;
    // Maybe mudar os valores 1 para 0 e depois -1 para fechar ou assim ns bem
    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            res = std::max(res, DFS_Visit(grafo, colors, n, i));
        }
    }
    printf("%d\n", res);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2;
    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<int> colors(n + 1);

    for (int i = 1; i <= n; ++i) {
        colors[i] = 0; // cor 0-Branco 1-Cinzento 2-Preto
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2);
    }
    
    DFS(grafo, colors, n);

    return 0;
}