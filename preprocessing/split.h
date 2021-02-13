#ifndef LOGISTICREGRESSION_SPLIT_H
#define LOGISTICREGRESSION_SPLIT_H

#include "../numerical/matrix.h"

typedef struct Split {
    Matrix TrainX;
    Matrix TrainY;
    Matrix TestX;
    Matrix TestY;
} TrainTestSplit;

#endif //LOGISTICREGRESSION_SPLIT_H
