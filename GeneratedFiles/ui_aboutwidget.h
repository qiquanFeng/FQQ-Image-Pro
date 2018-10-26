/********************************************************************************
** Form generated from reading UI file 'aboutwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *AboutWidget)
    {
        if (AboutWidget->objectName().isEmpty())
            AboutWidget->setObjectName(QStringLiteral("AboutWidget"));
        AboutWidget->resize(396, 155);
        label = new QLabel(AboutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 391, 151));

        retranslateUi(AboutWidget);

        QMetaObject::connectSlotsByName(AboutWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutWidget)
    {
        AboutWidget->setWindowTitle(QApplication::translate("AboutWidget", "AboutWidget", Q_NULLPTR));
        label->setText(QApplication::translate("AboutWidget", "<html><head/><body><p><span style=\" font-family:'Helvetica'; font-size:14pt; font-weight:600; color:#000000; background-color:#ffffff;\">Copyright \302\251\302\2402017 FQQ</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutWidget: public Ui_AboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
