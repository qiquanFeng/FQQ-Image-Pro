#include "fqqimagepro.h"

#define CHECK_OPENIMGAGE if (m_srcMat.data == NULL){QMessageBox::warning(this, "Error", "Image Not Open.");return;}m_dstMat.release();m_dumpMat.release();

using namespace cv;
using namespace std;

int graythresh(Mat &mat);
float GetDistance(Point2f p1, Point2f p2);
float ComputeVariance(std::vector<cv::Point> theContour, Point2f theCenter);
std::vector<Point3f> FindCircles(Mat img, int minPoints, int maxOffset, int minr, int maxr);


fqqImagePro::fqqImagePro(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("ImageTool v1.0.0.0");
	this->setWindowIcon(QIcon(":/fqqImagePro/Resources/Login.ico"));

	m_bayerInfoView = new fqqBayerInfo();
	m_particleView = new fqqParticleWidget(this);
	//****************** Initial Layout ******************
	ui.mainToolBar->setVisible(false);

	QMenu *menuFile = menuBar()->addMenu(tr("File"));
	QMenu *menuVideo = menuBar()->addMenu(tr("Video"));
	QMenu *menuTool = menuBar()->addMenu(tr("Tool"));
	QMenu *menuImage = menuBar()->addMenu(tr("Image"));
	QMenu *menuHelp = menuBar()->addMenu(tr("Help"));

	QList<QAction*> menuFile_List;
	menuFile_List.push_back(new QAction("Open"));
	menuFile_List.push_back(new QAction("AsSave"));
	menuFile_List.push_back(new QAction("Close"));
	connect(menuFile_List.at(0), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Open(bool)));
	connect(menuFile_List.at(1), SIGNAL(triggered(bool)), this, SLOT(slotMenu_AsSave(bool)));
	//connect(menuFile_List.at(2), SIGNAL(triggered(bool)), this, SLOT());
	menuFile->addActions(menuFile_List);

	QList<QAction*> menuVideo_List;
	menuVideo_List.push_back(new QAction("Open"));
	menuVideo_List.push_back(new QAction("OpenCamera"));
	connect(menuVideo_List.at(0), SIGNAL(triggered(bool)), this, SLOT(slotMenu_OpenVideo(bool)));
	connect(menuVideo_List.at(1), SIGNAL(triggered(bool)), this, SLOT(slotMenu_OpenCamera(bool)));
	menuVideo->addActions(menuVideo_List);

	QList<QAction*> menuTool_List;
	menuTool_List.push_back(new QAction(tr("ToGray")));
	menuTool_List.push_back(new QAction(tr("Sobel")));
	menuTool_List.push_back(new QAction(tr("Canny")));
	menuTool_List.push_back(new QAction(tr("Split")));
	menuTool_List.push_back(new QAction(tr("MedianBlur")));
	menuTool_List.push_back(new QAction(tr("Histogram")));
	menuTool_List.push_back(new QAction(tr("Particle")));
	menuTool_List.push_back(new QAction(tr("EqualizeHist")));
	menuTool_List.push_back(new QAction(tr("Shading Correction")));
	menuTool_List.push_back(new QAction(tr("Optical Center")));
	menuTool_List.push_back(new QAction(tr("Demosaic")));
	menuTool_List.push_back(new QAction(tr("MTF")));
	menuTool_List.push_back(new QAction(tr("Mark")));
	menuTool_List.push_back(new QAction(tr("Optical Center2")));

	connect(menuTool_List.at(0), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Gray(bool)));
	connect(menuTool_List.at(1), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Sobel(bool)));
	connect(menuTool_List.at(2), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Canny(bool)));
	connect(menuTool_List.at(4), SIGNAL(triggered(bool)), this, SLOT(slotMenu_MedianBlur(bool)));
	connect(menuTool_List.at(5), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Histogram(bool)));
	connect(menuTool_List.at(6), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Particle(bool)));
	connect(menuTool_List.at(7), SIGNAL(triggered(bool)), this, SLOT(slotMenu_EqualizeHist(bool)));
	connect(menuTool_List.at(8), SIGNAL(triggered(bool)), this, SLOT(slotMenu_ShadingCorrection(bool)));
	connect(menuTool_List.at(9), SIGNAL(triggered(bool)), this, SLOT(slotMenu_OpticalCenter(bool)));
	connect(menuTool_List.at(10), SIGNAL(triggered(bool)), this, SLOT(slotMenu_MTF(bool)));
	connect(menuTool_List.at(11), SIGNAL(triggered(bool)), this, SLOT(slotMenu_MTF(bool)));
	connect(menuTool_List.at(12), SIGNAL(triggered(bool)), this, SLOT(slotMenu_Positioning(bool)));
	connect(menuTool_List.at(13), SIGNAL(triggered(bool)), this, SLOT(slotMenu_OpticalCenter2(bool)));
	menuTool->addActions(menuTool_List);

	QList<QAction*> menuHelp_List;
	menuHelp_List.push_back(new QAction("About"));
	connect(menuHelp_List.at(0), SIGNAL(triggered(bool)), this, SLOT(slotMenu_About(bool)));
	menuHelp->addActions(menuHelp_List);


	m_pdockView1 = new fqqImageView("View1", this);
	addDockWidget(Qt::LeftDockWidgetArea, m_pdockView1);
	
	connect(this, SIGNAL(sig_reSize(QSize)), m_pdockView1, SLOT(slot_reSize(QSize)));

	//************************* Tool Bar **********************
	QAction *action_SelectROI = new QAction(QIcon(":/fqqImagePro/Resources/Login.ico"),tr("select Area"));

	connect(action_SelectROI, SIGNAL(triggered(bool)), this, SLOT(slotMenu_SelectArea(bool)));
	QToolBar *toolbar1=new QToolBar(this);
	toolbar1->addAction(action_SelectROI);
	addToolBar(Qt::LeftToolBarArea,toolbar1);
	//*****************************************************
}

