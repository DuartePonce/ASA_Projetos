#include <iostream>
#include <algorithm>
#include <vector>



int DFS_Visit(std::vector<std::vector<int>> grafo, std::vector<int>& colors, std::vector<int>& ft, int i) {
    int son = 0;
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            son = DFS_Visit(grafo, colors, ft, grafo[i][j]);
        }
        ft[i] = std::max(ft[i], 1 + son);
    }
    return ft[i];
}

void DFS(std::vector<std::vector<int>> grafo, std::vector<int>& colors, std::vector<int>& ft, int n) {

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            DFS_Visit(grafo, colors, ft, i);
        }
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2;
    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<std::vector<int>> transposto(n + 1);
    std::vector<int> colors(n + 1);
    std::vector<int> ft(n + 1);

    for (int i = 1; i <= n; ++i) {
        colors[i] = 0; // cor 0-Branco 1-Cinzento 2-Preto
        ft[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2);
        transposto[v2].push_back(v1);
    }
    
    DFS(grafo, colors, ft, n);



    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = std::max(res, ft[i]);
    }
    printf("%d\n",res);
    
    return 0;
}