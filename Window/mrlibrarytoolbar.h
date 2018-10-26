#ifndef MRLIBRARYTOOLBAR_H
#define MRLIBRARYTOOLBAR_H

#include <QWidget>
#include "window_global.h"
namespace Ui {
class MRLibraryToolBar;
}

class WINDOWSHARED_EXPORT MRLibraryToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit MRLibraryToolBar(QWidget *parent = nullptr);
    ~MRLibraryToolBar();

private:
    Ui::MRLibraryToolBar *ui;
};

#endif // MRLIBRARYTOOLBAR_H
