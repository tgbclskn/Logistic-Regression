#include "logistic.h"

void fit(LogisticRegression lr, Matrix X, Matrix y) {
    size_t m = X.rows;
    size_t num_features = X.cols;

    Matrix W = zeros(num_features, 1);
    Matrix b = zeros(1, 1);

    for (size_t i = 0; i < lr.iterations; i++) {
        Matrix Z = mat_mul(X, W);
        Matrix A = sigmoid(Z);

        Matrix dW = divide(mat_mul(transpose(X), mat_sub(A, y)), m);
        Matrix dB = zeros(1, 1);
        double temp = sum(mat_sub(A, y)) / m;
        dB.data[0][0] = temp;

        print_matrix(dW);
        print_matrix(dB);

        W = mat_sub(W, multiply(dW, lr.learning_rate));
        b = mat_sub(b, multiply(dB, lr.learning_rate));

        dispose(Z);
        dispose(A);
        dispose(dW);
        dispose(dB);
    }
}