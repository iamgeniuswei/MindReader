/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArticlePage.h
 * Author: develop
 *
 * Created on October 12, 2018, 8:15 AM
 */

#ifndef _ARTICLEPAGE_H
#define _ARTICLEPAGE_H

#include <QLabel>
#include "window_global.h"
//#include "mupdf/fitz.h"
//#include "mupdf/pdf/annot.h"
#include "mupdf/fitz.h"
#include "mrwindowutility.h"
#include "mrannotation.h"
#include "mrdocument.h"
#include <memory>
class MRPage;
class ArticlePageRender;
class MRArticlePageDisplayerPrivate;
/**
 * @brief The MRArticlePageDisplayer class
 * MRArticlePageDisplayer 用于显示PDF文档中的具体一页，对PDF页面的任何操作均体现在\n
 * MRArticlePageDisplayer中，比如放大、缩小、注释、文本选择高亮等。
 */
class WINDOWSHARED_EXPORT MRArticlePageDisplayer : public QLabel
{
    enum STATE{READ, SELECTION};
    Q_OBJECT
public:
    MRArticlePageDisplayer(QWidget *parent = nullptr);
//    MRArticlePageDisplayer(MRArticlePageDisplayer& src, QWidget* parent = nullptr) = delete ;
//    MRArticlePageDisplayer(MRArticlePageDisplayer&& src, QWidget* parent = nullptr) = delete;
//    MRArticlePageDisplayer& operator=(MRArticlePageDisplayer& src) = delete;
//    MRArticlePageDisplayer& operator=(MRArticlePageDisplayer&& src) = delete;
    ~MRArticlePageDisplayer() override;

    void setMRPage(std::shared_ptr<MRPage> &src);    
    int pageIndex() const;

    void setAnnotationFlag(int flag);
    void setCursorType(CURSOR cursor);



    void setPageIndex(int index);
    void displayPage(float scaleX,
                     float scaleY,
                     float rotation,
                     int index,
                     QImage img,
                     std::shared_ptr<MRPage> page);

    void requestPage(int index,
                     float scaleX,
                     float scaleY,
                     float rotation);
protected:
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

    void drawAnnotations(QPainter &painter);



    void drawLine(QPainter &painter);
    void drawLine(QPainter &painter, const MRAnnotation& annotation);
    void drawSelectionFollowMouse(QPainter &painter);
    void drawSelection(QPainter &painter, const MRAnnotation& annot );

    void drawRectangleFollowMouse(QPainter &painter);
    void drawRectangle(QPainter &painter, const MRAnnotation& annot);
    void appendAnnotation(int type, const char *content=nullptr);
    void appendAnnotation(int type, const fz_quad& quad, char *content = nullptr);
    void appendAnnotation();
    void appendAnnotation(const fz_quad& quad);


public slots:
    void handleCursorType(CURSOR cursor );

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);

public:
//    virtual QSize sizeHint() const override;
    void setImage(const QImage &img);
    QString getTextFromSelection();
    QRectF calculateSelectionRect();


        
    float getScaleX() const;
    void setScaleX(float value);

    float getScaleY() const;
    void setScaleY(float value);

    void setDoc(std::shared_ptr<MRDocument> value);

private:
    void loadSignals();

private:
    MRArticlePageDisplayerPrivate *d;
};

#endif /* _ARTICLEPAGE_H */
