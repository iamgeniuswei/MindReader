#ifndef UITEXTEDIT_H
#define UITEXTEDIT_H

#include <QTextEdit>
#include "uicontrol_global.h"

/**
	Class Name��UITextEdit
	Description��
	UITextEdit��չ��QTextEdit���ܣ�
	1������ʾQScrollBar
	2) Ĭ����ʾ��������
	3���س�������
	4�������Զ����ӿؼ��߶�
	Author��Geniuswei
	Modify Time��2018-11-16 08:47
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
