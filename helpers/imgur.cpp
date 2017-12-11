#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

#include "imgur.h"
#include "misc.h"


// helper things
// setting clientId
void Imgur::setClientId(QNetworkRequest & request)
{
    request.setRawHeader(QByteArray("authorization"), QString("Client-ID %1").arg(this->clientId).toUtf8());
}

Imgur::Imgur(QString clientId) : ApplicationHelper()
{
    this->clientId = clientId;
    this->baseUrl = new QUrl("https://api.imgur.com/3/");
}

Imgur::~Imgur()
{
    delete this->baseUrl;
}

QJsonObject Imgur::image(const char* imageHash)
{
    QNetworkRequest request(this->baseUrl->resolved(QString("image/%1").arg(imageHash)));
    setClientId(request);
    return Misc::jsonFromRequest(request);
}

QJsonObject Imgur::gallerySearch(const char* q, const char* sort, const char* window, int page)
{
    QNetworkRequest request(this->baseUrl->resolved(QString("gallery/search/%1/%2/%3?q=%4")
                                                  .arg(sort)
                                                  .arg(window)
                                                  .arg(page)
                                                  .arg(q)));
    setClientId(request);
    return Misc::jsonFromRequest(request);
}

QJsonObject Imgur::albumImages(const QString & albumHash)
{
    QNetworkRequest request(this->baseUrl->resolved(QString("album/%1/images").arg(albumHash)));
    setClientId(request);
    return Misc::jsonFromRequest(request);
}
