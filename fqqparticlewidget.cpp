#include "fqqparticlewidget.h"
#include "fqqimagepro.h"

fqqParticleWidget::fqqParticleWidget(QWidget *parent):m_pParent((fqqImagePro*)parent)
//: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_Test, SIGNAL(clicked()), this, SLOT(slot_Test()));
	connect(ui.pushButton_Save, SIGNAL(clicked()), this, SLOT(slot_Save()));
}

fqqParticleWidget::~fqqParticleWidget()
{

}

void fqqParticleWidget::slot_Test() {
	Mat m_dstMat;
	m_dstMat = m_pParent->m_srcMat.clone();
	if (m_dstMat.channels() == 3)
		cvtColor(m_dstMat, m_dstMat, COLOR_BGR2GRAY);

	Mat particleMat(ceil(m_dstMat.rows / 8), ceil(m_dstMat.cols / 8), CV_32FC1);

	FILE *file;
	fopen_s(&file, "D:\\ParticleTest.csv","wb+");
	
	
	int roiWidth = 8, roiHeight = 8;
	for (int r = 0; r < m_dstMat.rows; r += roiHeight)
	{
		for (int c = 0; c < m_dstMat.cols; c += roiWidth)
		{
			int ROIcol = roiWidth, ROIrow = roiHeight;
			if (c + ROIcol > m_dstMat.cols) {
				ROIcol = m_dstMat.cols - c;
			}
			if (r + ROIrow > m_dstMat.rows) {
				ROIrow = m_dstMat.rows - r;
			}

			double minVal = 0.0f, maxVal = 0.0f;
			//cv::minMaxIdx(m_dstMat(Rect(c, r, ROIcol, ROIrow)),&minVal,&maxVal);
			//particleMat.at<float>(r / roiHeight, c / roiWidth) = maxVal;
			particleMat.at<float>(r / roiHeight, c / roiWidth) = mean(m_dstMat(Rect(c, r, ROIcol, ROIrow))).val[0];
			fprintf(file, "%f,", particleMat.at<float>(r / roiHeight, c / roiWidth));
		}
		fprintf(file, "\n");
	}
	fclose(file);

	Mat particleMat_3x3 = particleMat.clone();
	blur(particleMat_3x3, particleMat_3x3, Size(3, 3));
	Mat particleMat_result(particleMat.rows, particleMat.cols, CV_8SC1);
	cv::subtract(particleMat_3x3, particleMat, particleMat_result);

	double minVal = 0.0f, maxVal = 0.0f;
	cv::minMaxIdx(particleMat_result, &minVal, &maxVal);
	

	Mat particleMat1 = particleMat(Rect(0, 0, ceil(particleMat.cols / 2), ceil(particleMat.rows / 2)));
	Mat particleMat2 = particleMat(Rect(floor(particleMat.cols / 2), 0, particleMat.cols - floor(particleMat.cols / 2), ceil(particleMat.rows / 2)));
	Mat particleMat3 = particleMat(Rect(0, floor(particleMat.rows / 2), ceil(particleMat.cols / 2), particleMat.rows - floor(particleMat.rows / 2)));
	Mat particleMat4 = particleMat(Rect(floor(particleMat.cols / 2), floor(particleMat.rows / 2), \
		particleMat.cols - floor(particleMat.cols / 2), particleMat.rows - floor(particleMat.rows / 2)));

	particleMat1.convertTo(particleMat1, CV_8UC1);
	particleMat2.convertTo(particleMat2, CV_8UC1);
	particleMat3.convertTo(particleMat3, CV_8UC1);
	particleMat4.convertTo(particleMat4, CV_8UC1);
	particleMat.convertTo(particleMat, CV_8UC1);
	
	/*rectangle(particleMat, Rect(0, 0, ceil(particleMat.cols / 2), ceil(particleMat.rows / 2)),Scalar(0,0,0),1	);
	rectangle(particleMat, Rect(floor(particleMat.cols / 2), 0, particleMat.cols - floor(particleMat.cols / 2), ceil(particleMat.rows / 2)), Scalar(0, 0, 0,0),1);
	rectangle(particleMat, Rect(0, floor(particleMat.rows / 2), ceil(particleMat.cols / 2), particleMat.rows - floor(particleMat.rows / 2)), Scalar(0, 0, 0,0),1);
	rectangle(particleMat, Rect(floor(particleMat.cols / 2), floor(particleMat.rows / 2), \
		particleMat.cols - floor(particleMat.cols / 2), particleMat.rows - floor(particleMat.rows / 2)), Scalar(0, 0, 0),1);
	*/
	m_pParent->setMat(particleMat_result);
}
