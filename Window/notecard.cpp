#include "notecard.h"
#include "ui_notecard.h"
#include <QMouseEvent>
#include "uilabel.h"
#include <QDebug>
#include "mrnotedata.h"
NoteCard::NoteCard(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::NoteCard)
{
    ui->setupUi(this);
//    ui->content->setGeometry(QRect(328, 240, 329, 27*10));  //四倍行距

    ui->content->setWordWrap(true);
    ui->content->setAlignment(Qt::AlignTop);
    ui->content->setScaledContents (true);
    ui->trash->setObjectName ("trash");
    ui->index->setObjectName ("index");
    ui->title->setObjectName ("title");
    ui->note->setObjectName ("note");
    connect (ui->index, &UILabel::clicked,
             this, &NoteCard::test);

}

NoteCard::~NoteCard()
{
    delete ui;
}

void NoteCard::setTitle(const QString &title)
{
    ui->title->setText (title);
    ui->title->adjustSize ();

    data->update ();
}

void NoteCard::setText(const QString &text)
{
    ui->content->setText (text);
    ui->content->adjustSize ();
    ui->content->setFixedHeight (ui->content->height ());
    update ();
    data->update ();
}

void NoteCard::setIndex(int index)
{
    ui->index->setText (QString::number (index, 10));
    data->update ();
}

void NoteCard::setPixmap(const QPixmap &pixmap)
{
    //    ui->content->setPixmap (pixmap);
}

void NoteCard::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    data = std::make_shared<MRNoteData>();
    data->setArticle (article);
    qDebug() << "persist note: " << data->persist ();
}

void NoteCard::test()
{
    qDebug() << "label clicked";
}

void NoteCard::mousePressEvent(QMouseEvent *event)
{
    startPoint = this->pos ();
    QPoint mousePos = event->globalPos ();
    distance = mousePos - startPoint;

}

void NoteCard::mouseReleaseEvent(QMouseEvent *event)
{

}

void NoteCard::mouseMoveEvent(QMouseEvent *event)
{
    endPoint = event->globalPos ();
    move (endPoint - distance);
}
