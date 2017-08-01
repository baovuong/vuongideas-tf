#include <QJsonObject>
#include <QJsonValue>
#include <QtConcurrent/QtConcurrent>
#include <QSettings>

#include "imagecontroller.h"
#include "imgur.h"

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

void ImageController::fetch()
{
    // write code
    QSettings settings("values.ini", QSettings::IniFormat);
    Imgur imgur(settings.value("AppSettings/imgurToken").value<QString>());
    QJsonObject object = imgur.gallerySearch("cats");
    QJsonArray results = object["data"].toArray();
    QList<QJsonValue> results2;
    foreach (const QJsonValue & r, results)
    {
        results2.append(r);
    }

    auto futureResults = QtConcurrent::blockingMapped(results2, fetchImages);

    QList<QString> output;
    foreach (QList<QString> r, futureResults)
    {
        output.append(r);
    }

    renderJson(output);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ImageController)
