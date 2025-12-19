#include "matrix_op.h"
#include <stdio.h>


void add_matrices(Matrix A, Matrix B, Matrix res) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}


void transpose(Matrix A, Matrix res) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            res[j][i] = A[i][j];
        }
    }
}


void element_wise_multiply(Matrix A, Matrix B, Matrix res) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            res[i][j] = A[i][j] * B[i][j];
        }
    }
}
