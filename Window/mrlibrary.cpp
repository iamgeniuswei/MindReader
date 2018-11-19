#include "mrlibrary.h"
#include "mrsetting.h"
MRLibrary::MRLibrary(QWidget *parent) : UIWidget(parent)
{
    loadUI ();
    loadThreads ();
    loadSignals ();
    MRSetting *set = MRSetting::instance();
    QString working_dir = set->getWorkDirectory ();
    scanner->startScan (working_dir);
}

void MRLibrary::loadUI()
{
    layout = new (std::nothrow) QVBoxLayout(this);
    toolBar = new (std::nothrow) MRLibraryToolBar(this);

    tree = new (std::nothrow) MRLibraryTree(this);
    splitter = new (std::nothrow) QSplitter(Qt::Horizontal, this);
    scroll = new QScrollArea(this);
    shelf = new (std::nothrow) MRArticleShelf(scroll);
    scroll->setWidgetResizable (true);
    scroll->setWidget (shelf);
    Q_ASSERT (layout);
    Q_ASSERT (toolBar);
    Q_ASSERT (shelf);
    Q_ASSERT (tree);
    Q_ASSERT (splitter);
    splitter->addWidget (tree);
    splitter->addWidget (scroll);
    splitter->setStretchFactor (1, 1);
    layout->addWidget (toolBar, 0, Qt::AlignTop);
    layout->addWidget (splitter, 1);
    setLayout (layout);
}

void MRLibrary::loadSignals()
{
    Q_ASSERT (shelf);
    connect (shelf, &MRArticleShelf::articleItemClicked,
             this, &MRLibrary::articleClicked);
    Q_ASSERT (scanner );
    connect (scanner, &MRArticleScanner::ArticleReady,
             shelf, &MRArticleShelf::addArticleItem);
//    connect (scanner, &MRArticleScanner::folderReady,
//             tree, &MRLibraryTree::addFolder);
    connect (tree, &MRLibraryTree::showArticleInDir,
             this, &MRLibrary::refreshLibrary);
}

void MRLibrary::loadThreads()
{
    scanner = new MRArticleScanner(this);
}

void MRLibrary::refreshLibrary(const QString &relative_dir)
{
    if(relative_dir.isEmpty ())
    {

    }
    else
    {
//        MRSetting set;
//        set.initializeSetting ("config.ini");
//        QString working_dir = set.getWorkDirectory ();
//        if(relative_dir != "root")
//            working_dir += relative_dir;
        Q_ASSERT (shelf != nullptr );
        shelf->clearArticleItems ();
        Q_ASSERT (scanner != nullptr );
        scanner->startScan (relative_dir);

    }
}
