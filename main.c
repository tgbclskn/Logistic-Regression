#include <stdio.h>
#include "numerical/matrix.h"
#include "util/printer.h"
#include "preprocessing/load.h"
#include <stdlib.h>

int main() {

    Iris IrisDataset = load_iris("../dataset/Iris.csv");
    Matrix X = IrisDataset.X;
    Matrix y = IrisDataset.y;

    print_matrix(X);

    return 0;
}
