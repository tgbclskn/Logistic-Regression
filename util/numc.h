#ifndef LOGISTICREGRESSION_NUMC_H
#define LOGISTICREGRESSION_NUMC_H

#include "stdlib.h"
#include "math.h"

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

Matrix transpose(Matrix A);
Matrix mat_mul(Matrix A, Matrix B);


#endif //LOGISTICREGRESSION_NUMC_H
