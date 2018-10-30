#ifndef MRARTICLEREADER_H
#define MRARTICLEREADER_H

#include <QWidget>
#include "mrreadertoolbar.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ArticleDisplayer.h"
#include "articlereader.h"
#include "notedisplayer.h"
class MRArticleMetaData;
class MRArticleReader : public QWidget
{
    Q_OBJECT
public:
    explicit MRArticleReader(QWidget *parent = nullptr);
    void initializeUI();
    void initializeSignal();
signals:
    void backToLibrary();

public slots:
    void setArticle(std::shared_ptr<MRArticleMetaData> article);

private:
    MRReaderToolBar *toolBar = nullptr;
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *subLayout = nullptr;
    ArticleReader *reader = nullptr;
    NoteDisplayer *note = nullptr;
};

#endif // MRARTICLEREADER_H
