#include <QtTest>
#include <QCoreApplication>
#include "mrdocument.h"
#include "mrpage.h"
#include "mupdf/pdf.h"
// add necessary includes here

class PDFPageTest : public QObject
{
    Q_OBJECT

public:
    PDFPageTest();
    ~PDFPageTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case_addAnnotation();
    void test_case_addAnnotation2();
    void test_case_getAnnotations();
    void test_case_openDocument();

private:
    MRDocument *document = nullptr;

};

PDFPageTest::PDFPageTest()
{

}

PDFPageTest::~PDFPageTest()
{

}

void PDFPageTest::initTestCase()
{
    document = new MRDocument();
}

void PDFPageTest::cleanupTestCase()
{
    if(document)
        delete document;
}

void PDFPageTest::test_case_addAnnotation()
{
//    bool ret = document->openDocument ("D:/Article/56.pdf");
//    QCOMPARE (ret, true);
//    PDFPage *page = document->page (0);
//    Q_ASSERT (page);
//    QVERIFY (page != nullptr );
//    fz_rect rect;
//    rect.x0 = 100;
//    rect.y0 = 100;
//    rect.x1 = 200;
//    rect.y1 = 200;
//    qDebug() << page;
//    page->addAnnotation (PDF_ANNOT_SQUARE,
//                         rect,
//                         QString());

//    fz_annot *annot = fz_first_annot (page->context (), page->page ());
//    if(annot)
//    {
//        pdf_annot *pdf_an = (pdf_annot*)annot;
//        QVERIFY (pdf_an != nullptr );
//        fz_rect r = pdf_annot_rect(page->context (),
//                                   pdf_an);
//        int flag = pdf_annot_flags (page->context (),
//                                    pdf_an);
//        QVERIFY (flag == PDF_ANNOT_SQUARE);
//        QVERIFY (r.x0 == rect.x0);
//        QVERIFY (r.x1 == rect.x1);
//        QVERIFY (r.y0 == rect.y0);
//        QVERIFY (r.y1 == rect.y1);
//        qDebug() << flag;
//        qDebug() << r.y0 << " " << rect.y0;
//    }
}

void PDFPageTest::test_case_addAnnotation2()
{
//    bool ret = document->openDocument ("D:/Article/56.pdf");
//    QCOMPARE (ret, true);
//    PDFPage *page = document->page (0);
//    Q_ASSERT (page);
//    QVERIFY (page != nullptr );
//    fz_rect rect;
//    rect.x0 = 100;
//    rect.y0 = 100;
//    rect.x1 = 200;
//    rect.y1 = 200;
//    qDebug() << page;
//    page->addAnnotation (PDF_ANNOT_SQUARE,
//                         rect,
//                         QString());

//    fz_rect rect1;
//    rect1.x0 = 300;
//    rect1.y0 = 300;
//    rect1.x1 = 500;
//    rect1.y1 = 500;
//    page->addAnnotation (PDF_ANNOT_LINE,
//                         rect1,
//                         QString());

//    fz_annot *annot = fz_first_annot (page->context (), page->page ());
//    if(annot)
//    {
//        pdf_annot *pdf_an = (pdf_annot*)annot;
//        QVERIFY (pdf_an != nullptr );
//        fz_rect r = pdf_annot_rect(page->context (),
//                                   pdf_an);
//        int flag = pdf_annot_flags (page->context (),
//                                    pdf_an);
//        QVERIFY (flag == PDF_ANNOT_SQUARE);
//        QVERIFY (r.x0 == rect.x0);
//        QVERIFY (r.x1 == rect.x1);
//        QVERIFY (r.y0 == rect.y0);
//        QVERIFY (r.y1 == rect.y1);
//        qDebug() << flag;
//        qDebug() << r.y0 << " " << rect.y0;
//    }
//    fz_annot *annot1 = fz_next_annot (page->context (),
//                                      annot);
//    if(annot1)
//    {
//        pdf_annot *pdf_an = (pdf_annot*)annot1;
//        QVERIFY (pdf_an != nullptr );
//        fz_rect r = pdf_annot_rect(page->context (),
//                                   pdf_an);
//        int flag = pdf_annot_flags (page->context (),
//                                    pdf_an);
//        qDebug() << r.x0 << " " << rect1.x0;
//        QVERIFY (flag == PDF_ANNOT_SQUARE);
//        QVERIFY (r.x0 == rect1.x0);
//        QVERIFY (r.x1 == rect1.x1);
//        QVERIFY (r.y0 == rect1.y0);
//        QVERIFY (r.y1 == rect1.y1);
//        qDebug() << flag;
//        qDebug() << r.y0 << " " << rect1.y0;
//    }

//    fz_annot *annot2 = fz_next_annot (page->context (),
//                                      annot1);
//    qDebug() << annot2;
//    QVERIFY (annot2 == nullptr );
}