fqqImagePro::~fqqImagePro()
{

}



void fqqImagePro::keyPressEvent(QKeyEvent *event) {
	if (event->modifiers()&Qt::ControlModifier) {
		if (event->key() == Qt::Key_Z) {
			m_srcMat = m_dumpMat.clone();
			m_pdockView1->SetImage(m_srcMat);
		}

		if (event->key() == Qt::Key_O) {
			slotMenu_Open(false);
		}

		if (event->key() == Qt::Key_S) {
			slotMenu_AsSave(false);
		}
	}
}

bool fqqImagePro::eventFilter(QObject *watched, QEvent *event) {
	if (event->type() == QEvent::Type::WindowStateChange) {
		emit sig_reSize(size());
	}
	return QMainWindow::eventFilter(watched, event);
}

void fqqImagePro::slotMenu_Open(bool bstate) {
	QString strFilePath=QFileDialog::getOpenFileName(this, "Open Image File", "", "BMP File|(*.BMP)\nRAW File|(*.RAW)\nJPG File|(*.JPG)\n");
	if (strFilePath.isEmpty())
	{
		return;
	}

	int index=strFilePath.lastIndexOf(QRegExp(".raw",Qt::CaseInsensitive));
	if(index<0){
		m_srcMat =imread(strFilePath.toLocal8Bit().toStdString());
	}
	else {
		m_bayerInfoView->exec();

		QFile file(strFilePath);
		file.open(QIODevice::ReadOnly);
		QByteArray buffer=file.readAll();
		file.close();

		int iWidth = m_bayerInfoView->GetUI().spinBox_Width->value();
		int iHeight = m_bayerInfoView->GetUI().spinBox_Height->value();
		QString strBayerOrder = m_bayerInfoView->GetUI().comboBox_BayerOrder->currentText();
		int blacklevel = m_bayerInfoView->GetUI().spinBox_BlackLevel->value();
		m_srcMat = Mat(iHeight/2, iWidth/2, CV_8UC3);

		if (m_bayerInfoView->GetUI().comboBox_Type->currentText() == "Raw10") {
			if (iWidth*iHeight * 2 !=buffer.size()) {
				QMessageBox::warning(this, "Input Error", "Image Size!");
				return;
			}

			unsigned short *uspBuffer = (unsigned short *)buffer.data();

			if (strBayerOrder == "RGGB") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r+1)*iWidth + (c+1)) >> 2;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c + 1)) + *(uspBuffer + (r + 1)*iWidth + (c))) >> 3;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r)*iWidth + (c)) >> 2;
					}
				}
			}
			else if (strBayerOrder == "GRBG") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r+1)*iWidth + (c)) >> 2;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c)) + *(uspBuffer + (r + 1)*iWidth + (c+1))) >> 3;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r)*iWidth + (c+1)) >> 2;
					}
				}
			}
			else if (strBayerOrder == "GBRG") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r)*iWidth + (c+1)) >> 2;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c)) + *(uspBuffer + (r + 1)*iWidth + (c+1))) >> 3;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r+1)*iWidth + (c)) >> 2;
					}
				}
			}
			else if (strBayerOrder == "BGGR") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r)*iWidth + (c)) >>2;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c + 1)) + *(uspBuffer + (r + 1)*iWidth + (c))) >>3;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r + 1)*iWidth + (c+1)) >>2;
					}
				}
			}
		}
		else {
			if (iWidth*iHeight != buffer.size()) {
				QMessageBox::warning(this, "Input Error", "Image Size!");
				return;
			}

			unsigned char *uspBuffer = (unsigned char *)buffer.data();

			if (strBayerOrder == "RGGB") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r + 1)*iWidth + (c + 1));
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c + 1)) + *(uspBuffer + (r + 1)*iWidth + (c))) >> 1;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r)*iWidth + (c));
					}
				}
			}
			else if (strBayerOrder == "GRBG") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r + 1)*iWidth + (c));
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c)) + *(uspBuffer + (r + 1)*iWidth + (c + 1))) >> 1;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r)*iWidth + (c + 1));
					}
				}
			}
			else if (strBayerOrder == "GBRG") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r)*iWidth + (c + 1));
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c)) + *(uspBuffer + (r + 1)*iWidth + (c + 1))) >> 1;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r + 1)*iWidth + (c));
					}
				}
			}
			else if (strBayerOrder == "BGGR") {
				for (int r = 0; r < iHeight; r += 2)
				{
					for (int c = 0; c < iWidth; c += 2)
					{
						m_srcMat.at<Vec3b>(r / 2, c / 2)[0] = *(uspBuffer + (r)*iWidth + (c));
						m_srcMat.at<Vec3b>(r / 2, c / 2)[1] = (*(uspBuffer + (r)*iWidth + (c + 1)) + *(uspBuffer + (r + 1)*iWidth + (c))) >> 1;
						m_srcMat.at<Vec3b>(r / 2, c / 2)[2] = *(uspBuffer + (r + 1)*iWidth + (c + 1));
					}
				}
			}
		}
	}

	m_pdockView1->setWindowTitle(strFilePath);
	m_pdockView1->SetImage(m_srcMat);
}

