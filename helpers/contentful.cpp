#include "contentful.h"

Contentful::Contentful(const char* spaceId, const char* accessToken) : ApplicationHelper()
{
    this->accessToken = QString::fromUtf8(accessToken);
    this->baseUrl = new QUrl(QString("https://cdn.contentful.com/spaces/%1/")
                             .arg(QString::fromUtf8(spaceId)));
}

Contentful::~Contentful() 
{
    delete this->baseUrl;
}


// ContentfulModel
ContentfulModel::ContentfulModel(QJsonObject json)
{
    // parse through values, and assign them
    QJsonValue fields = json.take("fields");
    if (fields.isUndefined() || !fields.isObject()) {
        // nothing here, 
        return;
    }
    
    JsonObject fieldsObj = fields.toObject();
    values = new QVariantMap();
    *values = fieldsObj.toVariantMap();
}

ContentfulModel:~ContentfulModel()
{
    delete values;
}


