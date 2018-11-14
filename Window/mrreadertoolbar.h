#ifndef MRREADERTOOLBAR_H
#define MRREADERTOOLBAR_H

#include <QWidget>
#include "uiwidget.h"
#include <QButtonGroup>
#include "mrwindowutility.h"
namespace Ui {
class MRReaderToolBar;
}

class MRReaderToolBar : public UIWidget
{
    Q_OBJECT

public:
    explicit MRReaderToolBar(QWidget *parent = nullptr);
    ~MRReaderToolBar();
    void initializeSignals();
signals:
    void hideNoteClicked();
    void backLibraryClicked();
    void cursorType(CURSOR cursor);
    void colorReady(const QColor& color);
private slots:

    void on_hand_clicked();

    void on_select_clicked();

    void on_line_clicked();

    void on_rectangle_clicked();

    void on_text_clicked();

    void on_color_clicked();

    void on_screenshot_clicked();

private:
    Ui::MRReaderToolBar *ui;
    QButtonGroup *btn_group = nullptr;
};

#endif // MRREADERTOOLBAR_H