void fqqImagePro::slotMenu_OpenVideo(bool bstate) {
	QString strFilePath = QFileDialog::getOpenFileName(this, "Open Video File", "", "AVI File|(*.AVI)\nMP4 File|(*.MP4)\n");
	if (strFilePath.isEmpty())
	{
		return;
	}

	VideoCapture capture(0);
	if (!capture.isOpened())
		return ;
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	Mat frame;

	namedWindow("Canny Video", CV_WINDOW_AUTOSIZE);
	int delay = 1000 / rate;

	while (!stop)
	{
		if (!capture.read(frame)) {
			break;
		}
			
		Mat result;
		Canny(frame, result, 100, 200);
		threshold(result, result, 128, 255, THRESH_BINARY);
		//imshow("Canny Video", frame);

		m_pdockView1->setWindowTitle(strFilePath);
		m_pdockView1->SetImage(result);

		if (waitKey(delay) >= 0)
			stop = false;
	}

}

void fqqImagePro::slotMenu_OpenCamera(bool bstate) {
	VideoCapture cap(0);
	if (!cap.isOpened())
		return;

	Mat frame;
	while (1) {
		cap >> frame;
		if (frame.empty())
			break;
		Canny(frame, frame, 150, 30);
		setMat(frame);
		imshow("test", frame);
		if(waitKey(30)>0)
			break;
	}
	cap.release();
	destroyAllWindows();
}

void fqqImagePro::slotMenu_Gray(bool bstate) {
	CHECK_OPENIMGAGE

	cvtColor(m_srcMat, m_dstMat, COLOR_BGR2GRAY);
	setMat(m_dstMat);
}

