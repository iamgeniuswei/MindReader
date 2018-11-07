#ifndef MRLIBRARYTREE_H
#define MRLIBRARYTREE_H

#include <QWidget>
#include "uiwidget.h"
#include <memory>
#include "mrarticlemetadata.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>
namespace Ui {
class MRLibraryTree;
}

class MRLibraryTree : public UIWidget
{
    Q_OBJECT

public:
    explicit MRLibraryTree(QWidget *parent = nullptr);
    ~MRLibraryTree();
public slots:
    void addFolder(const QString &name);

private slots:
    void on_articleTree_clicked(const QModelIndex &index);
    QString getRelativeDir(QStandardItem *item);
signals:
    void showArticleInDir(const QString& relative_dir);

private:
    Ui::MRLibraryTree *ui;
    QStandardItemModel *model = nullptr;
    QStandardItem *root = nullptr;
    QModelIndex cur_index;
};

#endif // MRLIBRARYTREE_H
