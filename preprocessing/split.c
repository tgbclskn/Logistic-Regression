#include "split.h"

static void shuffle(double *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            double t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

TrainTestSplit split_train_test(Matrix X, Matrix y, float test_percentage) {
    float length = (float) X.rows;
    int train_length = (int) (length * (1 - test_percentage));
    int test_length = (int) (length * (1 - test_percentage));

    shuffle(*X.data, X.rows);

}