#include <iostream>
#include <list>
#include <vector>
#include <chrono>

struct tile {
    int x, y;
    int price;
};

void createTile(tile* tile, int x, int y, int p) {
    tile->x = x;
    tile->y = y;
    tile->price = p;
}

int max(int a, int b, int c) {
   return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

void Algorithm(std::vector<tile*>& tilesVector, int x, int y, int n) {
    int dp[n + 1][x + 1][y +1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                std::cout << i << ", " << j << ", " << k << "\n";
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                }
                else if (tilesVector[i]->x <= x && tilesVector[i]->y <= y) {
                    if (x % tilesVector[i]->x == 0 && y % tilesVector[i]->y == 0) {
                        dp[i][j][k] = x / tilesVector[i]->x * y / tilesVector[i]->y * tilesVector[i]->price;
                    }
                    else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][x][y - tilesVector[i]->y], dp[i - 1][tilesVector[i]->x][y - tilesVector[i]->y]);
                    }
                }
                else if (tilesVector[i]->x <= y && tilesVector[i]->y <= x) {
                    if (x % tilesVector[i]->y == 0 && y % tilesVector[i]->x == 0) {
                        dp[i][j][k] = x / tilesVector[i]->y * y / tilesVector[i]->x * tilesVector[i]->price;                     
                    }
                    else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][x][y - tilesVector[i]->x] + tilesVector[i]->price, dp[i - 1][tilesVector[i]->y][y - tilesVector[i]->x] + tilesVector[i]->price);
                    }
                }

                // else {
                //     if ( tilesVector[i]->dim.y > x || tilesVector[i]->dim.y > x ) {
                //         dp[i][j] = 0;
                //     }
                // }

            }
        }
    }
    std::cout << dp[n][x][y];
}

int main() {
    int x, y, n, a, b, p;
    std::cin >> x >> y >> n;

    if ( n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<tile*> tilesVector;
  

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> p;

        tile* tiles = new tile;

        createTile(tiles, a, b, p);
        tilesVector.push_back(tiles);
    } 
    
    Algorithm(tilesVector, x, y, n);


    return 0;
}