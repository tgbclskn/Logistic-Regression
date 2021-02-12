#include "printer.h"

void print_matrix(Matrix A) {
    printf("\n");
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; ++j) {
            printf(" %0.2lf ", A.data[i][j]);
        }
        printf("\n");
    }
}