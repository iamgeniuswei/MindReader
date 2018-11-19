#include "notecard.h"
#include "ui_notecard.h"
#include <QMouseEvent>
#include "uilabel.h"
#include <QDebug>
#include "mrnotedata.h"
#include <QScrollBar>
#include "uitextedit.h"
NoteCard::NoteCard(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::NoteCard)
{
    ui->setupUi(this);
	//grabKeyboard();
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
    connect (ui->note, &UITextEdit::sizeChanged,
             this, &NoteCard::test1);
	//connect(ui->title, &QLineEdit::returnPressed,
	//	this, &NoteCard::updateTitleInDB);
	//connect(ui->title, &QLineEdit::textChanged,
	//	this, &NoteCard::updateTitleInDB);
	connect(ui->title, &QLineEdit::editingFinished,
		this, &NoteCard::updateTitleInDB);
	connect(ui->note, &UITextEdit::editingFinished,
		this, &NoteCard::updateNoteInDB);

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
	//qDebug() << "text changed";
}

void NoteCard::updateTitleInDB()
{
	qDebug() << "title update!";
	if (data == nullptr)
		return;
	data->setTitle(ui->title->text().toStdString());
	data->update();
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
        ui->content->setPixmap (pixmap);
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

void NoteCard::test1()
{
//    resize (this->width (), this->height ()+14);
}

void NoteCard::updateNoteInDB()
{
	qDebug() << "note update!";
	if (data == nullptr)
		return;
	data->setNote(ui->note->toPlainText().toStdString());
	data->update();
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
