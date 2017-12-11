#ifndef MISC_H
#define MISC_H

#include <TGlobal>
#include <QNetworkRequest>
#include <QJsonObject>

#include "applicationhelper.h"

class T_HELPER_EXPORT Misc : public ApplicationHelper
{
public:
    Misc();
    static QByteArray dataFromRequest(const QNetworkRequest & request);
    static QJsonObject jsonFromRequest(const QNetworkRequest & request);
};

#endif // MISC_H
