#include <TfTest/TfTest>

#include "helpers/markdown.h"

class TestMarkdown : public QObject
{
    Q_OBJECT
private slots:
    void html1();
};

void TestMarkdown::html1()
{
    Markdown markdown;
    QString expected = "<h1>hello</h1>";
    QCOMPARE(expected, markdown.html("# hello"));
}

TF_TEST_MAIN(TestMarkdown);
//#include "testmarkdown.moc"