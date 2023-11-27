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

int funcAux1(int N, int M, int** P) { // este N e M vao ser o i e j no algoritmo
    int res = 0;

    for (int k = 1; k < M; ++k) {
        std::max(res, P[N][k] + P[N][M - k]);
    }

    return res;
}

int funcAux2(int N, int M, int** P) { // este N e M vao ser o i e j no algoritmo
    int res = 0;

    for (int k = 1; k < N; ++k) {
        std::max(res, P[k][M] + P[N - k][M]);
    }

    return res;
}

int Algorithm(int N, int M, int p, int** matrix) {

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i == 0 || j == 0) {
               matrix[i][j] = 0;
            } else {
               matrix[i][j] = std::max( 1 , std::max(funcAux1(i, j, matrix), funcAux2(i, j, matrix)) ); // este 1 é o que eu ns oo que é
            }
        }
    }
    return 0;
}

int main() {
    int x, y, n, a, b, p;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    int res = 0;

    if ( n == 0) {
        std::cout << 0;
        return 0;
    }

    int** matrix = new int*[x + 1];
    for (int i = 0; i < x + 1; ++i) {
        matrix[i] = new int[y + 1];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &p);

        res = std::max(Algorithm(x, y, p, matrix), res);
    } 

    printf("%d", res);



    return 0;
}