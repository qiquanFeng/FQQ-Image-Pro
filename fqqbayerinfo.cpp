#include "fqqbayerinfo.h"

fqqBayerInfo::fqqBayerInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_Submit, SIGNAL(clicked()), this, SLOT(slot_Submit()));
}

fqqBayerInfo::~fqqBayerInfo()
{

}

void fqqBayerInfo::slot_Submit() {
	close();
}