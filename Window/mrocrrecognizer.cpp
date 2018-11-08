#include "mrocrrecognizer.h"
#include <QDebug>
#include <QPixmap>
#include <QDateTime>
MROCRRecognizer::MROCRRecognizer(QObject *parent) : QThread(parent)
{


}

MROCRRecognizer::~MROCRRecognizer()
{
    Q_ASSERT (tess);
    tess->End ();
}

void MROCRRecognizer::addPendingPix(const QPixmap &pix)
{
    if(pix.isNull ())
        return;
    QString filePathName = "D:/Article/";

    filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-zzz");
    filePathName += ".png";
    pix.save (filePathName);
    Pix *p = pixRead (filePathName.toLocal8Bit ().data ());
    pendingPixs.push (p);
}


Pix *MROCRRecognizer::getPix()
{
    Pix *pix = pendingPixs.wait_and_pop ();
    return  pix;
}

void MROCRRecognizer::run()
{
    tess = std::make_unique<TessBaseAPI>();
    Q_ASSERT (tess);
    if (tess->Init(NULL, "eng+chi_sim"))
    {
//            fprintf(stderr, "Could not initialize tesseract.\n");
        qDebug() << "Could not initialize tesseract.";
//            exit(1);
    }
    tess->SetPageSegMode (tesseract::PSM_AUTO);
    while (true)
    {
        try
        {
            Pix *pix = getPix ();
            if(pix == nullptr)
                continue;
            tess->SetImage (pix);
            qDebug() << "start ocr...";
            char *out = tess->GetUTF8Text ();
            qDebug() << out;
            qDebug() << "end ocr...";
            delete [] out;
        }
        catch (std::exception &e)
        {
            qDebug() << e.what ();
        }
    }
}
