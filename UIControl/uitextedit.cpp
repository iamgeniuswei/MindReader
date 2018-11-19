#include "uitextedit.h"
#include <QFont>
#include <QFontMetrics>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
UITextEdit::UITextEdit(QWidget *parent)
	: QTextEdit(parent)
{	
	//installEventFilter(this);
	loadUI();
}

UITextEdit::~UITextEdit()
{

}

void UITextEdit::updateFont(const QFont & font)
{	
	setFont(font);
	QFontMetrics metrics(font);
	increment = metrics.lineSpacing();
}

void UITextEdit::loadUI()
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setWordWrapMode(QTextOption::WordWrap);
	QFontMetrics metrics(this->font());
	increment = metrics.lineSpacing();
	resize(width(), metrics.height() + 10);
}

bool UITextEdit::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == this)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent* kevent = dynamic_cast<QKeyEvent*>(event);
			if (kevent == nullptr)
				return false;
			if (kevent->key() == Qt::Key_Enter || kevent->key() == Qt::Key_Return)
			{				
				this->insertPlainText("\n");
                emit sizeChanged ();
				return true;
			}
		}
	}
	return false;
}

void UITextEdit::focusOutEvent(QFocusEvent * e)
{	
	QTextEdit::focusOutEvent(e);
	emit editingFinished();	
}
