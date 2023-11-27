#include <iostream>
#include <list>
#include <vector>
#include <chrono>
#include <algorithm>

struct tile {
    int x, y;
    int price;
};

void createTile(tile* tile, int x, int y, int p) {
    tile->x = x;
    tile->y = y;
    tile->price = p;
}

int max(int a, int b, int c, int d) {
    return std::max(std::max(a, b), std::max(c, d));
}

void Algorithm(std::vector<tile*>& tilesVector, int x, int y, int n) {
    int dp[n + 1][x + 1][y +1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                // std::cout << i << ", " << j << ", " << k << "-";
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                }
                else if ( (tilesVector[i]->x > j || tilesVector[i]->y > k) && (tilesVector[i]->y > j || tilesVector[i]->x > k) ) {
                    dp[i][j][k] = 0;
                } else {
                   dp[i][j][k] = max(dp[i-1][j][k], 
                                     dp[i][j][k - 1], 
                                     j / tilesVector[i]->x * k / tilesVector[i]->y * tilesVector[i]->price,
                                     j / tilesVector[i]->y * k / tilesVector[i]->x * tilesVector[i]->price
                                     );
                }
                //std::cout << dp[i][j][k] << "\n";
            }
        }
    }
    std::cout << dp[n][x][y] << "\n";
}

int main() {
    int x, y, n, a, b, p;
    std::cin >> x >> y >> n;

    if ( n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<tile*> tilesVector;
    tilesVector.push_back(0);
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> p;

        tile* tiles = new tile;

        createTile(tiles, a, b, p);
        tilesVector.push_back(tiles);
    } 

    Algorithm(tilesVector, x, y, n);


    return 0;
}