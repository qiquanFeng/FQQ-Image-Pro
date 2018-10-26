/********************************************************************************
** Form generated from reading UI file 'fqqimagepro.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FQQIMAGEPRO_H
#define UI_FQQIMAGEPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fqqImageProClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fqqImageProClass)
    {
        if (fqqImageProClass->objectName().isEmpty())
            fqqImageProClass->setObjectName(QStringLiteral("fqqImageProClass"));
        fqqImageProClass->resize(600, 400);
        centralWidget = new QWidget(fqqImageProClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fqqImageProClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(fqqImageProClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        fqqImageProClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(fqqImageProClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        fqqImageProClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(fqqImageProClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        fqqImageProClass->setStatusBar(statusBar);

        retranslateUi(fqqImageProClass);

        QMetaObject::connectSlotsByName(fqqImageProClass);
    } // setupUi

    void retranslateUi(QMainWindow *fqqImageProClass)
    {
        fqqImageProClass->setWindowTitle(QApplication::translate("fqqImageProClass", "fqqImagePro", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fqqImageProClass: public Ui_fqqImageProClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FQQIMAGEPRO_H
