#ifndef NOTECARD_H
#define NOTECARD_H

#include <QWidget>
#include "uiwidget.h"
#include <memory>
#include "window_global.h"
namespace Ui {
class NoteCard;
}
class MRNoteData;
class MRArticleMetaData;
class WINDOWSHARED_EXPORT NoteCard : public UIWidget
{
    Q_OBJECT

public:
    explicit NoteCard(QWidget *parent = nullptr);
    ~NoteCard();
    void setTitle(const QString& title);
    void setText(const QString& text);
    void setIndex(int index);
    void setPixmap(const QPixmap& pixmap);
    void setArticle(std::shared_ptr<MRArticleMetaData> article);

public slots:
    void test();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
//    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::NoteCard *ui;
    QPoint startPoint;
    QPoint endPoint;
    QPoint distance;
    std::shared_ptr<MRNoteData> data;
};

#endif // NOTECARD_H
