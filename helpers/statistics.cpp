#include <QtMath>
#include <QTime>
#include <QtGlobal>

#include <cstdlib>

#include "statistics.h"

bool Statistics::executed = false;

Statistics::Statistics() : ApplicationHelper()
{
    Statistics::executeGlobal();
}

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

QList<double> Statistics::digitalNoise(int size)
{
    QList<double> output;
    double r1;
    double r2;
    for (int i=0; i<size; i++) {
        r1 = (double)qrand() / RAND_MAX;
        r2 = (double)qrand() / RAND_MAX;
        output.append(qSqrt(-2 * qLn(r1)/qLn(10)) * qCos(2*M_PI*r2));
       // output.append(RAND_MAX);
    }
    return output;
}

void Statistics::executeGlobal()
{
    if (Statistics::executed)
        return;
    
    // do the things
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    Statistics::executed = true;
}