#ifndef MRLIBRARY_H
#define MRLIBRARY_H

#include <QWidget>
#include "mrlibrarytoolbar.h"
#include <QVBoxLayout>
#include <memory>
#include "articleshelf.h"
#include "mrarticlemetadata.h"
class MRLibrary : public QWidget
{
    Q_OBJECT
public:
    explicit MRLibrary(QWidget *parent = nullptr);

signals:
    void articleClicked(std::shared_ptr<MRArticleMetaData> article);
public slots:

private:
    QVBoxLayout *layout = nullptr;
    MRLibraryToolBar *toolBar = nullptr;
    ArticleShelf *shelf = nullptr;
};

#endif // MRLIBRARY_H
