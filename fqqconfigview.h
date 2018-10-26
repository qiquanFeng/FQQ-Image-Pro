#ifndef FQQCONFIGVIEW_H
#define FQQCONFIGVIEW_H

#include <QWidget>
#include "ui_fqqconfigview.h"
#include "opencv.hpp"

class fqqImagePro;

class fqqConfigView : public QWidget
{
	Q_OBJECT

public:
	enum ConfigType {
		FT_Sobel = 0,
		FT_Canny,
		FT_Blur,
		FT_MedianBlur
	};

	fqqConfigView(cv::Mat&,ConfigType,QWidget *parent = 0);
	~fqqConfigView();

	fqqImagePro *pParent;
	cv::Mat *m_srcMat;
	cv::Mat dstMat;
	ConfigType type;

protected:
	virtual void closeEvent(QCloseEvent *event);
	
private:
	Ui::fqqConfigView ui;

signals:
	void sig__SliderChange();

public slots:
void slotChange(int);
void slotSave();

_inline void slotSlider1(int iValue) {
	ui.label_val1->setText(QString::number(iValue));
	slotChange(iValue);
}
_inline void slotSlider2(int iValue) {
	ui.label_val2->setText(QString::number(iValue));
	slotChange(iValue);
}
_inline void slotSlider3(int iValue) {
	ui.label_val3->setText(QString::number(iValue));
	slotChange(iValue);
}


};

#endif // FQQCONFIGVIEW_H
