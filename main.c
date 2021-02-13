#include <stdio.h>
#include "numerical/matrix.h"
#include "util/printer.h"
#include "preprocessing/load.h"
#include "preprocessing/split.h"
#include "regression/logistic.h"
#include <stdlib.h>

int main() {

//    Iris IrisDataset = load_iris("../dataset/Iris.csv");
//    Matrix X = IrisDataset.X;
//    Matrix y = IrisDataset.y;
//
//    TrainTestSplit tts = split_train_test(X, y, 0.2F);
//
//    Matrix TrainX = tts.TrainX;
//    Matrix TestX = tts.TestX;

    double x[][2] = {{1, 3}, {2, 4}, {-1, -3.2}};
    Matrix X = create_matrix(3, 2, *x);
    double y[][1] = {{1}, {0}, {1}};
    Matrix Y = create_matrix(3, 1, *y);
    double w[][1] = {{0}, {0}};
    Matrix W = create_matrix(2, 1, *w);
    Matrix Z = mat_mul(X, W);
    Matrix A = sigmoid(Z);
    Matrix E = mat_sub(A, Y);
//    print_matrix(E);

    LogisticRegression lr = {
            0.009, 100
    };

    fit(lr, X, Y);

    return 0;
}
