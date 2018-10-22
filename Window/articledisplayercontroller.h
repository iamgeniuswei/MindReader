#ifndef ARTICLEDISPLAYERCONTROLLER_H
#define ARTICLEDISPLAYERCONTROLLER_H

#include <QWidget>

namespace Ui {
class ArticleDisplayerController;
}

class ArticleDisplayerController : public QWidget
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

private:
    Ui::ArticleDisplayerController *ui;
};

#endif // ARTICLEDISPLAYERCONTROLLER_H
