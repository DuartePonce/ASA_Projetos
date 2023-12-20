#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
// txt5 15
// txt4 5 certo 
// kasaraju
int SCC = 1;

void DFS_final(std::vector<std::vector<int>>& grafo, int n, std::vector<int>& priority_list, std::vector<int>& stack_SCC) {
    std::vector<int> colors(n + 1, 0); // 0 = white, 1 = gray, 2 = black
    std::stack<int> stack;
    for (int i = 0; i < (int) priority_list.size(); ++i) {
        if (colors[priority_list[i]] == 0) {
            stack.push(priority_list[i]);
            while (!stack.empty()) {
                int current = stack.top();
                if (colors[current] == 0) {
                    colors[current] = 1;
                    for (int j = 0; j < (int) grafo[current].size(); j++) {
                        if (colors[grafo[current][j]] == 0) {
                            stack.push(grafo[current][j]);
                            stack_SCC[grafo[current][j]] = SCC;        
                        }
                    }
                } else {
                    if (colors[current] == 1) {
                        stack_SCC[priority_list[i]] = SCC;
                    }
                    colors[current] = 2;
                    stack.pop();
                }
            }
        }
        SCC++;
    }
}
// void DFS_Visit_final(std::vector<std::vector<int>>& graph, int node, std::vector<int>& longestPath, std::vector<bool>& visited) {
//     visited[node] = true;
//     for (int neighbor : graph[node]) {
//         if (!visited[neighbor]) {
//             DFS_Visit_final(graph, neighbor, longestPath, visited);
//         }
//         longestPath[node] = std::max(longestPath[node], 1 + longestPath[neighbor]);
//     }
// }

// void DFS_final(std::vector<std::vector<int>>& graph) {
//     int nodes = graph.size();
//     std::vector<bool> visited(nodes, false);
//     std::vector<int> longestPath(nodes, 0);

//     for (int i = 0; i < nodes; ++i) {
//         if (!visited[i]) {
//             DFS_Visit_final(graph, i, longestPath, visited);
//         }
//     }

//     int maxLength = 0;
//     for (int length : longestPath) {
//         maxLength = std::max(maxLength, length);
//     }
//     printf("%d\n", maxLength);
// }


void SCC_builder(std::vector<std::vector<int>>& grafo, int n, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
    std::vector<int> colors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) grafo[i].size(); j++) {
            int target = stack_SCC[grafo[i][j]];
            int source = stack_SCC[i];

            if (source != target) {
                // Check if target exists in the grafo_final[source] vector
                auto it = std::find(grafo_final[source].begin(), grafo_final[source].end(), target);

                // If it doesn't exist, add it to grafo_final[source]
                if (it == grafo_final[source].end()) {
                    grafo_final[source].push_back(target);
                }
            }
        }
    }
}


void DFS_transposta(std::vector<std::vector<int>>& grafo, int n, std::vector<int>& priority_list, std::vector<int>& stack_SCC) {
    std::vector<int> colors(n + 1, 0); // 0 = white, 1 = gray, 2 = black
    std::stack<int> stack;
    for (int i = 0; i < (int) priority_list.size(); ++i) {
        if (colors[priority_list[i]] == 0) {
            stack.push(priority_list[i]);
            while (!stack.empty()) {
                int current = stack.top();
                if (colors[current] == 0) {
                    colors[current] = 1;
                    for (int j = 0; j < (int) grafo[current].size(); j++) {
                        if (colors[grafo[current][j]] == 0) {
                            stack.push(grafo[current][j]);
                            stack_SCC[grafo[current][j]] = SCC;        
                        }
                    }
                } else {
                    if (colors[current] == 1) {
                        stack_SCC[priority_list[i]] = SCC;
                    }
                    colors[current] = 2;
                    stack.pop();
                }
            }
        }
        SCC++;
    }
}

void DFS(std::vector<std::vector<int>>& grafo, int n, std::vector<int>& priority_list) {
    std::vector<int> colors(n + 1, 0); // 0 = white, 1 = gray, 2 = black
    std::stack<int> stack;

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            stack.push(i);
            while (!stack.empty()) {
                int current = stack.top();
                //printf("current: %d\n", current);
                if (colors[current] == 0) {
                    colors[current] = 1;
                    for (int j = 0; j < (int) grafo[current].size(); j++) {
                        if (colors[grafo[current][j]] == 0) {
                            stack.push(grafo[current][j]);
                        }
                    }
                } else {
                    if (colors[current] == 1) {
                        priority_list.insert(priority_list.begin(), current);
                    }
                    colors[current] = 2;
                    stack.pop();
                }
            }
        }
    }
}



int main() {
    int n, m;
    int v1, v2;
    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<std::vector<int>> transposto(n + 1);
    std::vector<int> stack_SCC(n + 1, 0);
    std::vector<int> priority_list ;


    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        grafo[v1].push_back(v2);
        transposto[v2].push_back(v1);
    }

    // for (int i = 1; i<=n; i++) {
    //     printf("%d -> ", i);
    //     for (int j = 0; j < (int) grafo[i].size();j++) {
    //         printf("%d ", grafo[i][j]);
    //     }
    //     printf("\n");
    // }

    DFS(grafo, n, priority_list);
    
    // printf("\n");
    // printf("\n");

    // printf("priority list:\n");
    // for (int i = 0; i<(int) priority_list.size(); i++) {
    //     printf("%d ", priority_list[i]);
    // }
    // printf("\n");

    // printf("trasposto\n");
    // for (int i = 1; i<=n; i++) {
    //     printf("%d -> ", i);
    //     for (int j = 0; j < (int) transposto[i].size();j++) {
    //         printf("%d ", transposto[i][j]);
    //     }
    // printf("\n");
    // }
    // printf("\n");
    // printf("\n");

    DFS_transposta(transposto, n, priority_list, stack_SCC);
    
    // printf("lista com os valores de SCC:\n");
    // for (int i = 1; i < (int) stack_SCC.size(); i++) {
    //     printf("%d i-> %d\n", i, stack_SCC[i]);
    // }
    // printf("\n");

    std::vector<std::vector<int>> grafo_final(SCC);

    SCC_builder(grafo, n, grafo_final, stack_SCC);

    // printf("grafo aciclico:\n");
    // for (int i = 1; i < (int) grafo_final.size(); i++) {
    //     printf("%d ->", i);
    //     for (int j = 0; j < (int) grafo_final[i].size(); j++) {
    //         printf("%d ", grafo_final[i][j]);
    //     }
    //     printf("\n");
    // }

    DFS_final(grafo_final);

    return 0;
}