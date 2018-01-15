#ifndef CONTENTFUL_H
#define CONTENTFUL_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Contentful : public ApplicationHelper
{
public:
    Contentful(const char* spaceId, const char* accessToken);
    ~Contentful();
    const QJsonObject getEntry(const char* entryId);
    const QList<QJsonObject> getEntries();
    const QByteArray & getAsset(const char* assetId);
    QVector<const QByteArray&> getAssets(); 
    
private:
    QUrl* baseUrl;
    QString accessToken;
};


// models
class ContentfulModel
{
  public:
  ContentfulModel();
  ~ContentfulModel();
  private:
  Contentful* client;
};

class ContentfulResume : public ContentfulModel
{
public:
    ContentfulResume();
    ~ContentfulResume();
};

class ContentfulResumeExperience : public ContentfulModel
{
public:
    ContentfulResumeExperience();
    ~ContentfulResumeExperience();
};

#endif // CONTENTFUL_H
