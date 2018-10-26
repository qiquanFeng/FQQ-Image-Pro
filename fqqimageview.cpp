#include "fqqimageview.h"
#include <qevent.h>
#include <qmainwindow.h>


fqqImageView::fqqImageView(QString title,QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);
	QMainWindow *mainwindow = (QMainWindow*)parent;

	setWindowTitle(title);
	QWidget *widget=new QWidget();
	
	//widget->setFixedSize(mainwindow->centralWidget()->size());
	widget->setFixedSize(900, 600);
	m_plabImage = new QLabel("", widget);
	m_plabImage->setFixedSize(900, 600);
	//m_plabImage->setFixedSize(mainwindow->centralWidget()->size());
	setStyleSheet("border:1px solid black;background-color:#EEEEEE;");
	setWidget(widget);

}

fqqImageView::~fqqImageView()
{

}

void fqqImageView::mouseDoubleClickEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton){

	}
}

void fqqImageView::SetImage(QPixmap pixmap) {
	QPixmap viewPixmap=pixmap.scaled(m_plabImage->size());
	m_plabImage->setPixmap(viewPixmap);
	update();
}

void fqqImageView::SetImage(cv::Mat mat) {
	QPixmap pixmap;
	cv::Mat matDisplay=mat.clone();
	if (matDisplay.channels() == 1) {
		pixmap = QPixmap::fromImage(QImage(matDisplay.data, matDisplay.cols, matDisplay.rows, matDisplay.step, QImage::Format_Grayscale8));
	}
	else {
		cvtColor(matDisplay, matDisplay, cv::COLOR_BGR2RGB);
		pixmap = QPixmap::fromImage(QImage(matDisplay.data, matDisplay.cols, matDisplay.rows, matDisplay.step, QImage::Format_RGB888));
	}

	QImage image;

	QPixmap viewPixmap = pixmap.scaled(m_plabImage->size());
	m_plabImage->setPixmap(viewPixmap);
	update();
}

void fqqImageView::slot_reSize(QSize size) {
	//setGeometry(QRect(QPoint(0, 0), size));
	//this->m_plabImage->setGeometry(QRect(QPoint(0, 0), size));
	update();
}

void fqqImageView::slot_SelectArea() {
	
}