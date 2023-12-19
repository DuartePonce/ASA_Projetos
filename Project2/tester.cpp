#include <iostream>
#include <algorithm>
#include <vector>

int SCC = 1;

int DFS_Visit_final(std::vector<std::vector<int>>& grafo, std::vector<int>& colors, int i) {
    int son = 0;
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            son = std::max(son, 1 + DFS_Visit_final(grafo, colors, grafo[i][j]));
        }
    }

    return son;
}

void DFS_final(std::vector<std::vector<int>>& grafo) {
    std::vector<int> colors(SCC, 0);
    int res = 0;
    for (int i = 1; i < SCC; i++) {  
        if (colors[i] == 0) {
            //printf("%d i que oassa na DFS\n", i);
            res = std::max(res, DFS_Visit_final(grafo, colors, i));
        }
    }
    printf("%d\n", res);
}


// void DFS_visit_SCC(std::vector<std::vector<int>>& grafo, std::vector<int>& colors, int i, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
//     colors[i] = 1;

//     for (int j = 0; j < (int)grafo[i].size(); j++) {
//         if (stack_SCC[i] != stack_SCC[grafo[i][j]]) {
//             grafo_final[stack_SCC[i]].push_back(stack_SCC[grafo[i][j]]);
//         }
//     }   
// }

// void DFS_SCC(std::vector<std::vector<int>>& grafo, int n, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
//     std::vector<int> colors(n + 1, 0);


//     for (int i = 1; i <= n; i++) {
//         if (colors[i] == 0) {
//             DFS_visit_SCC(grafo, colors, i, grafo_final, stack_SCC);
//         }
//     }
// }

void SCC_builder(std::vector<std::vector<int>>& grafo, int n, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
    std::vector<int> colors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            for (int j = 0; j < (int) grafo[i].size(); j++) {
                if (stack_SCC[i] != stack_SCC[grafo[i][j]]) {
                    grafo_final[stack_SCC[i]].push_back(stack_SCC[grafo[i][j]]);
                }
            }
        }
    }
}


void DFS_Visit_transposta(std::vector<std::vector<int>>& grafo, std::vector<int>& colors, int i, std::vector<int>& stack_SCC) {
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            DFS_Visit_transposta(grafo, colors, grafo[i][j], stack_SCC);
            stack_SCC[grafo[i][j]] = SCC;

        }
    }
}

void DFS_transposta(std::vector<std::vector<int>>& grafo, int n, std::vector<int>& priority_list, std::vector<int>& stack_SCC) {
    std::vector<int> colors(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (colors[priority_list[i]] == 0) {
            DFS_Visit_transposta(grafo, colors, priority_list[i], stack_SCC);
            stack_SCC[priority_list[i]] = SCC;
            SCC++;
        }
    }
}


void DFS_Visit(std::vector<std::vector<int>> grafo, std::vector<int>& colors, int i, std::vector<int>& priority_list) {
    colors[i] = 1;
    for (int j = 0; j < (int) grafo[i].size(); j++) {
        if (colors[grafo[i][j]] == 0) {
            DFS_Visit(grafo, colors, grafo[i][j], priority_list);
        }
    }

    priority_list.insert(priority_list.begin(), i);

}

void DFS(std::vector<std::vector<int>> grafo, int n, std::vector<int>& priority_list) {
    std::vector<int> colors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            DFS_Visit(grafo, colors, i, priority_list);
        }
    }

}

int main() {
    int n, m;
    int v1, v2;
    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<std::vector<int>> transposto(n + 1);
    std::vector<int> stack_SCC(n+1);
    std::vector<int> priority_list(n);


    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2);
        transposto[v2].push_back(v1);
    }

    DFS(grafo, n, priority_list);

    DFS_transposta(transposto, n, priority_list, stack_SCC);

    std::vector<std::vector<int>> grafo_final(SCC);

    SCC_builder(grafo, n, grafo_final, stack_SCC);

    // printf("SCC %d\n", SCC);
    // for (int i = 1; i < (int) grafo_final.size(); i++) {
    //     printf("%d ->", i);
    //     for (int j = 0; j < (int) grafo_final[i].size(); j++) {
    //         printf("%d ", grafo_final[i][j]);
    //     }
    //     printf("\n");
    // }

    DFS_final(grafo_final);
    //printf("4\n");
    // int res = 0;
    // for (int i = 1; i <= n; ++i) {
    //     res = std::max(res, ft2[i]);
    // }
    // printf("%d\n",res);

    return 0;
}