#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

#include "imgur.h"


// helper things
// setting clientId
void Imgur::setClientId(QNetworkRequest & request)
{
    request.setRawHeader(QByteArray("authorizatio"), QString("Client-ID %1").arg(this->clientId).toUtf8());
}

const QJsonObject & jsonFromRequest(const QNetworkRequest & request)
{
    QEventLoop eventLoop;
    QNetworkAccessManager nam;
    QObject::connect(&nam, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkReply * reply = nam.get(request);
    eventLoop.exec(); 
    QJsonObject output;
    if (reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
        output = jsonResponse.object();
    }
    delete reply;
    
    return output;
}


Imgur::Imgur(const char* clientId) : ApplicationHelper()
{
    this->clientId = QString::fromUtf8(clientId);
    this->baseUrl = new QUrl("https://api.imgur.com/3/");
}

Imgur::~Imgur()
{
    delete this->baseUrl;
}

const QJsonObject & Imgur::image(const char* imageHash)
{
    QNetworkRequest request(this->baseUrl->resolved(QString("image/%1").arg(imageHash)));
    setClientId(request);
    return jsonFromRequest(request);
}

const QJsonObject & Imgur::gallerySearch(const char* q, const char* sort = "time", const char* window = "all", int page = 1)
{
    QNetworkRequest request(this->baseUrl->resolved(QString("gallery/search/%1/%2/%3?q=%4")
                                                  .arg(sort)
                                                  .arg(window)
                                                  .arg(page)
                                                  .arg(q)));
    setClientId(request);
    return jsonFromRequest(request);
}

