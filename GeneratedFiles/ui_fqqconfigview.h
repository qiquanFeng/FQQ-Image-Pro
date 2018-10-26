/********************************************************************************
** Form generated from reading UI file 'fqqconfigview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FQQCONFIGVIEW_H
#define UI_FQQCONFIGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fqqConfigView
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *Slider1;
    QLabel *label_val1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *Slider2;
    QLabel *label_val2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *Slider3;
    QLabel *label_val3;
    QPushButton *pushButton_Save;

    void setupUi(QWidget *fqqConfigView)
    {
        if (fqqConfigView->objectName().isEmpty())
            fqqConfigView->setObjectName(QStringLiteral("fqqConfigView"));
        fqqConfigView->resize(401, 301);
        verticalLayoutWidget = new QWidget(fqqConfigView);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Slider1 = new QSlider(verticalLayoutWidget);
        Slider1->setObjectName(QStringLiteral("Slider1"));
        Slider1->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(Slider1);

        label_val1 = new QLabel(verticalLayoutWidget);
        label_val1->setObjectName(QStringLiteral("label_val1"));

        horizontalLayout->addWidget(label_val1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        Slider2 = new QSlider(verticalLayoutWidget);
        Slider2->setObjectName(QStringLiteral("Slider2"));
        Slider2->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Slider2);

        label_val2 = new QLabel(verticalLayoutWidget);
        label_val2->setObjectName(QStringLiteral("label_val2"));

        horizontalLayout_3->addWidget(label_val2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Slider3 = new QSlider(verticalLayoutWidget);
        Slider3->setObjectName(QStringLiteral("Slider3"));
        Slider3->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Slider3);

        label_val3 = new QLabel(verticalLayoutWidget);
        label_val3->setObjectName(QStringLiteral("label_val3"));

        horizontalLayout_2->addWidget(label_val3);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_Save = new QPushButton(verticalLayoutWidget);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        verticalLayout->addWidget(pushButton_Save);


        retranslateUi(fqqConfigView);

        QMetaObject::connectSlotsByName(fqqConfigView);
    } // setupUi

    void retranslateUi(QWidget *fqqConfigView)
    {
        fqqConfigView->setWindowTitle(QApplication::translate("fqqConfigView", "fqqConfigView", Q_NULLPTR));
        label->setText(QApplication::translate("fqqConfigView", "param1:", Q_NULLPTR));
        label_val1->setText(QApplication::translate("fqqConfigView", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("fqqConfigView", "param2:", Q_NULLPTR));
        label_val2->setText(QApplication::translate("fqqConfigView", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("fqqConfigView", "param3:", Q_NULLPTR));
        label_val3->setText(QApplication::translate("fqqConfigView", "TextLabel", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("fqqConfigView", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fqqConfigView: public Ui_fqqConfigView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FQQCONFIGVIEW_H
