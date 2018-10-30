#include "qimagetextwidget.h"
#include "ui_qimagetextwidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDrag>
#include <QMimeData>
QImageTextWidget::QImageTextWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QImageTextWidget)
{
    ui->setupUi(this);
    setAcceptDrops (true);
}

QImageTextWidget::~QImageTextWidget()
{
    delete ui;
}

void QImageTextWidget::setImage(const QString &path)
{
    ui->lbImage->setPixmap (QPixmap(path));
}

void QImageTextWidget::setImageSize(int w, int h, bool keepAspectRatio)
{
    QSize size(w, h);
    const QPixmap *current = ui->lbImage->pixmap ();
    QPixmap scaled = current->scaled (w, h, Qt::KeepAspectRatio);
    update();
//    delete current;
    ui->lbImage->setPixmap (scaled);
}

void QImageTextWidget::setText(const QString &text)
{
    ui->lbText->setText (text);
}

QSize QImageTextWidget::sizeHit() const
{
    return QSize(100,100);
}

void QImageTextWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "enter drag mode";
    event->acceptProposedAction ();
}

void QImageTextWidget::dragLeaveEvent(QDragLeaveEvent *event)
{

}

void QImageTextWidget::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction ();
    qDebug() << "accept";
}

void QImageTextWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons () & Qt::LeftButton))
        return;
    QDrag *drag = new QDrag(this);
    QMimeData *data = new QMimeData;
    data->setData ("test", "test");
    drag->setMimeData (data);
    Qt::DropAction resultAction = drag->exec(Qt::MoveAction);
    if(resultAction == Qt::MoveAction)
    {
        qDebug() << "move success";
    }
}

void QImageTextWidget::mousePressEvent(QMouseEvent *event)
{

}



//void QImageTextWidget::mouseDoubleClickEvent(QMouseEvent *event)
//{
//    qDebug() << "mouseDoubleClickEvent";
//    qDebug() << ui->lbText->text ();
//    emit clicked (ui->lbText->text ());
//}


