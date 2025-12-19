#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3


typedef float Matrix[SIZE][SIZE];


void add_matrices(Matrix A, Matrix B, Matrix res);
void subtract_matrices(Matrix A, Matrix B, Matrix res);


void transpose(Matrix A, Matrix res);
void multiply_matrices(Matrix A, Matrix B, Matrix res);
void element_wise_multiply(Matrix A, Matrix B, Matrix res);


float calculate_determinant(Matrix A);
void get_adjoint(Matrix A, Matrix adj);
int inverse_matrix(Matrix A, Matrix inv);


void print_matrix(Matrix M, const char* name);

#endif
