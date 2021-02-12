#include <stdio.h>
#include "util/numc.h"
#include "util/printer.h"



int main() {
//    Matrix X = zeros(3, 3);
//    print_matrix(X);

    double a[][3] = {{1, 2, 3}};
    double b[][1] = {{1}, {2}, {3}};
    Matrix A = create_matrix(1, 3, *a);
    Matrix B = create_matrix(3, 1, *b);
    print_matrix(A);
    print_matrix(B);

    Matrix M = mat_mul(A, B);
    print_matrix(M);

    return 0;
}
