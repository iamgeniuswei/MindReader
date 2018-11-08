#ifndef ARTICLEDISPLAYERCONTROLLER_H
#define ARTICLEDISPLAYERCONTROLLER_H

#include <QWidget>
#include "uiwidget.h"
#include <QPushButton>
#include "window_global.h"
namespace Ui {
class ArticleDisplayerController;
}

class WINDOWSHARED_EXPORT ArticleDisplayerController : public UIWidget
{
    Q_OBJECT

public:
    explicit ArticleDisplayerController(QWidget *parent = nullptr);
    ~ArticleDisplayerController();

protected:
    void initializeSignals();
signals:
    void firstPageClicked();
    void prevPageClicked();
    void nextPageClicked();
    void lastPageClicked();
    void zoomInClicked();
    void zoomOutClicked();

public:
    QPushButton* getPage() const;
    QPushButton* getPageBreak() const;


public slots:
    void updateADCIndex(const QStringList& items);

signals:
    void changeToSinglePage();
    void changeToContinuousPage();

private slots:
    void on_page_clicked();

    void on_pageBreak_clicked();

private:
    Ui::ArticleDisplayerController *ui;
};

#endif // ARTICLEDISPLAYERCONTROLLER_H
