#ifndef MEDIATHINGS_H
#define MEDIATHINGS_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Mediathings : public ApplicationHelper
{
public:
    Mediathings();
    QList<QString> linksFromImgur(QString q);
};

#endif // MEDIATHINGS_H
