#include <stdio.h>
#include "numerical/matrix.h"
#include "util/printer.h"
#include "preprocessing/load.h"
#include <stdlib.h>

int main() {

    Iris IrisDataset = load_iris("../dataset/Iris.csv");
    Matrix X = IrisDataset.X;
    Matrix y = IrisDataset.y;

    print_matrix(y);

//    double a[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
//    Matrix A = create_matrix(4, 2, *a);
//    print_matrix(A);
//
//    shuffle(A);
//    print_matrix(A);

    return 0;
}
