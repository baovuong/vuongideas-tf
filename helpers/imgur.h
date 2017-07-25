#ifndef IMGUR_H
#define IMGUR_H

#include <TGlobal>

#include <QJsonObject>
#include <QUrl>

#include "applicationhelper.h"

class T_HELPER_EXPORT Imgur : public ApplicationHelper
{
public:
    Imgur(const char* clientId);
    ~Imgur();
    
    const QJsonObject & image(const char* imageHash);
    const QJsonObject & gallerySearch(const char* q, const char* sort, const char* window, int page);

private:
    QString clientId;
    QUrl* baseUrl;
};

#endif // IMGUR_H
