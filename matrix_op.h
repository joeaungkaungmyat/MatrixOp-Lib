#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3 

typedef float Matrix[SIZE][SIZE];

void transpose(Matrix A, Matrix result);
float determinant(Matrix A);

#endif

