#ifndef STATISTICS_H
#define STATISTICS_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Statistics : public ApplicationHelper
{
public:
    Statistics();

    // Mean and Standard Deviation
    double mean(QList<double> data);
    double sum(QList<double> data);
    double standardDeviation(QList<double> data);
private:
    double sumOfSquares(QList<double> data);
};

#endif // STATISTICS_H
