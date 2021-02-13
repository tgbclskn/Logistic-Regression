#ifndef LOGISTICREGRESSION_LOGISTIC_H
#define LOGISTICREGRESSION_LOGISTIC_H

#include "../numerical/matrix.h"
#include "../util/printer.h"

typedef struct Regression {
    double learning_rate;
    size_t iterations;
} LogisticRegression;

void fit(LogisticRegression lr, Matrix X, Matrix y);

#endif //LOGISTICREGRESSION_LOGISTIC_H
