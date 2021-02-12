#include <stdio.h>
#include "numc.h"

static Matrix create_matrix(size_t rows, size_t cols) {
    Matrix matrix;
    double **x;
    x = malloc(rows * sizeof *x);
    for (int i=0; i<rows; i++) {
        x[i] = malloc(cols * sizeof *x[i]);
    }
    printf("%p\n", &x[0][0]);
    matrix.data = x;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

Matrix zeros(size_t rows, size_t cols) {
    Matrix x = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            x.data[i][j] = 0;
        }
    }
    return x;
}

void mat_mul(
        double **result,
        double **A,
        double **B,
        size_t row_a,
        size_t col_a,
        size_t row_b,
        size_t col_b
) {

}