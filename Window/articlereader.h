#ifndef ARTICLEREADER_H
#define ARTICLEREADER_H

#include <QWidget>
#include <QVBoxLayout>
#include "window_global.h"
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

public slots:

private:
    QVBoxLayout *layout = nullptr;
    ArticleDisplayer *displayer = nullptr ;
    ArticleDisplayerController *controller = nullptr;
};

#endif // ARTICLEREADER_H
