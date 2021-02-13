#include <stdio.h>
#include "numerical/matrix.h"
#include "util/printer.h"
#include "preprocessing/load.h"
#include <stdlib.h>

//static void shuffle(double *array, size_t n) {
//    if (n > 1) {
//        size_t i;
//        for (i = 0; i < n - 1; i++) {
//            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
//            double t = array[j];
//            array[j] = array[i];
//            array[i] = t;
//        }
//    }
//}

int main() {

//    Iris IrisDataset = load_iris("../dataset/Iris.csv");
//    Matrix X = IrisDataset.X;
//    Matrix y = IrisDataset.y;
//
//    print_matrix(X);

    double a[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Matrix A = create_matrix(4, 2, *a);
    print_matrix(A);

    shuffle(A);
    print_matrix(A);

//    printf("%lf", **(A.data + 1));

    return 0;
}
