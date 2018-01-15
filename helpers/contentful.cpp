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

const QByteArray & Contentful::getAsset(const char* assetId)
{
    //QString url = QString("https://cdn.contentful.com").arg();
    return 0;
}
