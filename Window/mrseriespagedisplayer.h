#ifndef MRSERIESPAGEDISPLAYER_H
#define MRSERIESPAGEDISPLAYER_H

#include "mrarticlecanvas.h"
#include <QWidget>
#include "articlepagerender.h"
#include "mrarticleloader.h"
class MRSeriesPageDisplayer : public MRArticleCanvas
{
    Q_OBJECT
public:
    explicit MRSeriesPageDisplayer(QWidget *parent = nullptr);
	~MRSeriesPageDisplayer();
    void loadUI();
    void loadSignals();

    void handleDocReady(bool ret, std::shared_ptr<MRDocument> document);
    bool setArticle(std::shared_ptr<MRArticleMetaData> article);

	virtual void paintEvent(QPaintEvent *event) override;
	int getCurrentPage();
	int yValueForPage();

private:
	void invalidate();
	QSizeF pageSize(int page);




signals:

public slots :
	void pageLoaded(float scaleX,
		float scaleY,
		float rotation,
		int index,
		QImage img,
		std::shared_ptr<MRPage> page);


private:
	QHash<int, QImage> pageCache;
	QVector<int> cachePagesLRU;
	int pageCacheLimit = 9;
	QVector<QSizeF> pageSizes;

	int pageSpacing = 9;
	//int pageIndex = 0;
	//int totalPages = 0;
    qreal zoom = 1.0;
    qreal screenResolution = 1.0;
    ArticlePageRender *render = nullptr;
    std::shared_ptr<MRDocument> doc = nullptr;
    MRArticleLoader *loader = nullptr;
};

#endif // MRSERIESPAGEDISPLAYER_H
