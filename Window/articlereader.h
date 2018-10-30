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
class ArticleDisplayer;
class ArticleDisplayerController;
class MRArticleMetaData;
class WINDOWSHARED_EXPORT ArticleReader : public UIWidget
{
    Q_OBJECT
public:
    explicit ArticleReader(QWidget *parent = nullptr);

    std::shared_ptr<MRArticleMetaData> article() const;

protected:
    void initializeSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
    void cursorType(CURSOR cursor);
public slots:
    void setArticle(std::shared_ptr<MRArticleMetaData> article);
private:
    QVBoxLayout *layout = nullptr;
    ArticleDisplayer *displayer = nullptr ;
    ArticleDisplayerController *controller = nullptr;
    std::shared_ptr<MRArticleMetaData> article_;
//    QHBoxLayout *horizontalLayout = nullptr;
//    NoteDisplayer *noteDisplayer = nullptr;
};

#endif // ARTICLEREADER_H
