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

void mat_mul(
        double **result,
        double **A,
        double **B,
        size_t row_a,
        size_t col_a,
        size_t row_b,
        size_t col_b
);

#endif //LOGISTICREGRESSION_NUMC_H
