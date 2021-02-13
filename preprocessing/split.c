#include "split.h"

TrainTestSplit split_train_test(Matrix X, Matrix y, float test_percentage) {
    float length = (float) X.rows;
    int train_length = (int) (length * (1 - test_percentage));
    int test_length = (int) (length * (1 - test_percentage));

}