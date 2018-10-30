#ifndef NOTEDISPLAYER_H
#define NOTEDISPLAYER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "notecard.h"
#include "window_global.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include "widgetinterface.h"
#include <memory>
class MRArticleMetaData;
class WINDOWSHARED_EXPORT NoteDisplayer : public QScrollArea, public WidgetInterface
{
    Q_OBJECT
public:
    explicit NoteDisplayer(QWidget *parent = nullptr);
    void setArticle(std::shared_ptr<MRArticleMetaData> article_);

signals:

public slots:
    void addCard(
            int index,
                 const QString &text,
                 const QString &title = QString()                     
            );
    void addTextCard(int index,
                     const QString& text);
    void addPixmapCard(int index,
                 const QPixmap &pixmap );
protected:
    void initializeUI();
    void initializeSignal();

private:
    QVBoxLayout *layout = nullptr;
    QWidget *container = nullptr;
    QList<NoteCard*> cards;
    std::shared_ptr<MRArticleMetaData> article;
};

#endif // NOTEDISPLAYER_H
