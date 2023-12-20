#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int SCC = 1;

void DFS_final(std::vector<std::vector<int>>& grafo, std::vector<int>& stack_SCC) {
    std::vector<int> colors(SCC, 0); // 0 = white, 1 = gray, 2 = black
    std::stack<int> stack;
    std::vector<int> longestPath(SCC, 0);
    int maxLength = 0;

    for (int i = 1; i < (int) stack_SCC.size(); ++i) {
        if (colors[stack_SCC[i]] == 0) {
            stack.push(stack_SCC[i]);

            while (!stack.empty()) {
                int current = stack.top();

                if (colors[current] == 0) {
                    colors[current] = 1;
                    for (int j = 0; j < (int) grafo[current].size(); j++) {
                        if (colors[grafo[current][j]] == 0) {
                            stack.push(grafo[current][j]);
                        }
                    }
                    
                    
                } else {
                    if (colors[current] == 1) {
                        for (int j = 0; j < (int) grafo[current].size(); j++) {
                            stack.push(grafo[current][j]);
                            longestPath[current] = std::max(longestPath[current], 1 + longestPath[grafo[current][j]]);       

                        }
                        maxLength = std::max(maxLength, longestPath[current]);
                    }
                    colors[current] = 2;
                    stack.pop();
                }
            }
        }
    }
    printf("%d\n", maxLength);
}


void SCC_builder(std::vector<std::vector<int>>& grafo, int n, std::vector<std::vector<int>>& grafo_final, std::vector<int>& stack_SCC) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) grafo[i].size(); j++) {
            if (stack_SCC[i] != stack_SCC[grafo[i][j]]) {
                grafo_final[stack_SCC[i]].push_back(stack_SCC[grafo[i][j]]);
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
    std::ios::sync_with_stdio(0);  // Disable sync with C libs (printf/scanf)
    int n, m;
    int v1, v2;
    std::cin >> n >> m;
    std::cin.tie(0);

    std::vector<std::vector<int>> grafo(n + 1);
    std::vector<std::vector<int>> transposto(n + 1);
    std::vector<int> stack_SCC(n + 1, 0);
    std::vector<int> priority_list ;


    for (int i = 0; i < m; ++i) {
        std::cin >> v1 >> v2;
        std::cin.tie(0);
        grafo[v1].push_back(v2);
        transposto[v2].push_back(v1);
    }

    DFS(grafo, n, priority_list);
    DFS_transposta(transposto, n, priority_list, stack_SCC);

    std::vector<std::vector<int>> grafo_final(SCC);

    SCC_builder(grafo, n, grafo_final, stack_SCC);

    DFS_final(grafo_final, stack_SCC);

    return 0;
}
