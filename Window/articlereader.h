#ifndef ARTICLEREADER_H
#define ARTICLEREADER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "window_global.h"
#include "notedisplayer.h"
class ArticleDisplayer;
class ArticleDisplayerController;
class WINDOWSHARED_EXPORT ArticleReader : public QWidget
{
    Q_OBJECT
public:
    explicit ArticleReader(QWidget *parent = nullptr);

protected:
    void initializeSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
public slots:

private:
    QVBoxLayout *layout = nullptr;
    ArticleDisplayer *displayer = nullptr ;
    ArticleDisplayerController *controller = nullptr;
//    QHBoxLayout *horizontalLayout = nullptr;
//    NoteDisplayer *noteDisplayer = nullptr;
};

#endif // ARTICLEREADER_H
