#ifndef LOGISTICREGRESSION_MATRIX_H
#define LOGISTICREGRESSION_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrices {
    double **data;
    size_t rows;
    size_t cols;
} Matrix;

Matrix create_matrix(size_t rows, size_t cols, const double *data);

Matrix zeros(size_t rows, size_t cols);
Matrix ones(size_t rows, size_t cols);

double sum(Matrix A);
double mean(Matrix A);
double std(Matrix A);

Matrix transpose(Matrix A);
Matrix mat_add(Matrix A, Matrix B);
Matrix mat_sub(Matrix A, Matrix B);
Matrix mat_mul(Matrix A, Matrix B);
Matrix mat_dot(Matrix A, Matrix B);
Matrix power(Matrix A, double n);
void shuffle(Matrix X);


#endif //LOGISTICREGRESSION_MATRIX_H
