#include "mrarticleshelf.h"
#include "qimagetextwidget.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QDropEvent>
#include <QDebug>
#include "mrarticlescanner.h"
#include "articleitem.h"
#include "mrarticleitem.h"
#include <QPushButton>
MRArticleShelf::MRArticleShelf(QWidget *parent) : UIWidget(parent)
{
    setObjectName ("MRArticleShelf");
    mainLayout = new UIFlowLayout(this, 9, 20);

//    mainLayout->addWidget (new QPushButton("Dfaf"));

//    ArticleItem *w = new ArticleItem (this);
//        w->setImage (":img/pdf");
//        w->setText ("dfafdas");
//    mainLayout->addWidget (w);

//    MRArticleItem *it = new MRArticleItem(this);
//    it->setTitle ("dsafasfas");
//    it->setFixedSize (120,180);
//    mainLayout->addWidget (it);

    setLayout (mainLayout);
//    setMaximumSize (200,200);
//    QSize widgetSize = this->size ();

//    qDebug() << "asdfasfas"<< widgetSize;
//    rowCount = widgetSize.width ()/ itemSize.width ();
//    layout = new QGridLayout(this);
//    layout->setSizeConstraint (QLayout::SetNoConstraint);
//    setLayout (layout);
//    layout->setColumnStretch (10, 1);
//    layout->setRowStretch (10,1);
//    QImageTextWidget *w1 = new QImageTextWidget(this);
//    QImageTextWidget *w2 = new QImageTextWidget(this);
//    QImageTextWidget *w3 = new QImageTextWidget(this);
//    QImageTextWidget *w4 = new QImageTextWidget(this);
////    layout->addWidget (w1, 0,0);
////    layout->addWidget (w2, 0, 1);
//    w1->setImage (":/img/files");
//    w1->setText ("zzhonggag");
//////    w1->setFixedSize (100,100);
//    w2->setImage (":/img/files");
//    w2->setText ("dsfasfasf");
//    layout->addWidget (w1, 0,0);
//    layout->addWidget (w2, 1,0);
//    w3->setImage (":/img/files");
//    w3->setText ("zzhonggag");
//    layout->addWidget (w3, 2,0);
//////    w1->setFixedSize (100,100);
//    w4->setImage (":/img/files");
//    w4->setText ("dsfasfasf");
//    layout->addWidget (w4, 3,0);
////    addItem (w3);
////    addItem (w4);
//    items.append (w1);
//    items.append (w2);
//    items.append (w3);
//    items.append (w4);
//    qDebug() << "mimi"<< this->minimumSize ();
//    itemCount = 4;
//    setCurrentRow (10);
//    setResizeMode(QListView::Adjust);
//    setViewMode (QListView::IconMode);
//    scanner = new ArticleScanner;
//    connect (scanner, &ArticleScanner::itemReady, this, &ArticleShelf::addArticle, Qt::QueuedConnection);
//    scanner->start ();
}

void MRArticleShelf::addArticleItem (std::shared_ptr<MRArticleMetaData> article)
{
    MRArticleItem *w = new MRArticleItem (this);
//    w->setImage (":img/pdf");
    w->setTitle (QString::fromStdString (article->title ()));
    w->setArticle (article);
    w->setFixedSize (120,180);

//    QListWidgetItem *it = new QListWidgetItem(this);
    qDebug() <<"widget size:" << w->size ();
//    it->setSizeHint (w->size ());
//    this->addItem (it);
//    this->setItemWidget (it, w);
    mainLayout->addWidget (w);
    setLayout (mainLayout);
    connect (w, &MRArticleItem::articleClicked,
             this, &MRArticleShelf::articleItemClicked);
}

void MRArticleShelf::clearArticleItems()
{
//    int count = this->count();
//    for(int i=0; i<count; i++)
//    {
//        QListWidgetItem *it = takeItem (i);
//        if(it != nullptr)
//        {
//            Q_ASSERT (it != nullptr);
//            delete it;
//        }
//    }
//    this->clear ();
//    update ();
}



