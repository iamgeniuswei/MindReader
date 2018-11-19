#include "mrtextitem.h"
#include <QPainter>
#include <QDebug>
MRTextItem::MRTextItem(QGraphicsItem *parent)
	: QGraphicsItem(parent)
{
	widget = new QWidget;
	lE1 = new QLineEdit("dsfasdf",widget);
	lE2 = new QLineEdit("dsfasdf", widget);
	layout = new QVBoxLayout(widget);
	layout->addWidget(lE1);
	layout->addWidget(lE2);
	//layout->setSizeConstraint(QLayout::SetFixedSize);
	widget->setLayout(layout);
	proxy = new QGraphicsProxyWidget(this);
	proxy->setWidget(widget);

	//title = new QGraphicsSimpleTextItem(this);
	//title->setText("dsafasdfa");
	//content = new QGraphicsTextItem(this);
	//content->setPlainText("sdafadsfas");
	//note = new QGraphicsTextItem(this);
	//note->setPlainText("adsfafdasf");
	//title->setPos(boundingRect().left(), boundingRect().top());
	//content->setPos(boundingRect().left(), boundingRect().top() + 20);
	//note->setPos(boundingRect().left(), boundingRect().top() + 60);	
	setFlag(QGraphicsItem::ItemIsMovable);

}

MRTextItem::~MRTextItem()
{

}

QRectF MRTextItem::boundingRect() const
{
	if (widget)
		return(QRectF(0, 0, widget->width(), widget->height()));
	return QRectF(0, 0, 200, 80);
}

void MRTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	
}