/********************************************************************************
** Form generated from reading UI file 'fqqbayerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FQQBAYERINFO_H
#define UI_FQQBAYERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fqqBayerInfo
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_Type;
    QLabel *label;
    QSpinBox *spinBox_Width;
    QLabel *label_4;
    QSpinBox *spinBox_Height;
    QComboBox *comboBox_BayerOrder;
    QLabel *label_5;
    QSpinBox *spinBox_BlackLevel;
    QPushButton *pushButton_Submit;

    void setupUi(QWidget *fqqBayerInfo)
    {
        if (fqqBayerInfo->objectName().isEmpty())
            fqqBayerInfo->setObjectName(QStringLiteral("fqqBayerInfo"));
        fqqBayerInfo->resize(491, 102);
        gridLayoutWidget = new QWidget(fqqBayerInfo);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 491, 97));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        comboBox_Type = new QComboBox(gridLayoutWidget);
        comboBox_Type->setObjectName(QStringLiteral("comboBox_Type"));

        gridLayout->addWidget(comboBox_Type, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox_Width = new QSpinBox(gridLayoutWidget);
        spinBox_Width->setObjectName(QStringLiteral("spinBox_Width"));
        spinBox_Width->setMaximum(10000);

        gridLayout->addWidget(spinBox_Width, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        spinBox_Height = new QSpinBox(gridLayoutWidget);
        spinBox_Height->setObjectName(QStringLiteral("spinBox_Height"));
        spinBox_Height->setMaximum(10000);

        gridLayout->addWidget(spinBox_Height, 1, 1, 1, 1);

        comboBox_BayerOrder = new QComboBox(gridLayoutWidget);
        comboBox_BayerOrder->setObjectName(QStringLiteral("comboBox_BayerOrder"));
        comboBox_BayerOrder->setEditable(false);
        comboBox_BayerOrder->setMaxVisibleItems(4);

        gridLayout->addWidget(comboBox_BayerOrder, 1, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        spinBox_BlackLevel = new QSpinBox(gridLayoutWidget);
        spinBox_BlackLevel->setObjectName(QStringLiteral("spinBox_BlackLevel"));

        gridLayout->addWidget(spinBox_BlackLevel, 1, 4, 1, 1);

        pushButton_Submit = new QPushButton(gridLayoutWidget);
        pushButton_Submit->setObjectName(QStringLiteral("pushButton_Submit"));

        gridLayout->addWidget(pushButton_Submit, 2, 4, 1, 1);


        retranslateUi(fqqBayerInfo);

        QMetaObject::connectSlotsByName(fqqBayerInfo);
    } // setupUi

    void retranslateUi(QWidget *fqqBayerInfo)
    {
        fqqBayerInfo->setWindowTitle(QApplication::translate("fqqBayerInfo", "BayerInfo input", Q_NULLPTR));
        label_2->setText(QApplication::translate("fqqBayerInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Height:</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("fqqBayerInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Type:</span></p></body></html>", Q_NULLPTR));
        comboBox_Type->clear();
        comboBox_Type->insertItems(0, QStringList()
         << QApplication::translate("fqqBayerInfo", "Raw8", Q_NULLPTR)
         << QApplication::translate("fqqBayerInfo", "Raw10", Q_NULLPTR)
        );
        label->setText(QApplication::translate("fqqBayerInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Width:</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("fqqBayerInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Bayer Order:</span></p></body></html>", Q_NULLPTR));
        comboBox_BayerOrder->clear();
        comboBox_BayerOrder->insertItems(0, QStringList()
         << QApplication::translate("fqqBayerInfo", "RGGB", Q_NULLPTR)
         << QApplication::translate("fqqBayerInfo", "GRBG", Q_NULLPTR)
         << QApplication::translate("fqqBayerInfo", "GBRG", Q_NULLPTR)
         << QApplication::translate("fqqBayerInfo", "BGGR", Q_NULLPTR)
        );
        comboBox_BayerOrder->setCurrentText(QApplication::translate("fqqBayerInfo", "RGGB", Q_NULLPTR));
        label_5->setText(QApplication::translate("fqqBayerInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Black Level(OB):</span></p></body></html>", Q_NULLPTR));
        pushButton_Submit->setText(QApplication::translate("fqqBayerInfo", "Submit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fqqBayerInfo: public Ui_fqqBayerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FQQBAYERINFO_H
