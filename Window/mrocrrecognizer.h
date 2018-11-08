#ifndef MROCRRECOGNIZER_H
#define MROCRRECOGNIZER_H

#include <QThread>
#include <memory>
#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "fifotsqueue.h"
using namespace tesseract;
/**
 * @brief The MROCRRecognizer class
 * MROCRRecognizer 在线程中调用tesseract自动识别图像中的文字，并返回至主线程
 */
class MROCRRecognizer : public QThread
{
    Q_OBJECT
public:
    explicit MROCRRecognizer(QObject *parent = nullptr);
    ~MROCRRecognizer();

    void addPendingPix(const QPixmap &pix);
    Pix* getPix();

protected:
    void run() override;

signals:

public slots:

private:
    std::unique_ptr<TessBaseAPI> tess = nullptr;
    FIFOTSQueue<Pix*> pendingPixs;

};

#endif // MROCRRECOGNIZER_H
