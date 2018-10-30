#ifndef MRMAINWINDOW_H
#define MRMAINWINDOW_H

#include <QMainWindow>
#include "window_global.h"
#include <QStackedWidget>
#include "mrlibrary.h"
#include <memory>
class MRArticleMetaData;
namespace Ui {
class MRMainWindow;
}

class WINDOWSHARED_EXPORT MRMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MRMainWindow(QWidget *parent = nullptr);
    ~MRMainWindow();
    void initializeSignals();

public slots:
    void switchToAritcle(std::shared_ptr<MRArticleMetaData> article);
    void switchLibrary();

private:
    Ui::MRMainWindow *ui;
    QStackedWidget *container = nullptr;
    MRLibrary *library = nullptr;
};

#endif // MRMAINWINDOW_H
