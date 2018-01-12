#ifndef MARKDOWN_H
#define MARKDOWN_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Markdown : public ApplicationHelper
{
public:
    Markdown();
    QString html(const char* input);
    QString html(QString input);
    
};

#endif // MARKDOWN_H