void fqqImagePro::slotMenu_AsSave(bool bstate) {
	CHECK_OPENIMGAGE

	QString strFilePath = QFileDialog::getSaveFileName(this, "Save To Image", QDir::currentPath(), "BMP File|(*.BMP)\nRAW File|(*.RAW)");
	
	if (strFilePath.lastIndexOf(QRegExp(".raw", Qt::CaseInsensitive)) > 0) {
		QMessageBox::warning(this, "Error", QString::fromLocal8Bit("暂不支持Raw格式保存！"));
		return;
	}
	else {
		if (!imwrite(strFilePath.toLocal8Bit().toStdString(), m_srcMat)) {
			QMessageBox::warning(this, "Save Error", "Save Image Fail !");
		}
	}
}

void fqqImagePro::slotMenu_Sobel(bool bstate) {
	CHECK_OPENIMGAGE
	cv::Sobel(m_srcMat, m_dstMat, m_srcMat.depth(),1,1);
	setMat(m_dstMat);
}

void fqqImagePro::slotMenu_Canny(bool bstate) {
	CHECK_OPENIMGAGE
	m_configView_Canny=new fqqConfigView(m_srcMat,fqqConfigView::FT_Canny,this);
	m_configView_Canny->show();
}

void fqqImagePro::slotMenu_MedianBlur(bool bstate) {
	CHECK_OPENIMGAGE

	m_configView_Canny = new fqqConfigView(m_srcMat, fqqConfigView::FT_MedianBlur, this);
	m_configView_Canny->show();
}

void fqqImagePro::slotMenu_About(bool bstate) {
	AboutWidget *aboutwidget=new AboutWidget();
	aboutwidget->show();
}

void fqqImagePro::slotMenu_Histogram(bool bstate) {
	CHECK_OPENIMGAGE
	Mat outMat[3];
	split(m_srcMat, outMat);

	MatND b_hist, g_hist, r_hist;
	const int histSize = 256;
	float range[] = { 0,255};
	const float *ranges[] = { range };
	const int channels = 0;

	calcHist(&outMat[0], 1, &channels, Mat(), b_hist, 1, &histSize, &ranges[0], true, false);
	calcHist(&outMat[1], 1, &channels, Mat(), g_hist, 1, &histSize, &ranges[0], true, false);
	calcHist(&outMat[2], 1, &channels, Mat(), r_hist, 1, &histSize, &ranges[0], true, false);


	Mat disMat(300, 512, CV_8UC3);
	int w_bin = disMat.cols / histSize+0.5f;
	int hist_h = disMat.rows;
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	
	for (int i=1;i<256;i++)
	{
		line(disMat, Point((i - 1)*w_bin, hist_h - b_hist.at<float>(i - 1)), \
			Point((i)*w_bin, hist_h - b_hist.at<float>(i)), Scalar(255, 0, 0), 2,1);
		line(disMat, Point((i - 1)*w_bin, hist_h - g_hist.at<float>(i - 1)), \
			Point((i)*w_bin, hist_h - g_hist.at<float>(i)), Scalar(0, 255, 0), 2, 1);
		line(disMat, Point((i - 1)*w_bin, hist_h - r_hist.at<float>(i - 1)), \
			Point((i)*w_bin, hist_h - r_hist.at<float>(i)), Scalar(0, 0, 255), 2, 1);
	}

	imshow("Histogram", disMat);
}

