#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HomeController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    HomeController() : ApplicationController() { }

public slots:
    void index();
};

#endif // HOMECONTROLLER_H
