#ifndef MRMAPVIEW_H
#define MRMAPVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "mritemconnector.h"
#include "mrtextitem.h"
#include "mrmindmap_global.h"
class MRMINDMAPSHARED_EXPORT MRMapView : public QGraphicsView
{
	Q_OBJECT

public:
	explicit MRMapView(QWidget *parent = nullptr);
	~MRMapView();

public:
	

protected:
	void loadUI();

private:
	QGraphicsScene *scene = nullptr;	
};

#endif // MRMAPVIEW_H
