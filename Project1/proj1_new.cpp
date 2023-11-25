#include <iostream>
#include <list>
#include <vector>
#include <chrono>

struct dimension {
    int x, y;
};
struct tile {
    dimension dim;
    int price;
};
void createDimension(dimension* dim, int x, int y) {
    dim->x = x;
    dim->y = y;
}
void createTile(tile* tile, dimension* dim, int p) {
    tile->dim = *dim;
    tile->price = p;
}
int max(int a, int b, int c) {
   return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

// int knapsack(int W, int weights[], int values[], int n) {
//     int dp[n + 1][W + 1];
//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {
           
//         }
//     }
//     return dp[n][W]; // Retornando o valor máximo obtido para o peso W
// }

int main() {
    int x, y, n, a, b, p;
    std::cin >> x >> y >> n;
    dimension* mainTile = new dimension;
    createDimension(mainTile, x, y);
    std::vector<tile*> tilesVector;

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> p;
        dimension* dim = new dimension;
        tile* tiles = new tile;
        createDimension(dim, a, b);
        createTile(tiles, dim, p);
        tilesVector.push_back(tiles);
    } 

    

    return 0;
}
