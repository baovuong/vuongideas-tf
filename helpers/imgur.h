#ifndef IMGUR_H
#define IMGUR_H

#include <TGlobal>

#include <QJsonObject>
#include <QNetworkRequest>
#include <QUrl>

#include "applicationhelper.h"

class T_HELPER_EXPORT Imgur : public ApplicationHelper
{
public:
    Imgur(QString clientId);
    ~Imgur();
    
    QJsonObject image(const char* imageHash);
    QJsonObject gallerySearch(const char* q, const char* sort = "time", const char* window = "all", int page = 1);
    QJsonObject albumImages(const QString & albumHash);

private:
    QString clientId;
    QUrl* baseUrl;

    void setClientId(QNetworkRequest &);
};

#endif // IMGUR_H
