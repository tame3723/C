#include <stdio.h>

#define N 4
void rotateMatrix(int matrix[N][N]) {
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N - x - 1; y++) {
            int temp = matrix[x][y];
            matrix[x][y] = matrix[N - 1 - y][x];
            matrix[N - 1 - y][x] = matrix[N - 1 - x][N - 1 - y];
            matrix[N - 1 - x][N - 1 - y] = matrix[y][N - 1 - x];
            matrix[y][N - 1 - x] = temp;
        }
}
}
// Without using extra space

void rotmatrix(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for (int i = 0; i < N; i++) {
        int left = 0, right = N - 1;
        while (left < right) {
            int temp = a[i][left];
            a[i][left] = a[i][right];
            a[i][right] = temp;
            left++;
            right--;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    rotateMatrix(matrix);

    printf("\nRotated Matrix:\n");
    printMatrix(matrix);
    int mat[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    printf("Original Matrix:\n");
    printMatrix(mat);

    rotmatrix(mat);

    printf("Matrix after 90 degree clockwise rotation:\n");
    printMatrix(mat);

    return 0;
}

