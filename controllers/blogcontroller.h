#ifndef BLOGCONTROLLER_H
#define BLOGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT BlogController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    BlogController() { }
    BlogController(const BlogController &other);

public slots:
    void list();
    void read();
};

T_DECLARE_CONTROLLER(BlogController, blogcontroller)

#endif // BLOGCONTROLLER_H
