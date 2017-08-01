#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "contentful.h"
#include "imgur.h"
#include "mediathings.h"

class T_VIEW_EXPORT layouts_default_layoutView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  layouts_default_layoutView() : TActionView() { }
  QString toString();
};

QString layouts_default_layoutView::toString()
{
  responsebody.reserve(1154);
  responsebody += QLatin1String("<html>\n    <head>\n        <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n        <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">\n        <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css\" integrity=\"sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp\" crossorigin=\"anonymous\">\n    </head>\n    <body>\n        <div class=\"container\">\n            ");
  echo(yield());
  responsebody += QLatin1String("\n        </div>\n        <script \nsrc=\"http://code.jquery.com/jquery-3.2.1.min.js\"\nintegrity=\"sha256-hwg4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4=\"\ncrossorigin=\"anonymous\"></script>\n        <script \nsrc=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"\nintegrity=\"sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa\"\ncrossorigin=\"anonymous\"></script>\n    </body>\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(layouts_default_layoutView)

#include "layouts_default_layoutView.moc"
