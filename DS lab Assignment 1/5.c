#include <stdio.h>

void displayMatrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r = 2, c = 2;
    int A[2][2] = {{5, 8}, {3, 4}};
    int B[2][2] = {{1, 2}, {7, 1}};
    int sum[2][2], diff[2][2];

    // Perform Addition and Subtraction
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("Matrix A + B:\n");
    displayMatrix(r, c, sum);

    printf("\nMatrix A - B:\n");
    displayMatrix(r, c, diff);

    return 0;
}
