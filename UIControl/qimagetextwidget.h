#ifndef QIMAGETEXTWIDGET_H
#define QIMAGETEXTWIDGET_H

#include <QWidget>
#include "uicontrol_global.h"
namespace Ui {
class QImageTextWidget;
}

class UICONTROLSHARED_EXPORT QImageTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QImageTextWidget(QWidget *parent = nullptr);
    ~QImageTextWidget();
    void setImage(const QString& path);
    void setImageSize(int w, int h, bool keepAspectRatio);
    void setText(const QString& text);
    virtual QSize sizeHit() const;
protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);


signals:
    void clicked(const QString& text);

private:
    Ui::QImageTextWidget *ui;
};

#endif // QIMAGETEXTWIDGET_H
