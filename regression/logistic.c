#include "logistic.h"

Model fit(LogisticRegression lr, Matrix X, Matrix y) {

    printf("\n================ Logistic Regression ===============\n");
    printf("    - learning rate           : %lf\n", lr.learning_rate);
    printf("    - number of iterations    : %zu\n\n", lr.iterations);

    size_t m = X.rows;
    size_t num_features = X.cols;

    Matrix W = zeros(num_features, 1);
    Matrix b = zeros(1, 1);

    StandardScaler ss = fit_and_scale(X);

    for (size_t i = 0; i < lr.iterations; i++) {
        Matrix Z = mat_mul(X, W);
        Matrix A = sigmoid(Z);
        Matrix E = mat_sub(A, y);

        Matrix Temp1 = mat_dot(y, mat_log(A));
        Matrix Temp2 = mat_dot(sub_from_scalar(1, y), mat_log(sub_from_scalar(1, A)));
        double cost = - sum(mat_add(Temp1, Temp2)) / m;

        Matrix dW = scalar_divide(mat_mul(transpose(X), E), m);
        Matrix dB = zeros(1, 1);
        double temp = sum(mat_sub(A, y)) / m;
        dB.data[0][0] = temp;

        W = mat_sub(W, scalar_multiply(dW, lr.learning_rate));
        b = mat_sub(b, scalar_multiply(dB, lr.learning_rate));

        printf("  [ %*zu ] training model... cost ---> | %*lf |\n", 3, i, 7, cost);

        dispose(Z);
        dispose(A);
        dispose(E);
        dispose(Temp1);
        dispose(Temp2);
        dispose(dW);
        dispose(dB);
    }

    printf("\n================= Training Complete ================\n");
    printf("final weights and biases...\n");

    print_matrix(W);
    print_matrix(b);

    Model model = {ss, W, b};
    return model;
}

Matrix predict(Model model, Matrix X) {
    printf("making predictions on the test set...\n");
    Matrix Y = zeros(X.rows, 1);
    scale(model.ss, X);
    Matrix Z = mat_mul(X, model.W);
    Matrix A = sigmoid(Z);

    for (size_t i = 0; i < A.rows; i++) {
        if (A.data[i][0] >= 0.5) {
            Y.data[i][0] = 1;
        } else {
            Y.data[i][0] = 0;
        }
    }

    return Y;
}

double get_accuracy(Matrix Y, Matrix Y_hat) {
    printf("calculating the model accuracy...");
    size_t m = Y.rows;
    int sum = 0;
    for (size_t i = 0; i < m; i++) {
        if (Y.data[i][0] == Y_hat.data[i][0]) {
            sum++;
        }
    }
    double accuracy = ((double) sum) / m;

    printf("\n    =================================\n");
    printf("    || Accuracy     || %*lf ||\n", 11, accuracy);
    printf("    =================================\n");

    return accuracy;
}