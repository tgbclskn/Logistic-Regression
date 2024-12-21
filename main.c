#include "numerical/matrix.h"
#include "preprocessing/load.h"
#include "preprocessing/split.h"
#include "regression/logistic.h"

int main() {
    Iris IrisDataset = load_iris("./dataset/Iris.csv");
    Matrix X = IrisDataset.X;
    Matrix y = IrisDataset.y;

    TrainTestSplit tts = split_train_test(X, y, 0.2F);

    Matrix TrainX = tts.TrainX;
    Matrix TestX = tts.TestX;
    Matrix TrainY = tts.TrainY;
    Matrix TestY = tts.TestY;

    dispose(X);
    dispose(y);

    LogisticRegression lr = {0.001, 1000000};
    Model trained_model = fit(lr, TrainX, TrainY);

    Matrix Y_hat = predict(trained_model, TestX);
    get_accuracy(TestY, Y_hat);

    return 0;
}