void fqqImagePro::slotMenu_OpticalCenter(bool bstate) {
	CHECK_OPENIMGAGE
		if (m_srcMat.channels() > 1) {
			cvtColor(m_srcMat, m_dstMat, COLOR_BGR2GRAY);
		}
		else {
			m_dstMat = m_srcMat.clone();
		}
	GaussianBlur(m_dstMat, m_dstMat, Size(3, 3), 2, 2);
	//int idx = graythresh(m_dstMat);
	double minv=0.0f, maxv = 0.0f;
	minMaxIdx(m_dstMat,NULL,&maxv);
	int idx = int(maxv*0.9+0.5f);
	//imshow("test", m_dstMat);
	//waitKey(5);

	threshold(m_dstMat, m_dstMat, idx, 255, THRESH_BINARY);
	Mat mat=getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(5, 5));
	//cv::erode(m_dstMat, m_dstMat, mat);
	//cv::dilate(m_dstMat, m_dstMat,mat);

	int minr = 0;
	int maxr = 100;
	vector<Point3f> circles = FindCircles(m_dstMat, 300, 5000, 50, 3000);//检测结果  
	for (int i = 0; i < circles.size(); i++)
	{
		circle(m_dstMat, Point(circles[i].x, circles[i].y), circles[i].z, Scalar(255, 255, 255), 2, 8, 0);
		m_OC.x = circles[i].x; m_OC.y = circles[i].y; m_OC.z = circles[i].z;
		
		//putText(m_srcMat, QString("X:%1,Y:%2").arg(circles[i].x).arg(circles[i].y).toLatin1().data(),\
			Point(circles[i].x, circles[i].y), cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(0, 255, 255));
		QMessageBox::warning(this, "Optical Center", QString("X:%1,Y:%2").arg(circles[i].x).arg(circles[i].y));
		circle(m_dstMat, Point(m_dstMat.cols/2, m_dstMat.rows / 2), 6, Scalar(0, 0, 0), -1);
		//circle(m_dstMat, Point(m_dstMat.cols / 2, m_dstMat.rows / 2), circles[i].z, Scalar(255, 255, 255), 2, 8, 0);

		circle(m_dstMat, Point(circles[i].x, circles[i].y), 3, Scalar(0, 0, 0), -1);
	}
	namedWindow("win", CV_WINDOW_NORMAL);
	imshow("win", m_dstMat);
	waitKey();

	setMat(m_srcMat);
	
	
	/*
	Mat tempMap = Mat::zeros(m_dstMat.size(), CV_8UC3);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(m_dstMat, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (int i=0;i<contours.size();i++)
	{
		drawContours(m_srcMat, contours, i, Scalar(0,0,255), 1, 8);
	}
	
	imshow("dest", m_srcMat);
	setMat(m_srcMat);
	*/
}

void fqqImagePro::slotMenu_OpticalCenter2(bool bstate) {
	CHECK_OPENIMGAGE
#if 0
	Mat mat = Mat::zeros(2448,3264, CV_8UC1);
	circle(mat, Point(mat.cols / 2, mat.rows / 2), 300, Scalar(255), -1, 8);

	for (int i = 0; i < 800; i++)
	{
		int x = std::rand() % mat.cols;
		int y = std::rand() % mat.rows;
		circle(mat, Point(x, y), 3, Scalar(std::rand() % 100 + 155), -1, 8);
	}
	m_srcMat = mat;
#endif
		Mat channels[3];
		if (m_srcMat.channels() != 1) {
			//cvtColor(m_srcMat, m_dstMat, COLOR_BGR2GRAY);
			split(m_srcMat, channels);
			m_dstMat = channels[1];
		}
		else {
			m_dstMat = m_srcMat.clone();
		}

		
		int ox_X=0,ox_Y=0;
		
		fqq::opticalCenter((char*)channels[1].data, m_dstMat.cols, m_dstMat.rows, ox_X, ox_Y,true);

		double dflMaxDCV = 0;
		minMaxIdx(m_dstMat, NULL, &dflMaxDCV);
		int bwIdx = int((double)dflMaxDCV*0.9f + 0.5f);
		//threshold(m_dstMat, m_dumpMat, int(dflMaxDCV*0.9f+0.5f), 255, THRESH_BINARY);

		unsigned __int64 sumX = 0;
		unsigned __int64 sumY = 0;
		unsigned __int64 sums = 0;
		unsigned __int64 nX = 0, nY = 0;
		int index = 0, minidx = 2000;
		m_dumpMat = m_dstMat.clone();
		for (int r=0;r<m_dstMat.rows;r++)
		{
			for (int c=0;c<m_dstMat.cols;c++)
			{
				uchar ucVal = m_dstMat.at<uchar>(r, c);
				if (ucVal >= bwIdx) {
					sumX += ucVal*(c + 1);
					sumY += ucVal*(r + 1);
					sums += ucVal;

					nX += (c+1);
					nY += (r+1);
					index++;
				}
				else {
					m_dumpMat.at<uchar>(r, c) = 0;
				}
			}
		}

		double ocX_rlg = nX / index;
		double ocY_rlg = nY / index;
		double ocX = sumX / sums;
		double ocY = sumY / sums;

		

		circle(m_dumpMat, Point(m_OC.x, m_OC.y), m_OC.z, Scalar(255), 3, 8);
		QString str = QString("JSL :oc_X:%1 oc_Y:%2").arg(int(m_OC.x+0.5f)).arg(int(m_OC.y+0.5f));
		putText(m_dumpMat,str.toLatin1().data(), \
			Point(100, 200), cv::HersheyFonts::FONT_HERSHEY_SIMPLEX, 3, Scalar(255));
		str = QString("Moto:oc_X:%1 oc_Y:%2").arg(ocX).arg(ocY);
		putText(m_dumpMat, str.toLatin1().data(), \
			Point(100, 300), cv::HersheyFonts::FONT_HERSHEY_SIMPLEX, 3, Scalar(255));
		str = QString("RLG :oc_X:%1 oc_Y:%2").arg(ocX_rlg).arg(ocY_rlg);
		putText(m_dumpMat, str.toLatin1().data(), \
			Point(100, 400), cv::HersheyFonts::FONT_HERSHEY_SIMPLEX, 3, Scalar(255));

		circle(m_dumpMat, Point(m_OC.x, m_OC.y), 1, Scalar(255), 3, 8);
		circle(m_dumpMat, Point(ocX,ocY), 1, Scalar(255), 3, 8);
		circle(m_dumpMat, Point(ocX_rlg,ocY_rlg), 1, Scalar(255), 3, 8);

		setMat(m_dumpMat);
		

		//QMessageBox::warning(this, "OC_MoTo", QString("ocX_Mt:%1|ocY_Mt:%2\nocX_rlg:%3|ocY_rlg:%4").arg(ocX).arg(ocY).arg(ocX_rlg).arg(ocY_rlg));
		
		

		//imwrite("D:\\oc_Test4.bmp", mat);
		
}

