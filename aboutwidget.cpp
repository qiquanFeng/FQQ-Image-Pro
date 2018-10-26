#include "aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("About");
	setWindowIcon(QIcon(":/fqqImagePro/Resources/Login.ico"));
}

AboutWidget::~AboutWidget()
{
	
}

void AboutWidget::closeEvent(QCloseEvent *event) {
	delete this;
}
