#include "mrworkdirsettingwindow.h"
#include "ui_mrworkdirsettingwindow.h"
#include <QStyleOption>
#include <QPainter>
#include <QFileDialog>
#include <QMouseEvent>
#include "mrsetting.h"
#include "mrarticleshelf.h"
MRWorkDirSettingWindow::MRWorkDirSettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MRWorkDirSettingWindow)
{
    ui->setupUi(this);
    ui->browserBtn->setObjectName ("browser");
    ui->ignore->setObjectName ("test");
    ui->confirm->setObjectName ("test");
    ui->close->setObjectName ("close");
    setWindowFlag (Qt::FramelessWindowHint);
//    this->setObjectName ("mw");
}

MRWorkDirSettingWindow::~MRWorkDirSettingWindow()
{
    delete ui;
}

void MRWorkDirSettingWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MRWorkDirSettingWindow::mouseMoveEvent(QMouseEvent *event)
{
    endPoint = event->globalPos ();
    move (endPoint - distance);
}

void MRWorkDirSettingWindow::mousePressEvent(QMouseEvent *event)
{
    startPoint = this->pos ();
    QPoint mousePos = event->globalPos ();
    distance = mousePos - startPoint;
}

void MRWorkDirSettingWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MRWorkDirSettingWindow::on_browserBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    ui->lineEdit->setText (dir);
}

void MRWorkDirSettingWindow::on_confirm_clicked()
{
    //TODO:将MRSetting修改为单例模式
    if(!ui->lineEdit->text ().isEmpty ())
    {
		MRSetting *set = MRSetting::instance();
        set->setWorkDirectory (ui->lineEdit->text ());
        set->setFirstUseage ();
    }
    MRArticleShelf *w = new MRArticleShelf;
    w->show ();
    this->close ();
}

void MRWorkDirSettingWindow::on_ignore_clicked()
{
    MRArticleShelf *w = new MRArticleShelf;
    w->show ();
    this->close ();
}

void MRWorkDirSettingWindow::on_close_clicked()
{
    this->close ();
}
