#ifndef LOGISTICREGRESSION_LOGISTIC_H
#define LOGISTICREGRESSION_LOGISTIC_H

#include "../numerical/matrix.h"

typedef struct Regression {
    Matrix W;
    Matrix b;
    double learning_rate;
} LogisticRegression;

#endif //LOGISTICREGRESSION_LOGISTIC_H
