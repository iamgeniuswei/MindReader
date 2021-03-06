#include "articledisplayercontroller.h"
#include "ui_articledisplayercontroller.h"

ArticleDisplayerController::ArticleDisplayerController(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::ArticleDisplayerController)
{
    ui->setupUi(this);
    initializeSignals ();
    setObjectName ("whiteWidget");
    ui->firstPageBtn->setObjectName ("controlButton");
    ui->prevPageBtn->setObjectName ("controlButton");
    ui->nextPageBtn->setObjectName ("controlButton");
    ui->lastPageBtn->setObjectName ("controlButton");
    ui->zoomInBtn->setObjectName ("controlButton");
    ui->zoomOutBtn->setObjectName ("controlButton");
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
