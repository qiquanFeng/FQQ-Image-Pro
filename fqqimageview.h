#ifndef FQQIMAGEVIEW_H
#define FQQIMAGEVIEW_H

#include <QDockWidget>
#include "ui_fqqimageview.h"
#include <QLabel>
#include "opencv.hpp"

class fqqImageView : public QDockWidget
{
	Q_OBJECT

public:
	fqqImageView(QString title,QWidget *parent = 0);
	~fqqImageView();

	QLabel *m_plabImage;
	void SetImage(QPixmap);
	void SetImage(cv::Mat);

protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
private:
	Ui::fqqImageView ui;

public slots:
void slot_reSize(QSize);
void slot_SelectArea();
};

#endif // FQQIMAGEVIEW_H
