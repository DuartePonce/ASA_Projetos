#include <iostream>
#include <algorithm>
int corteHoriz(int N, int M, int** P) { 
    int res = 0;
    for (int k = 1; k < M; ++k) {
        res = std::max(res, P[N][k] + P[N][M - k]);
    }
    return res;
}
int corteVert(int N, int M, int** P) { 
    int res = 0;
    for (int k = 1; k < N; ++k) {
        res = std::max(res, P[k][M] + P[N - k][M]);
    }
    return res;
}
int ProblemaXY(int N, int M, int** matrix, int n) {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i == 0 || j == 0) {
            matrix[i][j] = 0;
            } else {
                matrix[i][j] = std::max(std::max(matrix[i][j], 0), std::max(corteHoriz(i, j, matrix), corteVert(i, j, matrix)) );
            }  
        }
    }
    return matrix[N][M];
}
int main() {
    int x, y, n, a, b, p;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    int** matrix = new int*[x + 1];
    for (int i = 0; i < x + 1; ++i) {
        matrix[i] = new int[y + 1];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &p);
        if (a <= x && b <= y) {
            matrix[a][b] = std::max(matrix[a][b], p);
            if (b <= x && a <= y) {
                matrix[b][a] = std::max(matrix[b][a], p);
            }
        }   
    } 
    printf("%d\n", ProblemaXY(x, y, matrix, n));
    return 0;
}