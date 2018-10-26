#ifndef MRWORKDIRSETTINGWINDOW_H
#define MRWORKDIRSETTINGWINDOW_H

#include <QWidget>
#include "window_global.h"

namespace Ui {
class MRWorkDirSettingWindow;
}

class WINDOWSHARED_EXPORT MRWorkDirSettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MRWorkDirSettingWindow(QWidget *parent = nullptr);
    ~MRWorkDirSettingWindow();

protected:
    virtual void paintEvent(QPaintEvent *);

    virtual void
    mouseMoveEvent(QMouseEvent *event);
    virtual void
    mousePressEvent(QMouseEvent *event);
    virtual void
    mouseReleaseEvent(QMouseEvent *event);


private slots:
    void on_browserBtn_clicked();

    void on_confirm_clicked();

    void on_ignore_clicked();

    void on_close_clicked();

private:
    Ui::MRWorkDirSettingWindow *ui;
    QPoint startPoint;
    QPoint endPoint;
    QPoint distance;
};

#endif // MRWORKDIRSETTINGWINDOW_H
