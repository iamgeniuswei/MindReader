#ifndef READERWITHNOTE_H
#define READERWITHNOTE_H

#include <QWidget>
#include "mrarticlereader.h"
#include "notedisplayer.h"
#include <QHBoxLayout>
#include "window_global.h"
class WINDOWSHARED_EXPORT ReaderWithNote : public QWidget
{
    Q_OBJECT
public:
    explicit ReaderWithNote(QWidget *parent = nullptr);
    void initializeSignal();

signals:

public slots:
private:
    QHBoxLayout *layout = nullptr;
    MRArticleReader *reader = nullptr;
    NoteDisplayer *note = nullptr;
};

#endif // READERWITHNOTE_H
