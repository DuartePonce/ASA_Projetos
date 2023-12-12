#include <iostream>
#include <algorithm>
#include <vector>   
#include <unordered_map>

class Vertex {
    public :
        int id; // Number of the vertex
        int color = 0; // 0 = white 1 = grey 2 = black;
        int d = 0;
        int f = 0;
        int pi = 0;
        std::vector<Vertex> adj; // List of vertex that the specific vertex points to
    
        // Constructors
        Vertex() : id(0) {} // Default constructor

        Vertex(int vertexId) : id(vertexId) {}
        
        void addEdge(int v1, int v2, std::unordered_map<int, Vertex>& vertexMap);

};

void Vertex::addEdge(int v1, int v2, std::unordered_map<int, Vertex>& vertexMap) {
    // Check if v1 vertex exists, if not, create it
    if (vertexMap.find(v1) == vertexMap.end()) {
        vertexMap[v1] = Vertex(v1);
    }
    // Check if v2 vertex exists, if not, create it
    if (vertexMap.find(v2) == vertexMap.end()) {
        vertexMap[v2] = Vertex(v2);
    }
    // Now add the edge
    vertexMap[v1].adj.push_back(vertexMap[v2]);
}

void printGraph(const std::unordered_map<int, Vertex>& vertexMap) {
    for (const auto& entry : vertexMap) {
        std::cout << "Vertex " << entry.first << " -> ";
        for (const auto& adjVertex : entry.second.adj) {
            std::cout << adjVertex.id << " ";
        }
        std::cout << std::endl;
    }
}

void DFS_Visit(std::unordered_map<int, Vertex>& vertexMap, Vertex& u, int& time) {
    u.color = 1;
    u.d = time;
    time++;
    for (int j = 0; j < (int) u.adj.size(); ++j) {
        if (u.adj[j].color == 0) {
            u.adj[j].pi = u.id;
            DFS_Visit(vertexMap, u.adj[j], time);
        }
    }
    u.color = 2;
    u.f = time;
    time++;
    vertexMap[u.id] = u;
}


void DFS(std::unordered_map<int, Vertex>& vertexMap, std::vector<int>& roots) {
    int time = 1;
    for (int i = 0; i <= (int) roots.size(); ++i) {
        auto it = vertexMap.find(roots[i]);
        if (it != vertexMap.end()) {
            
            DFS_Visit(vertexMap, it->second, time);
        }
    }
}



int main() { 
    int n, m, v1, v2;
    scanf("%d %d", &n, &m);

    std::unordered_map<int, Vertex> vertexMap;
    vertexMap.reserve(n); // Reserving memory for n elements to prevent mmemory leaks


    std::vector<int> roots(n);
    for (int i = 0; i < n; ++i) {
        roots[i] = i + 1;
    }
    Vertex v(0);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        v.addEdge(v1, v2, vertexMap);

        auto it = std::find(roots.begin(), roots.end(), v2);
        if (it != roots.end() || *it == v2) {
            roots.erase(it);
        }
    }
    printGraph(vertexMap);
    DFS(vertexMap, roots);
    int res = 0;
    for (const auto& entry : vertexMap) {
        res = std::max(res, entry.second.d);
        
    }
    printf("%d", res);

    return 0;
}