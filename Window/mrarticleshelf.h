#ifndef ARTICLESHELF_H
#define ARTICLESHELF_H

#include <QWidget>
#include "uiwidget.h"
#include <QListWidget>
#include "mrarticlemetadata.h"
#include <memory>
#include "window_global.h"
#include "uiflowlayout.h"
#include <QVBoxLayout>
class QGridLayout;
class QImageTextWidget;
class MRArticleScanner;
class WINDOWSHARED_EXPORT MRArticleShelf : public UIWidget
{
    Q_OBJECT
public:
    explicit MRArticleShelf(QWidget *parent = nullptr);
//    void dropEvent(QDropEvent *event);

//    virtual void resizeEvent(QResizeEvent *event);

//    void reLayoutItems();
//    void addItem(QImageTextWidget *widget = nullptr);
//    void addCompensationItem();
//    void removeWidgets();

signals:
//    void articleClicked();
    void articleItemClicked(std::shared_ptr<MRArticleMetaData> article);
public slots:
    void addArticleItem(std::shared_ptr<MRArticleMetaData> article);
    void clearArticleItems();


private:
//    QGridLayout *layout = nullptr;
//    unsigned int rows = 0;
//    unsigned int lastColumnIndex = 0;
//    int rowCount = 0;
//    unsigned int columns = 0;
//    QPoint endPos;
//    unsigned int itemCount = 0;
//    QSize itemSize;
//    QList<QImageTextWidget*> items;
    MRArticleScanner *scanner = nullptr;
    UIFlowLayout *mainLayout = nullptr;
};

#endif // ARTICLESHELF_H
