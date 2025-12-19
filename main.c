#include <stdio.h>
#include "matrix_op.h"

int main() {
    Matrix A = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    Matrix B = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
    Matrix res;

    print_matrix(A, "Matrix A");
    print_matrix(B, "Matrix B");

    add_matrices(A, B, res);
    print_matrix(res, "A + B");

    printf("Determinant of A: %.2f\n\n", calculate_determinant(A));

    if(inverse_matrix(A, res)) {
        print_matrix(res, "Inverse of A");
    } else {
        printf("A is singular and has no inverse.\n");
    }

    return 0;
}
