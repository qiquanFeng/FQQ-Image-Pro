/********************************************************************************
** Form generated from reading UI file 'fqqimageview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FQQIMAGEVIEW_H
#define UI_FQQIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fqqImageView
{
public:
    QWidget *widget;

    void setupUi(QDockWidget *fqqImageView)
    {
        if (fqqImageView->objectName().isEmpty())
            fqqImageView->setObjectName(QStringLiteral("fqqImageView"));
        fqqImageView->resize(400, 300);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        fqqImageView->setWidget(widget);

        retranslateUi(fqqImageView);

        QMetaObject::connectSlotsByName(fqqImageView);
    } // setupUi

    void retranslateUi(QDockWidget *fqqImageView)
    {
        fqqImageView->setWindowTitle(QApplication::translate("fqqImageView", "fqqImageView", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fqqImageView: public Ui_fqqImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FQQIMAGEVIEW_H
