#ifndef FQQBAYERINFO_H
#define FQQBAYERINFO_H

#include <QWidget>
#include <QDialog>
#include "ui_fqqbayerinfo.h"

class fqqBayerInfo : public QDialog
{
	Q_OBJECT

public:
	fqqBayerInfo(QWidget *parent = 0);
	~fqqBayerInfo();

public slots:
	void slot_Submit();

private:
	Ui::fqqBayerInfo ui;

public:
	_inline Ui::fqqBayerInfo GetUI() {
		return ui;
	}
};

#endif // FQQBAYERINFO_H
