#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "contentful.h"
#include "imgur.h"
#include "mediathings.h"

class T_VIEW_EXPORT home_indexView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  home_indexView() : TActionView() { }
  QString toString();
};

QString home_indexView::toString()
{
  responsebody.reserve(122);
  responsebody += QLatin1String("<html>\n <head>\n  <title>Vuong Ideas</title>\n </head>\n <body>\n </body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(home_indexView)

#include "home_indexView.moc"
