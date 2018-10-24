#ifndef NOTECARD_H
#define NOTECARD_H

#include <QWidget>
#include "window_global.h"
namespace Ui {
class NoteCard;
}

class WINDOWSHARED_EXPORT NoteCard : public QWidget
{
    Q_OBJECT

public:
    explicit NoteCard(QWidget *parent = nullptr);
    ~NoteCard();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
//    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::NoteCard *ui;
    QPoint startPoint;
    QPoint endPoint;
    QPoint distance;
};

#endif // NOTECARD_H
