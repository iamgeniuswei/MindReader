#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class Page : public QObject
{
    Q_OBJECT

public:
    Page();
    ~Page();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

Page::Page()
{

}

Page::~Page()
{

}

void Page::initTestCase()
{

}

void Page::cleanupTestCase()
{

}

void Page::test_case1()
{

}

QTEST_MAIN(Page)

#include "tst_page.moc"
