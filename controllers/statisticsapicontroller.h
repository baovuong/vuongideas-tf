#ifndef STATISTICSAPICONTROLLER_H
#define STATISTICSAPICONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT StatisticsApiController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    StatisticsApiController() : ApplicationController() { }

public slots:
    void mean();
    void standardDeviation();
    void histogram();
    void typical_error();
};

#endif // STATISTICSAPICONTROLLER_H
