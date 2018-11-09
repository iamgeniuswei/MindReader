#include "mrarticleitem.h"
#include "ui_mrarticleitem.h"
#include "mrwindowutility.h"
#include <QPainter>
#include <QDebug>
#include "mrarticlemetadata.h"
MRArticleItem::MRArticleItem(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::MRArticleItem)
{
    ui->setupUi(this);
    setObjectName ("MRArticleItem");
}

MRArticleItem::~MRArticleItem()
{
    delete ui;
    qDebug() << "delete item";
}

void MRArticleItem::setTitle(const QString &text)
{
    QString str = getElidedText (text, this->font (),100);
    ui->MRAITitle->setText (str);

}

void MRArticleItem::setArticle(const std::shared_ptr<MRArticleMetaData> &value)
{
    Q_ASSERT (value != nullptr );
    data = value;
}



void MRArticleItem::paintEvent(QPaintEvent *event)
{
    UIWidget::paintEvent (event);

    QPainter painter(this);
    painter.setRenderHint (QPainter::Antialiasing);
    painter.drawPixmap (0, 16, 60,30, QPixmap(":/img/pdf_t"));

//    painter.drawText (15,24, "PDF");

    static const QPointF points[5] = {
          QPointF(80.0, 0.0),
          QPointF(80.0, 24.0),
          QPointF(95.0, 36.0),
          QPointF(110.0, 24.0),
          QPointF(110.0, 0.0)
      };
    painter.setBrush (QBrush(QColor(45,45,45)));
    painter.drawPolygon (points, 5, Qt::WindingFill);

    painter.drawPixmap (80,140,32,32, QPixmap(":/img/pdf_s"));
    painter.drawPixmap (88,150,24,24, QPixmap(":/img/confirm"));


}

void MRArticleItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(data != nullptr)
    {
        qDebug() << QString::fromStdString (data->title ());
        emit articleClicked (data);
    }
    UIWidget::mouseDoubleClickEvent (event);
}
