//// Created by olive on 2/22/2021.//#include <stdio.h>#include <assert.h>#include <stdlib.h>#define swap(a, b) ((a)^=(b)^=(a)^=(b))voidrotate(int **matrix, int matrixSize, int *matrixColSize) {    (void) matrixColSize;    // 对角线    for (int i = 1; i < matrixSize; ++i) {        for (int j = 0; j < i; ++j) {            swap(matrix[i][j], matrix[j][i]);        }    }    // 镜像    for (int i = 0; i < matrixSize; ++i) {        for (int j = matrixSize / 2 - 1; j >= 0; --j) {            swap(matrix[i][j], matrix[i][matrixSize - 1 - j]);        }    }}