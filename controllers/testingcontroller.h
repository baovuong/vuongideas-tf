#ifndef TESTINGCONTROLLER_H
#define TESTINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TestingController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    TestingController() : ApplicationController() { }

public slots:
    void images();
};

#endif // TESTINGCONTROLLER_H
