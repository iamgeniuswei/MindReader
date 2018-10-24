#ifndef NOTEDISPLAYER_H
#define NOTEDISPLAYER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "notecard.h"
#include "window_global.h"
class WINDOWSHARED_EXPORT NoteDisplayer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit NoteDisplayer(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGraphicsScene *scene = nullptr;

};

#endif // NOTEDISPLAYER_H
