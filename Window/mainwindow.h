#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "articleshelf.h"
#include "window_global.h"
namespace Ui {
class MainWindow;
}

class WINDOWSHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget *container = nullptr;
    ArticleShelf *library = nullptr;
};

#endif // MAINWINDOW_H
