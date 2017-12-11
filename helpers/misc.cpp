#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

#include "misc.h"

Misc::Misc() : ApplicationHelper()
{ }

QJsonObject Misc::jsonFromRequest(const QNetworkRequest & request)
{
    QByteArray ba = dataFromRequest(request);
    QJsonObject output;
    if (ba.isEmpty())
    {
        // output["error"] = reply->errorString();
    }
    else
    {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(ba);
        output = jsonResponse.object();
    }

    return output;
}

QByteArray Misc::dataFromRequest(const QNetworkRequest & request)
{
    QNetworkAccessManager nam;
    QEventLoop namLoop;
    QObject::connect(&nam, SIGNAL(finished(QNetworkReply*)), &namLoop, SLOT(quit()));

    QNetworkReply * reply = nam.get(request);
    namLoop.exec();

    QByteArray output;
    if (reply->error() == QNetworkReply::NoError)
    {
        output = reply->readAll();
    }
    delete reply;

    return output;
}