void fqqImagePro::slotMenu_AlgCanny(bool bstate) {
	CHECK_OPENIMGAGE


}

void fqqImagePro::slotMenu_MTF(bool bstate) {
	CHECK_OPENIMGAGE
	if (m_srcMat.channels() != 1) {
		cvtColor(m_srcMat, m_dstMat, CV_BGR2GRAY);
	}
	else {
		m_dstMat = m_srcMat.clone();
	}

	RECT stRange;
	stRange.left = 500;
	stRange.right = 700;
	stRange.top = 500;
	stRange.bottom = 700;

	int m = stRange.right - stRange.left - 2, n = stRange.bottom - stRange.top - 2;
	m = ((m >> 2) << 2);
	stRange.right = stRange.left + 2 + m;
	int w = (stRange.right - stRange.left)*(stRange.bottom - stRange.top);

	uchar* pflGray = (uchar*)_aligned_malloc(w * sizeof(uchar), 64);
	if (!pflGray)	return;

	memcpy(pflGray, m_dstMat(cv::Rect(stRange.left, stRange.right, stRange.right - stRange.left, stRange.bottom - stRange.top)).data, \
		w * sizeof(uchar));
	

	__declspec(align(64)) unsigned int uiHistogram[256];
	__declspec(align(64)) unsigned int uiHistogramV[256];
	memset(uiHistogram, 0, 256 * sizeof(unsigned int));
	memset(uiHistogramV, 0, 256 * sizeof(unsigned int));
	float* pflValue = new float[m*n * 2];
	float* pflValueV = new float[m*n * 2];
	int x = stRange.right - stRange.left;
	int i, iCount = 0, iLoop = (m >> 2), a1 = x + 2, a2 = x + x, a3 = x + x + 1, a4 = x + x + 2, a5 = x;
	__m128 stH, stV, st45, st145, stData1, stData2, stData3, stData4, stData5, stData6, stData7, stData8, stabs, stMax;
	stabs.m128_u32[0] = stabs.m128_u32[1] = stabs.m128_u32[2] = stabs.m128_u32[3] = 0x7FFFFFFF;
	float *pflMax, *pflDes = pflValue, /**pflSrc = pflGray,*/ flThreshold = 3.0f; //spec
	__m128 sttemp, stthreshold = _mm_set1_ps(flThreshold); //spec
	double dflSumH = 0.0, dflSumV = 0.0;
	unsigned int uiCountH = 0, uiCountV = 0;
	float* pflDesV = pflValueV, flMaxData;

	setMat(m_dstMat(cv::Rect(stRange.left, stRange.right, stRange.right - stRange.left, stRange.bottom - stRange.top)));
}

