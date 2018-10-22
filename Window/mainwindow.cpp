#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    container = new QStackedWidget(this);
    setCentralWidget (container);
    library = new ArticleShelf(this);
    container->addWidget (library);
}

MainWindow::~MainWindow()
{
    delete ui;
}
