#ifndef FQQPARTICLEWIDGET_H
#define FQQPARTICLEWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "ui_fqqparticlewidget.h"

class fqqImagePro;

class fqqParticleWidget : public QWidget
{
	Q_OBJECT

public:
	fqqParticleWidget(QWidget *parent);
	~fqqParticleWidget();

private:
	Ui::fqqParticleWidget ui;
	fqqImagePro *m_pParent;

public slots:
	_inline void slot_Save() {
		close();
	}
	void slot_Test();
};

#endif // FQQPARTICLEWIDGET_H