void fqqImagePro::slotMenu_Positioning(bool bstate) {
	CHECK_OPENIMGAGE
	
	double BufferX[1024], BufferY[1024], ParaK[9]; //  8次拟合, 一共9个系数(包含常数项)  									   // 读入要拟合的数据  
	BufferX[0] = 1; BufferY[0] = 1;
	BufferX[1] = 3; BufferY[1] = 3;
	BufferX[2] = 5; BufferY[2] = 5;
	BufferX[3] = 7; BufferY[3] = 7;
	BufferX[4] = 9; BufferY[4] = 8;
	BufferX[5] = 11; BufferY[5] = 9;
	BufferX[6] = 13; BufferY[6] = 10;
	BufferX[7] = 15; BufferY[7] = 7;
	BufferX[8] = 17; BufferY[8] = 5;
	BufferX[9] = 19; BufferY[9] = 3;

	fqq::polyfit(BufferX, BufferY, 10, 9, ParaK);

	double NewBufferX[20] = { 0 };
	double NewBufferY[20] = { 0 };
	for (int i=0;i<20;i++)
	{
		NewBufferX[i] = i;
	}
	fqq::polyval(NewBufferX, NewBufferY, 20, ParaK, 9);

	QFile pfile("D:\\OC_RGB24.bin");
	pfile.open(QIODevice::ReadOnly);
	QByteArray arrBuffer = pfile.readAll();
	pfile.close();

	//uchar *pDstBuffer=(uchar*)malloc(3264*2448*3);
	//INT result = fqq::getMarkDistance_RGB24(arrBuffer.data(), pDstBuffer, 3264, 2448, 15, 15000, 25000);
	double pflDebug[5] = { 0 };
	fqq::getMarkDistance(m_srcMat,pflDebug, 15, 15000, 50000,400,1000,TRUE);
	//m_pdockView1->SetImage(QPixmap::fromImage(QImage(pDstBuffer, 3264, 2448, QImage::Format_RGB888)));
	//cv::resize(m_srcMat, m_dstMat, Size(m_srcMat.cols / 4 + 0.5f, m_srcMat.rows / 4 + 0.5f));
	setMat(m_srcMat);
	/*cvtColor(m_srcMat.clone(), m_dstMat, COLOR_BGR2GRAY);
	m_dstMat = 255 - m_dstMat;
	//GaussianBlur(m_dstMat, m_dstMat, Size(9, 9),0,0);
	vector<Vec3f> circles;
	threshold(m_dstMat, m_dstMat, graythresh(m_dstMat), 255, THRESH_BINARY);
	Mat element(15, 15, CV_8U, Scalar(1));
	element = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(m_dstMat, m_dstMat, element);
	dilate(m_dstMat, m_dstMat, element);
	//setMat(m_dstMat);
	//HoughCircles(m_dstMat, circles, CV_HOUGH_GRADIENT, 1,10, 100, 100, 0, 0);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(m_dstMat, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	m_dumpMat = Mat::zeros(m_dstMat.size(), CV_8UC3);

	vector<Point2f> centerPoints;
	for (int i=0;i<contours.size();i++)
	{
		Point2f center;
		float radius;
		double area=contourArea(contours[i]);
		if(area>15000&& area<30000){
			minEnclosingCircle(contours[i], center, radius);
			drawContours(m_dumpMat, contours, i, Scalar(255, 255, 255), 1, 8, hierarchy);
			circle(m_dumpMat, Point(center.x, center.y), radius, Scalar(0, 0, 255));
			centerPoints.push_back(center);
		}
	}
	Point pos1(centerPoints.at(0).x + 0.5, centerPoints.at(0).y + 0.5);
	Point pos2(centerPoints.at(1).x + 0.5, centerPoints.at(1).y + 0.5);
	double flDistance = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
	line(m_dumpMat, pos1,pos2, Scalar(0, 0, 255),5);
	setMat(m_dumpMat);
	QMessageBox::warning(this, "Distance", QString("Distance:%1").arg(QString::number(flDistance)));
	*/
}

