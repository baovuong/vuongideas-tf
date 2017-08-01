#include <QtMath>

#include "statistics.h"

Statistics::Statistics() : ApplicationHelper()
{ }


double Statistics::sum(QList<double> data)
{
    double s = 0;
    foreach (double entry, data)
    {
        s += entry;
    }
    return s;
}

double Statistics::mean(QList<double> data)
{
    return sum(data)/data.length();
}

double Statistics::sumOfSquares(QList<double> data)
{
    double sum = 0;
    foreach (double entry, data)
    {
        sum += entry * entry;
    }
    return sum;
}



double Statistics::standardDeviation(QList<double> data)
{
    double s = sum(data);
    double ss = sumOfSquares(data);
    int n = data.length();
    return qSqrt((ss - (s * s)/n)/(n-1));
}