void PDFPageTest::test_case_getAnnotations()
{
    bool ret = document->openDocument ("D:/Article/56.pdf");
    QCOMPARE (ret, true);
    MRPage *page = document->page (0);
    Q_ASSERT (page);
    QVERIFY (page != nullptr );
    fz_rect rect;
    rect.x0 = 100;
    rect.y0 = 100;
    rect.x1 = 200;
    rect.y1 = 200;
    qDebug() << page;
    page->addAnnotation (PDF_ANNOT_SQUARE,
                         rect,
                         nullptr);

    fz_rect rect1;
    rect1.x0 = 300;
    rect1.y0 = 300;
    rect1.x1 = 500;
    rect1.y1 = 500;
    page->addAnnotation (PDF_ANNOT_LINE,
                         rect1,
                         nullptr);

    fz_rect rect2;
    rect2.x0 = 600;
    rect2.y0 = 600;
    rect2.x1 = 800;
    rect2.y1 = 800;
    page->addAnnotation (PDF_ANNOT_LINE,
                         rect1,
                         "THis is a Annotation");

    QList<MRAnnotation> annotations;
    page->getAnnotations (annotations);
    qDebug() << annotations.size ();
    QVERIFY (annotations.size () == 3);

//    fz_annot *annot = fz_first_annot (page->context (), page->page ());
//    if(annot)
//    {
//        pdf_annot *pdf_an = (pdf_annot*)annot;
//        QVERIFY (pdf_an != nullptr );
//        fz_rect r = pdf_annot_rect(page->context (),
//                                   pdf_an);
//        int flag = pdf_annot_flags (page->context (),
//                                    pdf_an);
//        QVERIFY (flag == PDF_ANNOT_SQUARE);
//        QVERIFY (r.x0 == rect.x0);
//        QVERIFY (r.x1 == rect.x1);
//        QVERIFY (r.y0 == rect.y0);
//        QVERIFY (r.y1 == rect.y1);
//        qDebug() << flag;
//        qDebug() << r.y0 << " " << rect.y0;
//    }
//    fz_annot *annot1 = fz_next_annot (page->context (),
//                                      annot);
//    if(annot1)
//    {
//        pdf_annot *pdf_an = (pdf_annot*)annot1;
//        QVERIFY (pdf_an != nullptr );
//        fz_rect r = pdf_annot_rect(page->context (),
//                                   pdf_an);
//        int flag = pdf_annot_flags (page->context (),
//                                    pdf_an);
//        qDebug() << r.x0 << " " << rect1.x0;
//        QVERIFY (flag == PDF_ANNOT_SQUARE);
//        QVERIFY (r.x0 == rect1.x0);
//        QVERIFY (r.x1 == rect1.x1);
//        QVERIFY (r.y0 == rect1.y0);
//        QVERIFY (r.y1 == rect1.y1);
//        qDebug() << flag;
//        qDebug() << r.y0 << " " << rect1.y0;
//    }

//    fz_annot *annot2 = fz_next_annot (page->context (),
//                                      annot1);
//    qDebug() << annot2;
//    QVERIFY (annot2 == nullptr );
}

void PDFPageTest::test_case_openDocument()
{
//    bool ret = document->openDocument ("D:/Article/56.pdf");
//    QCOMPARE (ret, true);
//    QVERIFY (document->context () != nullptr);
//    QVERIFY (document->document () != nullptr);
//    QCOMPARE (document->pageCount (), 1);
}

QTEST_MAIN(PDFPageTest)

#include "tst_pdfpagetest.moc"
