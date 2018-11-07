#ifndef MRMESSAGEBOX_H
#define MRMESSAGEBOX_H

#include "uidialog.h"
namespace Ui {
class MRMessageBox;
}

class MRMessageBox : public UIDialog
{
    Q_OBJECT

public:
    explicit MRMessageBox(QWidget *parent = nullptr);
    ~MRMessageBox();

private slots:
    void on_MRMBClose_clicked();

private:
    Ui::MRMessageBox *ui;
};

#endif // MRMESSAGEBOX_H
