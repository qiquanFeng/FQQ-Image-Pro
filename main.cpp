#include "fqqimagepro.h"
#include <QtWidgets/QApplication>
#include <QTranslator>
#include <QLocale>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QLocale locale;
	QTranslator translator;
	switch (locale.language())
	{
	case QLocale::Chinese:
		translator.load(":/fqqImagePro/Resources/cn.qm");
		a.installTranslator(&translator);
		break;
	default:
		break;
	}
	

	fqqImagePro w;
	a.installEventFilter(&w);
	w.showMaximized();
	return a.exec();
}