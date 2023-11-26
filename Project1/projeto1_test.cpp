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
                //std::cout << i << ", " << j << ", " << k << "-";
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                }
                else if (tilesVector[i]->x <= j && tilesVector[i]->y <= k) {
                    if (j % tilesVector[i]->x == 0 && k % tilesVector[i]->y == 0) {
                        dp[i][j][k] = max ( j / tilesVector[i]->x * k / tilesVector[i]->y * tilesVector[i]->price, j / tilesVector[i]->y * k / tilesVector[i]->x * tilesVector[i]->price, 0, 0);
                    }
                    else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][x][k - tilesVector[i]->y + 1] + tilesVector[i]->price, dp[i - 1][tilesVector[i]->x][k - tilesVector[i]->y + 1] + tilesVector[i]->price, dp[i][j][k-1]);
                    }
                }
                else if (tilesVector[i]->x <= k && tilesVector[i]->y <= j) {
                    if (j % tilesVector[i]->y == 0 && k % tilesVector[i]->x == 0) {
                        dp[i][j][k] = max ( j / tilesVector[i]->x * k / tilesVector[i]->y * tilesVector[i]->price, j / tilesVector[i]->y * k / tilesVector[i]->x * tilesVector[i]->price, 0, 0);
                    }
                    else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][x][k - tilesVector[i]->x + 1] + tilesVector[i]->price, dp[i - 1][tilesVector[i]->y][k - tilesVector[i]->x + 1] + tilesVector[i]->price, dp[i][j][k-1]);
                    }
                }
                else {
                    dp[i][j][k] = 0;
                }

                // else {
                //     if ( tilesVector[i]->dim.y > x || tilesVector[i]->dim.y > x ) {
                //         dp[i][j] = 0;    
                //     }
                // }
                //std::cout << dp[i][j][k] << "\n";
            }
        }
    }
    std::cout << dp[n][x][y];
}

int main() {
    int x, y, n, a, b, p;

    if (std::cin >> x >> y >> n && x > 0 && y > 0 && n > 0) {
        std::vector<tile*> tilesVector;
        tilesVector.push_back(0);

        for (int i = 0; i < n; i++) {
            if (std::cin >> a >> b >> p && a > 0 && b > 0 && p > 0){
                tile* tiles = new tile;
                createTile(tiles, a, b, p);
                tilesVector.push_back(tiles);
            }
            else{
                return 0;
            }
        } 

        Algorithm(tilesVector, x, y, n);
        return 0;

    } else {
        return 0;
    }

} 
