#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "contentful.h"
#include "imgur.h"
#include "mediathings.h"

class T_VIEW_EXPORT testing_imagesView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  testing_imagesView() : TActionView() { }
  QString toString();
};

QString testing_imagesView::toString()
{
  responsebody.reserve(359);
  responsebody += QLatin1String("<div class=\"row-fluid\">\n    ");
  tfetch(QList<QString>, links);
foreach (auto & l, links) {
  responsebody += QLatin1String("<div class=\"col-md-1\">\n        <img width=\"100px\" height=\"100px\" ");
  echo(a("src", l));
  responsebody += QLatin1String(" />\n    </div>");
  };
  responsebody += QLatin1String("</div>");

  return responsebody;
}

T_DEFINE_VIEW(testing_imagesView)

#include "testing_imagesView.moc"
