#ifndef ARTICLEREADER_H
#define ARTICLEREADER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "uiwidget.h"
#include "window_global.h"
#include "notedisplayer.h"
#include <memory>
#include "mrwindowutility.h"
class MRArticleDisplayer;
class ArticleDisplayerController;
class MRArticleMetaData;
class MRReaderToolBar;
class QSplitter;
class WINDOWSHARED_EXPORT MRArticleReader : public UIWidget
{
    Q_OBJECT
public:
    explicit MRArticleReader(QWidget *parent = nullptr);

    std::shared_ptr<MRArticleMetaData> article() const;

protected:
    void loadUI();
    void initializeSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
    void cursorType(CURSOR cursor);
signals:
    void backToLibrary();
public slots:
    bool setArticle(std::shared_ptr<MRArticleMetaData> article);
    void resetArticle();
private:
    QVBoxLayout *layout = nullptr;
    MRArticleDisplayer *displayer = nullptr ;
    ArticleDisplayerController *controller = nullptr;
    std::shared_ptr<MRArticleMetaData> article_;
    MRReaderToolBar *toolBar = nullptr;
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *subLayout = nullptr;
    QSplitter *splitter = nullptr;
//    ArticleReader *reader = nullptr;
    QWidget *readerContainer = nullptr;
    NoteDisplayer *note = nullptr;
};

#endif // ARTICLEREADER_H
