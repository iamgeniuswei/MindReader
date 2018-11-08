#include <QtTest>
#include <QCoreApplication>
#include "articledisplayercontroller.h"
// add necessary includes here
#include <QPushButton>
class TestMRADC : public QObject
{
    Q_OBJECT

public:
    TestMRADC();
    ~TestMRADC();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case_getPageChecked();
    void test_case_getPageBreakChecked();

private:
    ArticleDisplayerController *p = nullptr;

};

TestMRADC::TestMRADC()
{

}

TestMRADC::~TestMRADC()
{

}

void TestMRADC::initTestCase()
{
    p = new ArticleDisplayerController;
}

void TestMRADC::cleanupTestCase()
{
    if(p)
        delete p;

}

void TestMRADC::test_case_getPageChecked()
{
    QTest::mouseClick (p->getPage (), Qt::LeftButton);
    QCOMPARE (p->getPage ()->isChecked (), true);
    QCOMPARE (p->getPageBreak ()->isChecked (), false);

}

void TestMRADC::test_case_getPageBreakChecked()
{
    QTest::mouseClick (p->getPageBreak (), Qt::LeftButton);
    QCOMPARE (p->getPage ()->isChecked (), false);
    QCOMPARE (p->getPageBreak ()->isChecked (), true);
}

QTEST_MAIN(TestMRADC)

#include "tst_testmradc.moc"
