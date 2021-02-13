#include "matrix.h"
#include <math.h>

//----------------------- Matrix Implementation ----------------------//
static Matrix init_matrix(size_t rows, size_t cols) {
    Matrix matrix;
    double **x;
    x = malloc(rows * sizeof *x);
    for (size_t i = 0; i < rows; i++) {
        x[i] = malloc(cols * sizeof *x[i]);
    }
    matrix.data = x;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

Matrix create_matrix(size_t rows, size_t cols, const double *data) {
    Matrix matrix;
    double **x;
    size_t counter = 0;
    x = malloc(rows * sizeof *x);
    for (size_t i = 0; i < rows; i++) {
        x[i] = malloc(cols * sizeof *x[i]);
        for (size_t j = 0; j < cols; j++) {
            x[i][j] = *(data + counter);
            counter++;
        }
    }
    matrix.data = x;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

//-------------------- Zeros ----------------------//
Matrix zeros(size_t rows, size_t cols) {
    Matrix x = init_matrix(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x.data[i][j] = 0.0;
        }
    }
    return x;
}

//------------------ Ones ---------------------//
Matrix ones(size_t rows, size_t cols) {
    Matrix x = init_matrix(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x.data[i][j] = 1.0;
        }
    }
    return x;
}

//-------------------- Sum ---------------------//
double sum(Matrix A) {
    double sum = 0.0;
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            sum += A.data[i][j];
        }
    }
    return sum;
}

//---------------------- Mean ---------------------//
double mean(Matrix A) {
    double sum = 0.0;
    double num_elements = (double) (A.rows * A.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            sum += A.data[i][j];
        }
    }
    return sum / num_elements;
}

//---------------------- STD ---------------------//
double std(Matrix A) {
    double sum = 0.0;
    double num_elements = (double) (A.rows * A.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            sum += pow(A.data[i][j] - mean(A), 2);
        }
    }
    return sqrt(sum / (num_elements - 1));
}

//-------------------------- Transpose -------------------------//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
Matrix transpose(Matrix A) {
    Matrix T = init_matrix(A.cols, A.rows);
    for (size_t i = 0; i < A.cols; i++) {
        for (size_t j = 0; j < A.rows; ++j) {
            T.data[i][j] = A.data[j][i];
        }
    }
    T.rows = A.cols;
    T.cols = A.rows;
    return T;
}
#pragma clang diagnostic pop

//------------------------ Matrix Addition ------------------------//
Matrix mat_add(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        perror("MAT_ADD_ERROR --> MATRIX DIMENSIONS MUST MATCH");
        exit(EXIT_FAILURE);
    }
    Matrix M = init_matrix(A.rows, B.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            M.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return M;
}

//------------------------- Matrix Subtraction --------------------------//
Matrix mat_sub(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        perror("MAT_SUB_ERROR --> MATRIX DIMENSIONS MUST MATCH");
        exit(EXIT_FAILURE);
    }
    Matrix M = init_matrix(A.rows, B.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            M.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return M;
}

//---------------------- Matrix Multiplication ---------------------//
Matrix mat_mul(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        perror("MAT_MUL_ERROR --> INCORRECT DIMENSION");
        exit(EXIT_FAILURE);
    }
    Matrix M = init_matrix(A.rows, B.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            for(size_t k = 0; k < B.rows; k++) {
                M.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return M;
}

//---------------------- Matrix Elementwise Multiplication ---------------------//
Matrix mat_dot(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        perror("MAT_SUB_ERROR --> MATRIX DIMENSIONS MUST MATCH");
        exit(EXIT_FAILURE);
    }
    Matrix M = init_matrix(A.rows, B.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            M.data[i][j] = A.data[i][j] * B.data[i][j];
        }
    }
    return M;
}

//---------------------- Matrix Power ---------------------//
Matrix power(Matrix A, double n) {
    Matrix P = init_matrix(A.rows, A.cols);
    for (size_t i = 0; i < A.rows; i++) {
        for (size_t j = 0; j < A.cols; ++j) {
            P.data[i][j] = pow(A.data[i][j], n);
        }
    }
    return P;
}

//---------------------- Matrix Shuffle -------------------//
Matrix shuffle(Matrix X) {
    for (size_t i = 0; i < X.rows; i++) {
        for (size_t j = 0; j < X.cols; ++j) {
            size_t r = i + rand() / (RAND_MAX / (X.rows - i) + 1);

        }
    }
}