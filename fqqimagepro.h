#ifndef FQQIMAGEPRO_H
#define FQQIMAGEPRO_H

#include "qt_windows.h"
#include <qmath.h>
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMenuBar>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QLabel>
#include <qdockwidget.h>
#include <QVBoxLayout>
#include <qmessagebox.h>
#include <QFileDialog>
#include <QKeyEvent>
#include <QRegExp>
#include <QFile>
#include <QCombobox>
#include "fqqbayerinfo.h"
#include "fqqconfigview.h"
#include "aboutwidget.h"
#include "fqqparticlewidget.h"

#include "../fqqImageTool/fqqImageTool.h"
#include "opencv.hpp" 
#include <vector>
#ifdef WIN32
#if _DEBUG
#pragma comment(lib,"fqqImageToolD")

#pragma comment(lib,"opencv_features2d330d.lib")
#pragma comment(lib,"opencv_imgcodecs330d.lib")
#pragma comment(lib,"opencv_objdetect330d.lib")
#pragma comment(lib,"opencv_stitching330d.lib")
#pragma comment(lib,"opencv_videostab330d.lib")
#pragma comment(lib,"opencv_superres330d.lib")
#pragma comment(lib,"opencv_calib3d330d.lib")
#pragma comment(lib,"opencv_highgui330d.lib")
#pragma comment(lib,"opencv_imgproc330d.lib")
#pragma comment(lib,"opencv_videoio330d.lib")
#pragma comment(lib,"opencv_flann330d.lib")
#pragma comment(lib,"opencv_photo330d.lib")
#pragma comment(lib,"opencv_shape330d.lib")
#pragma comment(lib,"opencv_video330d.lib")
#pragma comment(lib,"opencv_core330d.lib")
#pragma comment(lib,"opencv_dnn330d.lib")
#pragma comment(lib,"opencv_ml330d.lib")
#else
#pragma comment(lib,"fqqImageTool")

#pragma comment(lib,"opencv_calib3d330.lib")
#pragma comment(lib,"opencv_core330.lib")
#pragma comment(lib,"opencv_dnn330.lib")
#pragma comment(lib,"opencv_features2d330.lib")
#pragma comment(lib,"opencv_flann330.lib")
#pragma comment(lib,"opencv_highgui330.lib")
#pragma comment(lib,"opencv_imgcodecs330.lib")
#pragma comment(lib,"opencv_imgproc330.lib")
#pragma comment(lib,"opencv_ml330.lib")
#pragma comment(lib,"opencv_objdetect330.lib")
#pragma comment(lib,"opencv_photo330.lib")
#pragma comment(lib,"opencv_shape330.lib")
#pragma comment(lib,"opencv_stitching330.lib")
#pragma comment(lib,"opencv_superres330.lib")
#pragma comment(lib,"opencv_video330.lib")
#pragma comment(lib,"opencv_videoio330.lib")
#pragma comment(lib,"opencv_videostab330.lib")

#endif
#else
#if _DEBUG
#pragma comment(lib,"fqqImageToolD.lib")
#pragma comment(lib,"opencv_world330d")
#else
#pragma comment(lib,"opencv_world330")
#pragma comment(lib,"fqqImageTool")
#endif
#endif



#include "ui_fqqimagepro.h"
#include "fqqimageview.h"

using namespace cv;

class fqqImagePro : public QMainWindow
{
	Q_OBJECT

public:
	fqqImagePro(QWidget *parent = 0);
	~fqqImagePro();

	

	fqqImageView *m_pdockView1;
	fqqConfigView *m_configView_Canny;
	fqqBayerInfo *m_bayerInfoView;
	fqqParticleWidget *m_particleView;

	Point3f m_OC;

	QVBoxLayout *layout;
	cv::Mat m_srcMat;
	cv::Mat m_dumpMat;
	cv::Mat m_dstMat;
	cv::Mat m_ShadingMat;

	_inline void setMat(cv::Mat mat) {
		m_dumpMat = m_srcMat.clone();
		m_srcMat = mat.clone();
		m_pdockView1->SetImage(m_srcMat);
	}
protected:
	virtual bool eventFilter(QObject *watched, QEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
	

private:
	Ui::fqqImageProClass ui;
	
signals:
	void sig_reSize(QSize);

public slots:
	void slotMenu_About(bool);
	void slotMenu_Open(bool);
	void slotMenu_OpenVideo(bool);
	void slotMenu_OpenCamera(bool);
	void slotMenu_AsSave(bool);
	//void slotMenu_Close(bool);

	//*********  Tool menu *********
	void slotMenu_Gray(bool);
	void slotMenu_Sobel(bool);
	void slotMenu_Canny(bool);
	void slotMenu_MedianBlur(bool);
	void slotMenu_Histogram(bool);
	void slotMenu_ShadingCorrection(bool);
	void slotMenu_OpticalCenter(bool);
	void slotMenu_OpticalCenter2(bool);
	void slotMenu_AlgCanny(bool);
	void slotMenu_MTF(bool);
	void slotMenu_Positioning(bool);

	_inline void slotMenu_EqualizeHist(bool) {
		m_dstMat = m_srcMat.clone();
		if (m_dstMat.channels() == 3)
		{
			cvtColor(m_dstMat, m_dstMat, COLOR_BGR2GRAY);
		}
		equalizeHist(m_dstMat, m_dstMat);
		setMat(m_dstMat);
	}
	_inline void slotMenu_Particle(bool) {
		m_particleView->show();
	}

	void slotMenu_SelectArea(bool);
};

#endif // FQQIMAGEPRO_H
