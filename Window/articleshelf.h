#ifndef ARTICLESHELF_H
#define ARTICLESHELF_H

#include <QWidget>
#include <QListWidget>
#include "window_global.h"
class QGridLayout;
class QImageTextWidget;
class ArticleScanner;
class WINDOWSHARED_EXPORT ArticleShelf : public QListWidget
{
    Q_OBJECT
public:
    explicit ArticleShelf(QWidget *parent = nullptr);
//    void dropEvent(QDropEvent *event);

//    virtual void resizeEvent(QResizeEvent *event);

//    void reLayoutItems();
//    void addItem(QImageTextWidget *widget = nullptr);
//    void addCompensationItem();
//    void removeWidgets();

signals:
//    void articleClicked();
    void articleClicked(const QString& text);
public slots:
    void addArticle(const QString& text);


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
    ArticleScanner *scanner = nullptr;
};

#endif // ARTICLESHELF_H
