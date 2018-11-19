#ifndef UITEXTEDIT_H
#define UITEXTEDIT_H

#include <QTextEdit>
#include "uicontrol_global.h"

/**
	Class Name：UITextEdit
	Description：
	UITextEdit扩展了QTextEdit功能：
	1）不显示QScrollBar
	2) 默认显示单行文字
	3）回车键换行
	4）换行自动增加控件高度
	Author：Geniuswei
	Modify Time：2018-11-16 08:47
	Modify Description:
**/
class UICONTROLSHARED_EXPORT UITextEdit : public QTextEdit
{
	Q_OBJECT

public:
	explicit UITextEdit(QWidget *parent = 0);
	~UITextEdit();
	void updateFont(const QFont& font);

protected:
	void loadUI();
	virtual bool eventFilter(QObject *watched, QEvent *event) override;
	virtual void focusOutEvent(QFocusEvent *e) override;



signals:
    void sizeChanged();
	void editingFinished();

private:
	int increment = 0;
};

#endif // UITEXTEDIT_H
