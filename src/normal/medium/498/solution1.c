//
// Created by olive on 2/23/2021.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int *
findDiagonalOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = matrixSize * matrixColSize[0];
    int *result = calloc(*returnSize, sizeof(int));
    int cur = 0;
    for (int col = 0; col < matrixColSize[0]; ++col) {
        if ((col & 1) == 0) { // Even number -> up
            for (int x = 0, y = col; y >= 0; ++x, --y) {
                result[cur++] = matrix[y][x];
            }
        } else { // Odd number -> down
            for (int x = col, y = 0; x >= 0; --x, ++y) {
                result[cur++] = matrix[y][x];
            }
        }
    }
    for (int row = 1; row < matrixSize; ++row) {
        if ((row & 1) == 0) { // Even number -> up
            for (int x = row, y = matrixColSize[0] - 1; x < matrixColSize[0]; ++x, --y) {
                result[cur++] = matrix[y][x];
            }
        } else { // Odd number -> down
            for (int x = matrixColSize[0] - 1, y = row; y < matrixSize; --x, ++y) {
                result[cur++] = matrix[y][x];
            }
        }
    }
    return result;
}

int
main(void) {
    int **matrix = malloc(3 * sizeof(int *));
    matrix[0] = malloc(3 * sizeof(int));
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1] = malloc(3 * sizeof(int));
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2] = malloc(3 * sizeof(int));
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    int matrixSize = 3;
    int matrixColSize = 3;
    int returnSize = 0;
    int *result = findDiagonalOrder(matrix, matrixSize, &matrixColSize, &returnSize);
    printf("Returned array's size is %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(matrix[0]);
    free(matrix[1]);
    free(matrix[2]);
    free(matrix);
}
