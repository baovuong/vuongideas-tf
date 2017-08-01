#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ImageController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    ImageController() : ApplicationController() 
    {
    }

public slots:
    void fetch();
};

#endif // IMAGECONTROLLER_H
