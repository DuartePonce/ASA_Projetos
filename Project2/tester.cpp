#include <iostream>
#include <algorithm>
#include <vector>

int SCC = 1;


void DFS_visit_SCC(std::vector<std::vector<int>>& grafo, std::vector<int>& colors, int i, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
    colors[i] = 1;

    for (int j = 0; j < (int)grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0 && stack_SCC[i] != stack_SCC[grafo[i][j]]) {
            printf("color: %d - stack[i]: %d - stacj[grafo]: %d\n",colors[i], stack_SCC[i], stack_SCC[grafo[i][j]]);
            grafo_final[stack_SCC[i]].push_back(stack_SCC[grafo[i][j]]);
        }
    }   
}

void DFS_SCC(std::vector<std::vector<int>>& grafo, std::vector<int>& colors, int n, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {


    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            printf("i : %d\n", i);
            DFS_visit_SCC(grafo, colors, i, grafo_final, stack_SCC);
        }
    }
}

void DFS_Visit_transposta(std::vector<std::vector<int>> grafo, std::vector<int>& colors, int i, std::vector<int>& stack_SCC) {
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            DFS_Visit_transposta(grafo, colors, grafo[i][j], stack_SCC);
            stack_SCC[grafo[i][j]] = SCC;

        }
    }
}

void DFS_transposta(std::vector<std::vector<int>> grafo, std::vector<int>& colors, int n, std::vector<int>& priority_list, std::vector<int>& stack_SCC) {

    for (int i = 0; i < n; i++) {
        if (colors[priority_list[i]] == 0) {
            DFS_Visit_transposta(grafo, colors, priority_list[i], stack_SCC);
            stack_SCC[priority_list[i]] = SCC;
            SCC++;
        }
    }
}


int DFS_Visit(std::vector<std::vector<int>> grafo, std::vector<int>& colors, std::vector<int>& ft, int i, std::vector<int>& priority_list) {
    int son = 0;
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            son = DFS_Visit(grafo, colors, ft, grafo[i][j], priority_list);
        }
        ft[i] = std::max(ft[i], 1 + son);
    }

    priority_list.insert(priority_list.begin(), i);
    return ft[i];
}

void DFS(std::vector<std::vector<int>> grafo, std::vector<int>& colors, std::vector<int>& ft, int n, std::vector<int>& priority_list) {

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            DFS_Visit(grafo, colors, ft, i, priority_list);
        }
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2;
    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<std::vector<int>> transposto(n + 1);
    std::vector<int> stack_SCC(n+1);
    std::vector<int> colors(n + 1);
    std::vector<int> ft(n + 1);            
    std::vector<int> priority_list(n);

    for (int i = 1; i <= n; ++i) {
        colors[i] = 0; // cor 0-Branco 1-Cinzento 2-Preto
        ft[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2);
        transposto[v2].push_back(v1);
    }
    
    DFS(grafo, colors, ft, n, priority_list);
    std::fill(colors.begin(), colors.end(), 0);

    DFS_transposta(transposto, colors, n, priority_list, stack_SCC);
    std::fill(colors.begin(), colors.end(), 0);

    std::vector<std::vector<int>> grafo_final(SCC);

    DFS_SCC(grafo, colors, n, grafo_final, stack_SCC);

    for (int i  = 0 ; i < (int) grafo_final.size(); i++) {
        printf("%d -> ", i);
        for (int j = 0 ; j < (int) grafo_final[i].size(); j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    std::fill(colors.begin(), colors.end(), 0);
    std::fill(ft.begin(), ft.end(), 0);

    printf("ola\n");
    DFS(grafo_final, colors, ft, n, priority_list);

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = std::max(res, ft[i]);
    }
    printf("%d\n",res);

    return 0;
}