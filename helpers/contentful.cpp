#include "contentful.h"

Contentful::Contentful(const char* spaceId, const char* accessToken) : ApplicationHelper()
{
    this->spaceId = QString::fromUtf8(spaceId);
    this->accessToken = QString::fromUtf8(accessToken);
}

const QByteArray & Contentful::getAsset(const char* assetId)
{
    //QString url = QString("https://cdn.contentful.com").arg();
    return 0;
}
