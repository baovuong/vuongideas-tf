#ifndef CONTENTFUL_H
#define CONTENTFUL_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Contentful : public ApplicationHelper
{
public:
    Contentful(const char* spaceId, const char* accessToken);
    const QByteArray & getAsset(const char* assetId);
    QVector<const QByteArray&> getAssets(); 
private:
    const QString spaceId;
    const QString accessToken;
};

#endif // CONTENTFUL_H
