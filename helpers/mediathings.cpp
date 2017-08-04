#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QtConcurrent/QtConcurrent>

#include "imgur.h"
#include "mediathings.h"

QList<QString> fetchImages(const QJsonValue &result)
{
    QJsonObject obj = result.toObject();
    QList<QString> output;
    if (obj["is_album"].toBool())
    {
        QSettings settings("values.ini", QSettings::IniFormat);
        Imgur imgur(settings.value("AppSettings/imgurToken").value<QString>());
        QJsonObject album = imgur.albumImages(obj["id"].toString());
        QJsonArray albumImages = album["data"].toArray();
        foreach (const QJsonValue & image, albumImages)
        {
            output.append(image.toObject()["link"].toString());
        }
    }
    else
    {
        output.append(obj["link"].toString());
    }
    return output;
}

Mediathings::Mediathings() : ApplicationHelper()
{ }

QList<QString> Mediathings::linksFromImgur(QString q)
{
    QList<QString> output;
    QSettings settings("values.ini", QSettings::IniFormat);
    Imgur imgur(settings.value("AppSettings/imgurToken").value<QString>());
    QJsonObject object = imgur.gallerySearch(q.toUtf8());
    QJsonArray results = object["data"].toArray();
    QList<QJsonValue> results2;
    foreach (const QJsonValue & r, results) {
        results2.append(r);
    }
    QList<QList<QString>> futureResults = QtConcurrent::blockingMapped(results2, fetchImages);

    foreach (QList<QString> r, futureResults)
    {
        output.append(r);
    }
    
    return output;
}