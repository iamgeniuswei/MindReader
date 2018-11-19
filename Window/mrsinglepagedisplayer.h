#ifndef MRSINGLEPAGEDISPLAYER_H
#define MRSINGLEPAGEDISPLAYER_H

#include "mrarticlecanvas.h"
#include "mrarticlepagedisplayer.h"
class MRSinglePageDisplayer : public MRArticleCanvas
{
    Q_OBJECT
public:
    explicit MRSinglePageDisplayer(QWidget *parent = nullptr);
protected:
    virtual void loadUI();
    virtual void loadSignals();
signals:

public slots:
    virtual void handleDocReady(bool ret, std::shared_ptr<MRDocument> document);
    virtual void firstPage();
    virtual void prevPage();
    virtual void nextPage();
    virtual void lastPage();
    virtual void zoomInPage();
    virtual void zoomOutPage();
    virtual void displayPage(float scaleX,
                     float scaleY,
                     float rotation,
                     int index,
                     QImage img,
                     std::shared_ptr<MRPage> src);
private:
    MRArticlePageDisplayer *page = nullptr;
};

#endif // MRSINGLEPAGEDISPLAYER_H
