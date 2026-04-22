#include <stdio.h>

int main() {
    // Matrix A: 2x3, Matrix B: 3x2 -> Result: 2x2
    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;

    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int result[2][2];

    // Initialize result matrix with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix Multiplication Logic
    for (int i = 0; i < r1; i++) {         
        for (int j = 0; j < c2; j++) {     
            for (int k = 0; k < c1; k++) { 
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display Result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
