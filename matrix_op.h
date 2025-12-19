#ifndef MATRIX_OP_H
#define MATRIX_OP_H

// 定义矩阵维度为 3x3
#define SIZE 3 

// 定义矩阵类型，方便后续使用
typedef float Matrix[SIZE][SIZE];

// 在这里声明作业要求的功能 [cite: 29]
// 例如：
void transpose(Matrix A, Matrix result);
float determinant(Matrix A);

#endif
