#include "scaler.h"

static void get_params(Matrix X, double *mean, double *std) {
    for (size_t i = 0; i < X.cols; i++) {
        double sum = 0;
        for (size_t j = 0; j < X.rows; j++) {
            sum += X.data[j][i];
        }
        mean[i] = sum / X.rows;
    }
    for (size_t i = 0; i < X.cols; i++) {
        double sum = 0;
        for (size_t j = 0; j < X.rows; j++) {
            sum += pow(X.data[j][i] - mean[i], 2);
        }
        std[i] = sqrt(sum / (double) X.rows);
    }
}

StandardScaler fit_and_scale(Matrix X) {
    double mean[X.cols];
    double std[X.cols];
    get_params(X, mean, std);

    for (size_t i = 0; i < X.cols; i++) {
        for (size_t j = 0; j < X.rows; j++) {
            X.data[j][i] = (X.data[j][i] - mean[i]) / std[i];
        }
    }

    StandardScaler ss = {mean, std};

    return ss;
}

void scale(StandardScaler ss, Matrix X) {
    for (size_t i = 0; i < X.cols; i++) {
        for (size_t j = 0; j < X.rows; j++) {
            X.data[j][i] = (X.data[j][i] - ss.mean[i]) / ss.std[i];
        }
    }
}