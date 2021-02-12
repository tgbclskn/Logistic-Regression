#include <stdio.h>
#include "util/numc.h"
#include "util/printer.h"



int main() {
    Matrix X = zeros(3, 3);
    print_matrix(X);

    double a[][3] = {{1, 2, 3}};
    Matrix B = create_matrix(1, 3, *a);
    print_matrix(B);

    double s = mean(B);
    printf("%lf\n", s);

    return 0;
}