void fqqImagePro::slotMenu_ShadingCorrection(bool bstate) {
	CHECK_OPENIMGAGE
	int height = m_srcMat.rows;
	int width = m_srcMat.cols;
	Point centerPoint;
	centerPoint.x = width / 2;
	centerPoint.y = height / 2;
	

	m_ShadingMat = m_dstMat.clone();
	double fDist = 0;
	double fTotalDist = sqrt(pow(centerPoint.x, 2) + pow(centerPoint.y, 2));
	uchar cen = m_ShadingMat.at<uchar>(centerPoint);
	uchar cor = m_ShadingMat.at<uchar>(0, 0);
	double radio = (double)cen*0.6f - cor;
	for (int r=0;r<height;r++)
	{
		for (int c=0;c<width;c++)
		{
			fDist = sqrt(pow(c - centerPoint.x, 2) + pow(r - centerPoint.y, 2));
			m_ShadingMat.at<uchar>(r, c) = (uchar)(m_ShadingMat.at<uchar>(r, c)+(fDist/fTotalDist)*radio);
		}
	}

	//add(m_ShadingMat, m_dstMat, m_dstMat);
	setMat(m_ShadingMat);
}
void fqqImagePro::slotMenu_SelectArea(bool bstate) {
	CHECK_OPENIMGAGE
	m_pdockView1->setCursor(Qt::CrossCursor);
}

int graythresh(Mat &mat) {
	int threshold = 0;
	const int GrayScale = 256;
	int rows = mat.rows;
	int cols = mat.cols;
	long pixelSum = rows*cols;
	long pixelCount[GrayScale] = { 0 };
	double pixelPro[GrayScale] = { 0 };

	for (int r = 0; r < rows; r++)// Count. Gray Level
	{
		for (int c = 0; c < cols; c++)
		{
			pixelCount[mat.at<uchar>(r, c)] += 1;
		}
	}

	for (int i = 0; i < sizeof(pixelCount) / sizeof(pixelCount[0]); i++)
	{
		pixelPro[i] = (double)pixelCount[i] / pixelSum;
	}

	double w0 = 0, w1 = 0, u0tmp = 0, u1tmp = 0, u0 = 0, u1 = 0, u = 0, deltaTmp = 0, deltaMax = 0;
	for (int i = 0; i < GrayScale; i++)
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (int j = 0; j < GrayScale; j++)
		{
			if (j <= i)   //背景部分  
			{
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else   //前景部分  
			{
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;
		u1 = u1tmp / w1;
		u = u0tmp + u1tmp;
		deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	return threshold;
}
//************************************
// Description: 两点距离
// Method:    GetDistance
// FullName:  GetDistance
// Access:    public 
// Parameter: Point2f p1
// Parameter: Point2f p2
// Returns:   float
// Author:    小白
// Date:      2017/09/27
// History:
//************************************
float GetDistance(Point2f p1, Point2f p2)
{
	float dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	return dis;
}

//************************************
// Description: 根据轮廓点和圆心计算方差
// Method:    ComputeVariance
// FullName:  ComputeVariance
// Access:    public 
// Parameter: std::vector<cv::Point> theContour 某个轮廓点向量
// Parameter: Point2f theCenter 最小外接圆圆心
// Returns:   float
// Author:    小白
// Date:      2017/09/27
// History:
//************************************
float ComputeVariance(std::vector<cv::Point> theContour, Point2f theCenter)
{
	int n = theContour.size();
	vector<int> a(n);

	float aver, s;
	float sum = 0, e = 0;

	for (int i = 0; i < n; i++)
	{
		a[i] = GetDistance(theContour[i], theCenter);
		sum += a[i];
	}
	aver = sum / n;
	for (int i = 0; i < n; i++)
		e += (a[i] - aver) * (a[i] - aver);
	e /= n - 1;
	s = sqrt(e);
	return e;
}

//************************************
// Description: 判断某个轮廓是否为圆
// Method:    FindCircles
// FullName:  FindCircles
// Access:    public 
// Parameter: Mat img 二值化图（不是边缘检测结果）
// Parameter: int minPoints 轮廓最小点数（过滤噪点）
// Parameter: int maxOffset 圆检测最大偏差
// Parameter: int minr 最小半径
// Parameter: int maxr 最大半径
// Returns:   vector<Point3f>
// Author:    小白
// Date:      2017/09/27
// History:
//************************************
std::vector<Point3f> FindCircles(Mat img, int minPoints, int maxOffset, int minr, int maxr)
{
	vector<Point3f> result;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	findContours(img.clone(), contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		Point2f center; float radius;
		if (contours.at(i).size() > minPoints)
		{
			minEnclosingCircle(contours[i], center, radius);//得到最小外接圆圆心和半径  
			int offset = ComputeVariance(contours[i], center);
			if (offset < maxOffset && radius > minr && radius <= maxr)
			{
				Point3f p(center.x, center.y, radius);
				result.push_back(p);
			}
		}
	}

	return result;
}