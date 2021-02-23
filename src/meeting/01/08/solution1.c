//
// Created by olive on 2/23/2021.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <strings.h>

/**
 * 思路是先将0元素标记出来.
 * 由于只需要行、列信息, 只需要o(2n)的空间消耗.
 */
void
setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    short row_clr[matrixSize], col_clr[matrixColSize[0]];
    bzero(row_clr, matrixSize * sizeof(short));
    bzero(col_clr, matrixColSize[0] * sizeof(short));

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == 0) {
                row_clr[i] = 1;
                col_clr[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; ++i) {
        if (row_clr[i] == 1) {
            for (int j = 0; j < matrixColSize[0]; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < matrixColSize[0]; ++j) {
        if (col_clr[j] == 1) {
            for (int i = 0; i < matrixSize; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
