#include "mrlibrarytree.h"
#include "ui_mrlibrarytree.h"
#include <QStandardItem>
#include <QModelIndex>
#include <QDebug>
MRLibraryTree::MRLibraryTree(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::MRLibraryTree)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    root = new QStandardItem( QIcon(":/img/browser") ,tr("Root"));
    ui->articleTree->setModel (model);
    model->appendRow (root);
}

MRLibraryTree::~MRLibraryTree()
{
    delete ui;
}

void MRLibraryTree::addFolder(const QString& name)
{
    if(name.isEmpty ())
        return;
    if(cur_index.isValid ())
    {
        QStandardItem *top = model->itemFromIndex (cur_index);
        QStandardItem *item = new QStandardItem( QIcon(":/img/browser") ,name);
        Q_ASSERT ( top != nullptr );
        top->appendRow (item);
    }
    else
    {
        QStandardItem *item = new QStandardItem( QIcon(":/img/browser") ,name);
        Q_ASSERT ( root != nullptr );
        root->appendRow (item);
    }
}



void MRLibraryTree::on_articleTree_clicked(const QModelIndex &index)
{
    cur_index = index;
    QStandardItem *item = model->itemFromIndex (index);
    QString dir = getRelativeDir (item);
    int count = item->rowCount ();
    if(count !=0)
        item->removeRows (0, count);
    emit showArticleInDir (dir);


}

QString MRLibraryTree::getRelativeDir(QStandardItem* item)
{
    QString dir;
    while (item != root)
    {
        dir.prepend (item->text ());
        dir.prepend ("/");
        item = item->parent ();
    }
    if(dir.isEmpty ())
        dir = "root";
    return dir;
}
