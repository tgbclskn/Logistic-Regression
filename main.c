#include <stdio.h>
#include "util/numc.h"



int main() {
    Matrix X = zeros(3, 3);
    printf("%p\n", &X.data[0][0]);
    return 0;
}
