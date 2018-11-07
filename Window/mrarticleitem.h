#ifndef MRARTICLEITEM_H
#define MRARTICLEITEM_H

#include "uiwidget.h"
#include "window_global.h"
#include <memory>
class MRArticleMetaData;
namespace Ui {
class MRArticleItem;
}

class WINDOWSHARED_EXPORT MRArticleItem : public UIWidget
{
    Q_OBJECT

public:
    explicit MRArticleItem(QWidget *parent = nullptr);
    ~MRArticleItem();

    virtual void setTitle(const QString& text);
    void setArticle(const std::shared_ptr<MRArticleMetaData> &value);

protected:


signals:
    void articleClicked(std::shared_ptr<MRArticleMetaData> article);

public slots:

protected:
    virtual void
    paintEvent(QPaintEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

protected:

private:
    Ui::MRArticleItem *ui;
    std::shared_ptr<MRArticleMetaData> data = nullptr;
};

#endif // MRARTICLEITEM_H
