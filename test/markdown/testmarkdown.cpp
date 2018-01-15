#include <TfTest/TfTest>

#include "helpers/markdown.h"

class TestMarkdown : public QObject
{
    Q_OBJECT
private slots:
    void html1();
    void html2();
};

void TestMarkdown::html1()
{
    QString expected = "<h1>hello</h1>\n";
    QCOMPARE(expected, Markdown::html("# hello"));
}

void TestMarkdown::html2()
{
  QString expected = "<p>hello!</p>\n";
  QCOMPARE(expected, Markdown::html("hello!"));
}


TF_TEST_MAIN(TestMarkdown);
#include "testmarkdown.moc"