#include "matrix_op.h"
#include <stdio.h>

void add_matrices(Matrix A, Matrix B, Matrix res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            res[i][j] = A[i][j] + B[i][j];
}

void subtract_matrices(Matrix A, Matrix B, Matrix res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            res[i][j] = A[i][j] - B[i][j];
}

void transpose(Matrix A, Matrix res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            res[j][i] = A[i][j];
}

void multiply_matrices(Matrix A, Matrix B, Matrix res) {
	int i,j,k;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            res[i][j] = 0;
            for(k=0; k<SIZE; k++)
                res[i][j] += A[i][k] * B[k][j];
        }
    }
}

void element_wise_multiply(Matrix A, Matrix B, Matrix res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            res[i][j] = A[i][j] * B[i][j];
}

float calculate_determinant(Matrix A) {
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
           A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
           A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

void get_adjoint(Matrix A, Matrix adj) {
    Matrix temp;
    
    adj[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    adj[0][1] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    adj[0][2] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    
    adj[1][0] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    adj[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    adj[1][2] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    
    adj[2][0] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    adj[2][1] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);
    adj[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

int inverse_matrix(Matrix A, Matrix inv) {
    float det = calculate_determinant(A);
    if (det == 0) return 0; 
    
    Matrix adj;
    get_adjoint(A, adj);
    
    int i,j;
    
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            inv[i][j] = adj[i][j] / det;
    return 1;
}

void print_matrix(Matrix M, const char* name) {
    printf("%s:\n", name);
    int i,j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) printf("%.2f\t", M[i][j]);
        printf("\n");
    }
}
