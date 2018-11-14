#ifndef MRARTICLEPAGEDISPLAYER_P_H
#define MRARTICLEPAGEDISPLAYER_P_H
#include <QPoint>
#include <QList>
#include <QColor>
#include <memory>
#include "mrwindowutility.h"
#include "PDFUtil.h"
class MRPage;
class MRDocument;
class MRAnnotation;
class ArticlePageRender;
class MROCRRecognizer;
class MRArticlePageDisplayerPrivate
{
public:
    MRArticlePageDisplayerPrivate()
    {}

public:
    QPoint mouseStartPoint;
    QPoint mouseEndPoint;
    std::shared_ptr<MRPage> page = nullptr;
    int pageIndex = 0;
    float scaleX = 1.0;
    float scaleY = 1.0;
    float rotation = 0.0;
    volatile bool isDrawFollowMouse = false;
    QList<std::shared_ptr<MRAnnotation>> annotsOnDraw;
    QList<SPtrMRA> annotsInPage;
    CURSOR cursor_;
    int annotFlag;
    bool isShiftDown = false;
    ArticlePageRender *render = nullptr;
    MROCRRecognizer *ocr = nullptr;
    std::shared_ptr<MRDocument> doc = nullptr;
    QSize pageSize;
    QColor curColor{Qt::green};
};

#endif // MRARTICLEPAGEDISPLAYER_P_H
