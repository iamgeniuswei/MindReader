#ifndef NOTECARD_H
#define NOTECARD_H

#include <QWidget>

namespace Ui {
class NoteCard;
}

class NoteCard : public QWidget
{
    Q_OBJECT

public:
    explicit NoteCard(QWidget *parent = nullptr);
    ~NoteCard();

private:
    Ui::NoteCard *ui;
};

#endif // NOTECARD_H
