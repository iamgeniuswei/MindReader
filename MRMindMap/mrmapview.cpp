#include "mrmapview.h"
#include "mrtextitem.h"
#include <QLineEdit>
#include <QGraphicsProxyWidget>
MRMapView::MRMapView(QWidget *parent)
	: QGraphicsView(parent)
{
	loadUI();

}

MRMapView::~MRMapView()
{

}

void MRMapView::loadUI()
{
	scene = new QGraphicsScene(this);
	setScene(scene);

	MRTextItem *item = new MRTextItem;
	scene->addItem(item);
	//MRTextItem *item1 = new MRTextItem;
	//scene->addItem(item1);
	//MRTextItem *item2 = new MRTextItem;
	//scene->addItem(item2);
	//QLineEdit* pLineEdit = new QLineEdit("Some Text");
	//// add the widget - internally, the QGraphicsProxyWidget is created and returned
	////QGraphicsProxyWidget* pProxyWidget = pScene->AddWidget(pLineEdit);

	////Or just add it to your current QGraphicsItem. Here, you can either add it as a child of the QGraphicsItem: -

	//MRTextItem* pMyItem = new MRTextItem;
	//QGraphicsProxyWidget* pMyProxy = new QGraphicsProxyWidget(pMyItem); // the proxy's parent is pMyItem
	//pMyProxy->setWidget(pLineEdit);
	//scene->addItem(pMyItem);
}
