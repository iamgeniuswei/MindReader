#ifndef MRLIBRARY_H
#define MRLIBRARY_H

#include <QWidget>
#include "mrlibrarytoolbar.h"
#include <QVBoxLayout>
#include "articleshelf.h"
class MRLibrary : public QWidget
{
    Q_OBJECT
public:
    explicit MRLibrary(QWidget *parent = nullptr);

signals:
    void articleClicked(const QString& text);
public slots:

private:
    QVBoxLayout *layout = nullptr;
    MRLibraryToolBar *toolBar = nullptr;
    ArticleShelf *shelf = nullptr;
};

#endif // MRLIBRARY_H
