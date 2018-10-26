#include "fqqconfigview.h"
#include "fqqimagepro.h"
using namespace cv;

fqqConfigView::fqqConfigView(cv::Mat& mat,ConfigType type,QWidget *parent)
	: m_srcMat(&mat),type(type)
{
	ui.setupUi(this);
	pParent = (fqqImagePro*)parent;

	ui.label_val1->setText("0");
	ui.label_val2->setText("0");
	ui.label_val3->setText("0");

	switch (type)
	{
	case fqqConfigView::FT_Sobel:
		break;
	case fqqConfigView::FT_Canny:
		ui.Slider1->setRange(0, 255);
		ui.Slider2->setRange(0, 255);
		ui.Slider3->setRange(0, 255);
		ui.Slider3->setEnabled(false);
		break;
	case fqqConfigView::FT_Blur:
		break;
	case fqqConfigView::FT_MedianBlur:
		ui.Slider1->setRange(3, 255);
		ui.label_val1->setText("3");
		ui.Slider2->setEnabled(false);
		ui.Slider3->setEnabled(false);
		break;
	default:
		break;
	}

	connect(this, SIGNAL(sig__SliderChange()), this, SLOT(slotChange(int)));

	connect(ui.Slider1, SIGNAL(valueChanged(int)), this, SLOT(slotSlider1(int)));
	connect(ui.Slider2, SIGNAL(valueChanged(int)), this, SLOT(slotSlider2(int)));
	connect(ui.Slider3, SIGNAL(valueChanged(int)), this, SLOT(slotSlider3(int)));

	connect(ui.pushButton_Save, SIGNAL(clicked()), this, SLOT(slotSave()));
}

fqqConfigView::~fqqConfigView()
{

}

void fqqConfigView::closeEvent(QCloseEvent *event) {
	pParent->m_pdockView1->SetImage(*m_srcMat);
}

void fqqConfigView::slotChange(int iValue) {
	switch (type)
	{
	case fqqConfigView::FT_Sobel:

		break;
	case fqqConfigView::FT_Canny:
	{
		double t1 = (double)ui.Slider1->value();
		double t2 = (double)ui.Slider2->value();
		Canny(*m_srcMat, dstMat, t1, t2);
		pParent->m_pdockView1->SetImage(dstMat);
	}
		break;
	case fqqConfigView::FT_Blur:
		break;
	case fqqConfigView::FT_MedianBlur:
	{
		medianBlur(*m_srcMat, dstMat, ui.Slider1->value() | 0x01);
		pParent->m_pdockView1->SetImage(dstMat);
	}
		break;
	default:
		break;
	}
	
}

void fqqConfigView::slotSave() {
	pParent->setMat(dstMat);
	close();
}