#ifndef MRTEXTITEM_H
#define MRTEXTITEM_H

#include <QObject>
#include <QWidget>
#include <QVboxLayout>
#include <QLineEdit>
#include <QGraphicsItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
class MRTextItem : public QGraphicsItem
{
	
public:
	MRTextItem(QGraphicsItem *parent = nullptr);
	~MRTextItem();

protected:

	virtual QRectF
		boundingRect() const;

	virtual void
		paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


private:
	QGraphicsSimpleTextItem *title = nullptr;
	QGraphicsTextItem *content = nullptr;
	QGraphicsTextItem *note = nullptr;
	QWidget *widget = nullptr;
	QLineEdit *lE1 = nullptr;
	QLineEdit *lE2 = nullptr;
	QVBoxLayout *layout = nullptr;
	QGraphicsProxyWidget *proxy = nullptr;
};

#endif // MRTEXTITEM_H
