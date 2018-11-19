#include "mrseriespagedisplayer.h"
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QVector>
#include <QPainter>
#include <QPaintEvent>
#include "articlepagerender.h"
#include "mrarticleloader.h"
#include "mrpage.h"
#include "mrarticlemetadata.h"
MRSeriesPageDisplayer::MRSeriesPageDisplayer(QWidget *parent) : MRArticleCanvas(parent)
{	
	loadUI();
	loadSignals();
}

MRSeriesPageDisplayer::~MRSeriesPageDisplayer()
{
}


void MRSeriesPageDisplayer::loadUI()
{

}

void MRSeriesPageDisplayer::loadSignals()
{
	loader = new MRArticleLoader(this);
	connect(loader, &MRArticleLoader::docReady,
		this, &MRSeriesPageDisplayer::handleDocReady);


	render = new ArticlePageRender(this);
	connect(render, &ArticlePageRender::pageReady,
		this, &MRSeriesPageDisplayer::pageLoaded);
}

void MRSeriesPageDisplayer::handleDocReady(bool ret, std::shared_ptr<MRDocument> document)
{
	if (ret)
	{
		doc = document;
		render->setPDFDocument(doc);
		totalPages = doc->pageCount();
		pageSizes.clear();
		for (int page = 0; page < totalPages; page++)
		{
			pageSizes.append(doc->page(page)->size() * screenResolution);
		}
        invalidate ();
	}
	else
	{
		qDebug() << "can not open file";
    }
}

bool MRSeriesPageDisplayer::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    QString articlePath = QString::fromStdString (article->relative_path ());
    Q_ASSERT (loader != nullptr );
    loader->loadArticle (articlePath);
    return true;
}

void MRSeriesPageDisplayer::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	if (totalPages == 0)
		return;

	int page = 0;
	int pos = 0;
	while (page < totalPages)
	{
		int page_height = pageSizes.at(page).toSize().height();
		if (pos + page_height >= event->rect().top())
		{
			break;
		}
		pos += page_height + pageSpacing;
		page++;		
	}

	while (pos < event->rect().bottom() && page < totalPages)
	{
		QSizeF page_size = pageSizes.at(page);
		if (pageCache.contains(page))
		{
			const QImage &img = pageCache[page];
			painter.fillRect((width() - img.width()) / 2, pos, page_size.width(), page_size.height(), Qt::white);
			painter.drawImage((width() - img.width()) / 2, pos, img);
			getCurrentPage();
		}
		else
		{
			painter.fillRect((width() - page_size.width()) / 2, pos, page_size.width(), page_size.height(), Qt::white);
            render->requestPage(page, 1.0*screenResolution, 1.0*screenResolution, 0.0);
		}
        pos += page_size.height ()+ pageSpacing;
        page++;
	}

}

int MRSeriesPageDisplayer::getCurrentPage()
{
	QRect visibleRect = this->visibleRegion().boundingRect();

	int top = visibleRect.y();
	int bottom = visibleRect.y() + visibleRect.height();
	int middle = (top + bottom) / 2;
	int page = 0;
	int pos = 0;
	for (page = 0; page < totalPages; page++)
	{
		int page_height = pageSpacing + pageSizes.at(page).toSize().height();
		if (pos == top)
		{
			pageIndex = page;
			break;
		}
		if (pos < top && pos + page_height >= bottom)
		{
			pageIndex = page;
			break;
		}
		if (pos > top && pos + page_height <= bottom)
		{
			pageIndex = page;
			break;
		}
		if (pos <= middle && pos + page_height >= bottom)
		{
			pageIndex = page;
			break;
		}
		if (pos > middle && pos + page_height > bottom)
		{
			pageIndex = page - 1;
			break;
		}
		pos += page_height;
	}
	return pageIndex;
}

int MRSeriesPageDisplayer::yValueForPage()
{
	int y = 0;
	for (int page = 0; page < totalPages && page < pageIndex; ++page)
	{
		y += pageSpacing + pageSize(page).toSize().height();
	}
	return y;
}

void MRSeriesPageDisplayer::invalidate()
{
    QSizeF total_size(0, pageSpacing);
    QSizeF size(0, 0);
    for (int page = 0; page < totalPages; ++page)
    {
        size = pageSize(page);
        total_size.setHeight(total_size.height() + size.height() + pageSpacing);
        if (size.width() > total_size.width())
        {
            total_size.setWidth(size.width());
        }
    }
    total_size += QSizeF(0.49,0.49);
//    total = total_size.toSize();
    setMinimumSize(total_size.toSize ());
    pageCache.clear();
    update();
}

QSizeF MRSeriesPageDisplayer::pageSize(int page)
{
    return pageSizes.value(page) * zoom;
}


void MRSeriesPageDisplayer::pageLoaded(float scaleX,
	float scaleY,
	float rotation,
	int index,
	QImage img,
	std::shared_ptr<MRPage> page)
{
	if (cachePagesLRU.length() > pageCacheLimit)
	{
		pageCache.remove(cachePagesLRU.takeFirst());
	}
	pageCache.insert(index, img);
	cachePagesLRU.append(index);
}