//void ArticleShelf::dropEvent(QDropEvent *event)
//{
////    ArticleShelf *source = qobject_cast<ArticleShelf *>(event->source());

////    if (source && source == this)
////    {
////        //得到鼠标移动到的坐标
////        endPos = event->pos();
////        //通过endPos获取鼠标位置所在的行
////        QListWidgetItem *Enditem = itemAt(endPos);
////        //判断该位置是否在Item上
////        int rowCount = row(Enditem);

////        if(rowCount >= 0)
////        {
////            QList<QListWidgetItem*> pListItem;
////            pListItem =  source->selectedItems();
////            int count = pListItem.count();

////            if(count)
////            {
////                for(int i= 0;i<count;i++)
////                {
////                    QListWidgetItem *item = pListItem.at(i);
////                    removeItemWidget(item);
////                    delete item;
////                }

////            }
////        }
////    }

//}

//void ArticleShelf::resizeEvent(QResizeEvent *event)
//{
//    QWidget::resizeEvent (event);
//    removeWidgets ();
//    qDebug() << this->size ();
//    int currentRowCount = this->size ().width ()/itemSize.width ();
//    if(currentRowCount == rowCount || itemCount == 0)
//        return;
//    rowCount = currentRowCount;

////    reLayoutItems ();
//    reLayoutItems ();

//}

//void ArticleShelf::reLayoutItems()
//{
////    for(int i=0; i<4; i++)
////    {
////        QImageTextWidget *widget = items.at (i);
////        widget->show ();
////        layout->addWidget (widget, i, 0);
////    }
////    update ();
//    int temRows = itemCount / rowCount + 1;
//    for(int i=0; i<temRows; i++)
//    {
//        for(int j=0; j<rowCount; j++)
//        {
//            if(itemCount < (i*rowCount+j+1))
//                return;
//            QImageTextWidget *widget = items.at (i*rowCount+j);
//            if(widget)
//            {
//                layout->addWidget (widget, i, j);
//            }
//        }
//    }
//}

//void ArticleShelf::addItem(QImageTextWidget *widget)
//{
//    if(widget != nullptr)
//    {
//        QLayoutItem* item = layout->itemAtPosition (rows, lastColumnIndex);
//        if(item)
//        {
//            layout->removeItem (item);
//            delete item;
//        }
//        widget->setFixedSize (itemSize);
////        widget->setImageSize (itemSize.width (), itemSize.height (), true);
//        itemCount ++;
//        items.append (widget);

//        layout->addWidget (widget, rows, lastColumnIndex);
//        lastColumnIndex++;

//        if(lastColumnIndex >= rowCount)
//        {
////            layout->setRowStretch (rows, 0);
//            rows++;
//            lastColumnIndex = 0;
////            layout->addItem (new QSpacerItem(1,1), rows,lastColumnIndex);
////            layout->setRowStretch (rows, 1);
//        }
//        else
//        {
////            layout->addItem (new QSpacerItem(1,1), rows+1,lastColumnIndex);
////            layout->setRowStretch (rows+1, 1);
//        }

//    }
////    addCompensationItem ();
//}

//void ArticleShelf::addCompensationItem()
//{
//    layout->addItem (new QSpacerItem(10,10), rows, lastColumnIndex);
//    layout->addItem (new QSpacerItem(10,10), rows+1,0);
//}

//void ArticleShelf::removeWidgets()
//{
//    if(items.count () == 0)
//        return;
//    for(int i=0; i<items.count (); i++)
//    {
//        QImageTextWidget *widget = items.at (i);
//        layout->removeWidget (widget);
////        widget->hide ();
//    }
////    layout->setRowMinimumHeight (0,0);
////    layout->setRowStretch (0,0);
////    layout->setRowMinimumHeight (1,0);
////    layout->setRowStretch (1,0);
////    layout->setRowMinimumHeight (2,0);
////    layout->setRowStretch (2,0);
////    layout->setRowStretch (rows, 0);
////    layout->setRowStretch (rows+1, 0);
////    rows = 0;
////    lastColumnIndex = 0;
//}
