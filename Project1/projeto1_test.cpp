#include <iostream>
#include <vector>
#include <algorithm>

struct tile {
    int x, y;
    int price;
};

void createTile(tile* t, int x, int y, int p) {
    t->x = x;
    t->y = y;
    t->price = p;
}

int max(int a, int b, int c, int d) {
    return std::max(std::max(a, b), std::max(c, d));
}

void deallocateMemory(std::vector<tile*>& tilesVector) {
    for (size_t i = 0; i < tilesVector.size(); ++i) {
        delete tilesVector[i];
    }
}

int algorithm(const std::vector<tile*>& tilesVector, int x, int y, int n) {
    std::vector<std::vector<std::vector<int> > > dp(n + 1, std::vector<std::vector<int> >(x + 1, std::vector<int>(y + 1, 0)));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                } else if (tilesVector[i]->x <= j && tilesVector[i]->y <= k) {
                    if (j % tilesVector[i]->x == 0 && k % tilesVector[i]->y == 0) {
                        dp[i][j][k] = max(j / tilesVector[i]->x * k / tilesVector[i]->y * tilesVector[i]->price,
                                          j / tilesVector[i]->y * k / tilesVector[i]->x * tilesVector[i]->price, 0, 0);
                    } else {
                        dp[i][j][k] = max(dp[i - 1][j][k],
                                          dp[i - 1][j][k - tilesVector[i]->y + 1] + tilesVector[i]->price,
                                          dp[i - 1][tilesVector[i]->x][k - tilesVector[i]->y + 1] +
                                          tilesVector[i]->price, dp[i][j][k - 1]);
                    }
                } else if (tilesVector[i]->x <= k && tilesVector[i]->y <= j) {
                    if (j % tilesVector[i]->y == 0 && k % tilesVector[i]->x == 0) {
                        dp[i][j][k] = max(j / tilesVector[i]->x * k / tilesVector[i]->y * tilesVector[i]->price,
                                          j / tilesVector[i]->y * k / tilesVector[i]->x * tilesVector[i]->price, 0, 0);
                    } else {
                        dp[i][j][k] = max(dp[i - 1][j][k],
                                          dp[i - 1][j][k - tilesVector[i]->x + 1] + tilesVector[i]->price,
                                          dp[i - 1][tilesVector[i]->y][k - tilesVector[i]->x + 1] +
                                          tilesVector[i]->price, dp[i][j][k - 1]);
                    }
                } else {
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    return dp[n][x][y];
}

int main() {
    int x, y, n, a, b, p;
    std::cin >> x >> y >> n;

    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<tile*> tilesVector;
    tilesVector.push_back(nullptr); // Placeholder for index 0

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> p;

        tile* tiles = new tile;
        createTile(tiles, a, b, p);
        tilesVector.push_back(tiles);
    }

    int result = algorithm(tilesVector, x, y, n);
    std::cout << result << std::endl;

    deallocateMemory(tilesVector);

    return 0;
}
