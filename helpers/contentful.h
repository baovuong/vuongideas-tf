#ifndef CONTENTFUL_H
#define CONTENTFUL_H

#include <TGlobal>
#include "applicationhelper.h"

class T_HELPER_EXPORT Contentful : public ApplicationHelper
{
public:
    Contentful(const char* spaceId, const char* accessToken);
    ~Contentful();
    
    // Resume
    ContentfulResume getResume(const char* id);
    QList<ContentfulResume> getResumes();
    
    // Resume Experience
    ContentfulResumeExperience getResumeExperience(const char* id);
    QList<ContentfulResumeExperience> getResumeExperiences();
    QList<ContentfulResumeExperience> getResumeExperiencesByResumeId(const char* resumeId);
    
private:
    QUrl* baseUrl;
    QString accessToken;
    
    // helper methods
    const QJsonObject getEntry(const char* entryId);
    const QList<QJsonObject> getEntries();
    const QByteArray & getAsset(const char* assetId);
    QVector<const QByteArray&> getAssets();
    
    
};


// models
class ContentfulModel
{
  public:
  ContentfulModel(QJsonObject);
  ~ContentfulModel();
  private:
  QVariantMap values;
};

class ContentfulResume : public ContentfulModel
{
public:
    ContentfulResume(QJsonObject);
    ~ContentfulResume();
    
    const QString & getTitle();
    void setTitle(const QString &);
    
    const QString & getName();
    void setName(const QString &);
    
private:
    QString* title;
    QString* name;
    QString* emailAddress;
    QString* phoneNumber;
    QList<ContentfulResumeExperience>* experiences;
};

class ContentfulResumeExperience : public ContentfulModel
{
public:
    ContentfulResumeExperience(QJsonObject);
    ~ContentfulResumeExperience();
private:
    QString* company;
    QString* jobTitle;
    QDate* startDate;
    QDate* endDate;
    bool currentlyEmployed;
    QString* location;
    QString* tasks;
};

#endif // CONTENTFUL_H
