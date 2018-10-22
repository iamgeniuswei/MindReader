#include "articledisplayercontroller.h"
#include "ui_articledisplayercontroller.h"

ArticleDisplayerController::ArticleDisplayerController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleDisplayerController)
{
    ui->setupUi(this);
    initializeSignals ();
}

ArticleDisplayerController::~ArticleDisplayerController()
{
    delete ui;
}

void ArticleDisplayerController::initializeSignals()
{
    connect (ui->firstPageBtn, &QPushButton::clicked,
             this, &ArticleDisplayerController::firstPageClicked);
    connect (ui->prevPageBtn, &QPushButton::clicked,
             this, &ArticleDisplayerController::prevPageClicked);
    connect (ui->nextPageBtn, &QPushButton::clicked,
             this, &ArticleDisplayerController::nextPageClicked);
    connect (ui->lastPageBtn, &QPushButton::clicked,
             this,&ArticleDisplayerController::lastPageClicked);
    connect (ui->zoomInBtn, &QPushButton::clicked,
             this, &ArticleDisplayerController::zoomInClicked);
    connect (ui->zoomOutBtn, &QPushButton::clicked,
             this, &ArticleDisplayerController::zoomOutClicked);
}
