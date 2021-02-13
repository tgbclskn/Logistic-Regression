#include "logistic.h"

static void init_weights(LogisticRegression lr, size_t num_features) {
    lr.W = zeros(num_features, 1);
    lr.b = zeros(1, 1);
}

void fit(LogisticRegression lr, Matrix X, Matrix y) {
    size_t num_features = X.cols;
    init_weights(lr, num_features);


}