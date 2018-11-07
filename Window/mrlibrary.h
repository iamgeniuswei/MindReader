#ifndef MRLIBRARY_H
#define MRLIBRARY_H

#include <QWidget>
#include "uiwidget.h"
#include "mrlibrarytoolbar.h"
#include <QVBoxLayout>
#include <memory>
#include "mrarticleshelf.h"
#include "mrarticlemetadata.h"
#include "mrlibrarytree.h"
#include <QSplitter>
#include "mrarticlescanner.h"
class MRLibrary : public UIWidget
{
    Q_OBJECT
public:
    explicit MRLibrary(QWidget *parent = nullptr);

signals:
    void articleClicked(std::shared_ptr<MRArticleMetaData> article);

protected:
    void loadUI();
    void loadSignals();
    void loadThreads();

public slots:
    void refreshLibrary(const QString& relative_dir);
private:
    QVBoxLayout *layout = nullptr;
    MRLibraryToolBar *toolBar = nullptr;
    MRArticleShelf *shelf = nullptr;
    MRLibraryTree *tree = nullptr;
    QSplitter *splitter = nullptr;
    MRArticleScanner *scanner = nullptr;

};

#endif // MRLIBRARY_H
