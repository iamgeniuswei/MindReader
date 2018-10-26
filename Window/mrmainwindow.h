#ifndef MRMAINWINDOW_H
#define MRMAINWINDOW_H

#include <QMainWindow>
#include "window_global.h"
#include <QStackedWidget>
namespace Ui {
class MRMainWindow;
}

class WINDOWSHARED_EXPORT MRMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MRMainWindow(QWidget *parent = nullptr);
    ~MRMainWindow();

public slots:
    void switchToAritcle(const QString& text);

private:
    Ui::MRMainWindow *ui;
    QStackedWidget *container = nullptr;
};

#endif // MRMAINWINDOW_H
