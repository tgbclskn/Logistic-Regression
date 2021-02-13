#include "logistic.h"

Model fit(LogisticRegression lr, Matrix X, Matrix y) {
    size_t m = X.rows;
    size_t num_features = X.cols;

    Matrix W = zeros(num_features, 1);
    Matrix b = zeros(1, 1);

    StandardScaler ss = fit_and_scale(X);

    for (size_t i = 0; i < lr.iterations; i++) {
        Matrix Z = mat_mul(X, W);
        Matrix A = sigmoid(Z);
        Matrix E = mat_sub(A, y);

        Matrix dW = divide(mat_mul(transpose(X), E), m);
        Matrix dB = zeros(1, 1);
        double temp = sum(mat_sub(A, y)) / m;
        dB.data[0][0] = temp;

        W = mat_sub(W, multiply(dW, lr.learning_rate));
        b = mat_sub(b, multiply(dB, lr.learning_rate));

        dispose(Z);
        dispose(A);
        dispose(E);
        dispose(dW);
        dispose(dB);
    }

    print_matrix(W);
    print_matrix(b);

    Model model = {ss, W, b};
    return model;
}

Matrix predict(Model model, Matrix X) {
    Matrix Y = zeros(X.rows, 1);
    scale(model.ss, X);
    Matrix Z = mat_mul(X, model.W);
    Matrix A = sigmoid(Z);

    for (size_t i = 0; i < X.rows; i++) {
        if (A.data[i][0] >= 0.5) {
            Y.data[i][0] = 1;
        } else {
            Y.data[i][0] = 0;
        }
    }
    return Y;
}

double get_accuracy(Matrix Y, Matrix Y_hat) {
    size_t m = Y.rows;
    int sum = 0;
    for (size_t i = 0; i < m; i++) {
        if (Y.data[i][0] == Y_hat.data[i][0]) {
            sum++;
        }
    }
    double accuracy = ((double) sum) / m;
    return accuracy;
}