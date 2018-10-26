#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include "ui_aboutwidget.h"

class AboutWidget : public QWidget
{
	Q_OBJECT

public:
	AboutWidget(QWidget *parent = 0);
	~AboutWidget();

protected:
	virtual void closeEvent(QCloseEvent *);

private:
	Ui::AboutWidget ui;
};

#endif // ABOUTWIDGET_H
