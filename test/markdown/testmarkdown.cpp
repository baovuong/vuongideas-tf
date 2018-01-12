#include <TfTest/TfTest>

class TestMarkdown : public QObject
{
    Q_OBJECT
private slots:
    void check();
};

void TestMarkdown::check()
{
    int thing = 123;
    QCOMPARE(thing, 123);
}

TF_TEST_MAIN(TestMarkdown);
#include "testmarkdown.moc"