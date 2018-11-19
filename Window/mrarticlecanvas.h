/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   ArticleDisplayer.h
  * Author: develop
  *
  * Created on October 11, 2018, 10:42 AM
  */

#ifndef _MRARTICLEDISPLAYER_H
#define _MRARTICLEDISPLAYER_H

#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>
#include "window_global.h"
#include <QLabel>
#include "mrarticlepagedisplayer.h"
#include "articlepagerender.h"
#include "mrwindowutility.h"
class MRDocument;
class MRPage;
class MRArticleMetaData;
class MRArticleLoader;
class QVBoxLayout;
class WINDOWSHARED_EXPORT MRArticleCanvas : public QWidget
{
	Q_OBJECT
public:
	MRArticleCanvas(QWidget *parent = nullptr);
	virtual ~MRArticleCanvas();
	virtual bool setArticle(std::shared_ptr<MRArticleMetaData> article);
	virtual int yValueForPage() { return 0; };
protected:
	virtual void wheelEvent(QWheelEvent *event);

protected:
	virtual void loadUI() {};
	virtual void loadSignals();

signals:
	void imageReady(int page, const QPixmap& pixmap);
	void textReady(int page, const QString& text);
	void cursorReady(CURSOR cursor);
	void colorReady(const QColor& color);
	void ADCIndexItemsReady(const QStringList& items);
public slots:
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

private slots:
	virtual void handleDocReady(bool ret, std::shared_ptr<MRDocument> document);
	void handleScrollBarChanged(int value);

protected:
	ArticlePageRender *render = nullptr;
	MRArticleLoader *loader = nullptr;
	std::shared_ptr<MRDocument> doc = nullptr;
	QList<MRPage*> pages;
	int pageIndex = 0;
	int totalPages = 0;
	qreal zoom = 1.0;
	qreal screenResolution = 1.0;
	int pageSpacing = 9;
};

#endif /* _MRARTICLEDISPLAYER_H */
