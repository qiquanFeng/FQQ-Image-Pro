/********************************************************************************
** Form generated from reading UI file 'fqqparticlewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FQQPARTICLEWIDGET_H
#define UI_FQQPARTICLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fqqParticleWidget
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Test;
    QFrame *frame;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_18;
    QDoubleSpinBox *doubleSpinBox_19;
    QDoubleSpinBox *doubleSpinBox_20;
    QDoubleSpinBox *doubleSpinBox_21;
    QDoubleSpinBox *doubleSpinBox_22;
    QDoubleSpinBox *doubleSpinBox_23;
    QDoubleSpinBox *doubleSpinBox_24;
    QFrame *frame_1;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_1;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_1_LT;
    QDoubleSpinBox *doubleSpinBox_1_R;
    QDoubleSpinBox *doubleSpinBox_1_L;
    QDoubleSpinBox *doubleSpinBox_1_RT;
    QDoubleSpinBox *doubleSpinBox_1_T;
    QDoubleSpinBox *doubleSpinBox_1_RB;
    QDoubleSpinBox *doubleSpinBox_1_LB;
    QDoubleSpinBox *doubleSpinBox_1_B;
    QFrame *frame_3;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_8;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_49;
    QDoubleSpinBox *doubleSpinBox_50;
    QDoubleSpinBox *doubleSpinBox_51;
    QDoubleSpinBox *doubleSpinBox_52;
    QDoubleSpinBox *doubleSpinBox_53;
    QDoubleSpinBox *doubleSpinBox_54;
    QDoubleSpinBox *doubleSpinBox_55;
    QDoubleSpinBox *doubleSpinBox_56;
    QFrame *frame_4;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_57;
    QDoubleSpinBox *doubleSpinBox_58;
    QDoubleSpinBox *doubleSpinBox_59;
    QDoubleSpinBox *doubleSpinBox_60;
    QDoubleSpinBox *doubleSpinBox_61;
    QDoubleSpinBox *doubleSpinBox_62;
    QDoubleSpinBox *doubleSpinBox_63;
    QDoubleSpinBox *doubleSpinBox_64;

    void setupUi(QWidget *fqqParticleWidget)
    {
        if (fqqParticleWidget->objectName().isEmpty())
            fqqParticleWidget->setObjectName(QStringLiteral("fqqParticleWidget"));
        fqqParticleWidget->resize(505, 359);
        fqqParticleWidget->setStyleSheet(QStringLiteral(""));
        gridLayoutWidget_2 = new QWidget(fqqParticleWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 50, 451, 251));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Save = new QPushButton(gridLayoutWidget_2);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        gridLayout_2->addWidget(pushButton_Save, 2, 1, 1, 1);

        pushButton_Test = new QPushButton(gridLayoutWidget_2);
        pushButton_Test->setObjectName(QStringLiteral("pushButton_Test"));

        gridLayout_2->addWidget(pushButton_Test, 2, 0, 1, 1);

        frame = new QFrame(gridLayoutWidget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame{border:1px solid black}\n"
"QWidget{margin:3px;}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 201, 88));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 1, 1, 1);

        doubleSpinBox_17 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_17->setObjectName(QStringLiteral("doubleSpinBox_17"));

        gridLayout_4->addWidget(doubleSpinBox_17, 0, 0, 1, 1);

        doubleSpinBox_18 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_18->setObjectName(QStringLiteral("doubleSpinBox_18"));

        gridLayout_4->addWidget(doubleSpinBox_18, 1, 2, 1, 1);

        doubleSpinBox_19 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_19->setObjectName(QStringLiteral("doubleSpinBox_19"));

        gridLayout_4->addWidget(doubleSpinBox_19, 1, 0, 1, 1);

        doubleSpinBox_20 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_20->setObjectName(QStringLiteral("doubleSpinBox_20"));

        gridLayout_4->addWidget(doubleSpinBox_20, 0, 2, 1, 1);

        doubleSpinBox_21 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_21->setObjectName(QStringLiteral("doubleSpinBox_21"));

        gridLayout_4->addWidget(doubleSpinBox_21, 0, 1, 1, 1);

        doubleSpinBox_22 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_22->setObjectName(QStringLiteral("doubleSpinBox_22"));

        gridLayout_4->addWidget(doubleSpinBox_22, 2, 2, 1, 1);

        doubleSpinBox_23 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_23->setObjectName(QStringLiteral("doubleSpinBox_23"));

        gridLayout_4->addWidget(doubleSpinBox_23, 2, 0, 1, 1);

        doubleSpinBox_24 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_24->setObjectName(QStringLiteral("doubleSpinBox_24"));

        gridLayout_4->addWidget(doubleSpinBox_24, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame, 0, 1, 1, 1);

        frame_1 = new QFrame(gridLayoutWidget_2);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setStyleSheet(QLatin1String("QFrame{border:1px solid black}\n"
"QWidget{margin:3px;}"));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        frame_1->setLineWidth(2);
        layoutWidget_2 = new QWidget(frame_1);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 201, 88));
        gridLayout_1 = new QGridLayout(layoutWidget_2);
        gridLayout_1->setSpacing(6);
        gridLayout_1->setContentsMargins(11, 11, 11, 11);
        gridLayout_1->setObjectName(QStringLiteral("gridLayout_1"));
        gridLayout_1->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_1->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_1->addWidget(label_5, 1, 1, 1, 1);

        doubleSpinBox_1_LT = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_LT->setObjectName(QStringLiteral("doubleSpinBox_1_LT"));

        gridLayout_1->addWidget(doubleSpinBox_1_LT, 0, 0, 1, 1);

        doubleSpinBox_1_R = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_R->setObjectName(QStringLiteral("doubleSpinBox_1_R"));

        gridLayout_1->addWidget(doubleSpinBox_1_R, 1, 2, 1, 1);

        doubleSpinBox_1_L = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_L->setObjectName(QStringLiteral("doubleSpinBox_1_L"));

        gridLayout_1->addWidget(doubleSpinBox_1_L, 1, 0, 1, 1);

        doubleSpinBox_1_RT = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_RT->setObjectName(QStringLiteral("doubleSpinBox_1_RT"));

        gridLayout_1->addWidget(doubleSpinBox_1_RT, 0, 2, 1, 1);

        doubleSpinBox_1_T = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_T->setObjectName(QStringLiteral("doubleSpinBox_1_T"));

        gridLayout_1->addWidget(doubleSpinBox_1_T, 0, 1, 1, 1);

        doubleSpinBox_1_RB = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_RB->setObjectName(QStringLiteral("doubleSpinBox_1_RB"));

        gridLayout_1->addWidget(doubleSpinBox_1_RB, 2, 2, 1, 1);

        doubleSpinBox_1_LB = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_LB->setObjectName(QStringLiteral("doubleSpinBox_1_LB"));

        gridLayout_1->addWidget(doubleSpinBox_1_LB, 2, 0, 1, 1);

        doubleSpinBox_1_B = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_1_B->setObjectName(QStringLiteral("doubleSpinBox_1_B"));

        gridLayout_1->addWidget(doubleSpinBox_1_B, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_1, 0, 0, 1, 1);

        frame_3 = new QFrame(gridLayoutWidget_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setStyleSheet(QLatin1String("QFrame{border:1px solid black}\n"
"QWidget{margin:3px;}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        layoutWidget_4 = new QWidget(frame_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 10, 201, 88));
        gridLayout_8 = new QGridLayout(layoutWidget_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_8->addWidget(label_7, 1, 1, 1, 1);

        doubleSpinBox_49 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_49->setObjectName(QStringLiteral("doubleSpinBox_49"));

        gridLayout_8->addWidget(doubleSpinBox_49, 0, 0, 1, 1);

        doubleSpinBox_50 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_50->setObjectName(QStringLiteral("doubleSpinBox_50"));

        gridLayout_8->addWidget(doubleSpinBox_50, 1, 2, 1, 1);

        doubleSpinBox_51 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_51->setObjectName(QStringLiteral("doubleSpinBox_51"));

        gridLayout_8->addWidget(doubleSpinBox_51, 1, 0, 1, 1);

        doubleSpinBox_52 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_52->setObjectName(QStringLiteral("doubleSpinBox_52"));

        gridLayout_8->addWidget(doubleSpinBox_52, 0, 2, 1, 1);

        doubleSpinBox_53 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_53->setObjectName(QStringLiteral("doubleSpinBox_53"));

        gridLayout_8->addWidget(doubleSpinBox_53, 0, 1, 1, 1);

        doubleSpinBox_54 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_54->setObjectName(QStringLiteral("doubleSpinBox_54"));

        gridLayout_8->addWidget(doubleSpinBox_54, 2, 2, 1, 1);

        doubleSpinBox_55 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_55->setObjectName(QStringLiteral("doubleSpinBox_55"));

        gridLayout_8->addWidget(doubleSpinBox_55, 2, 0, 1, 1);

        doubleSpinBox_56 = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_56->setObjectName(QStringLiteral("doubleSpinBox_56"));

        gridLayout_8->addWidget(doubleSpinBox_56, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_3, 1, 0, 1, 1);

        frame_4 = new QFrame(gridLayoutWidget_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setStyleSheet(QLatin1String("QFrame{border:1px solid black}\n"
"QWidget{margin:3px;}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        layoutWidget_5 = new QWidget(frame_4);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 10, 201, 88));
        gridLayout_9 = new QGridLayout(layoutWidget_5);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_9->addWidget(label_8, 1, 1, 1, 1);

        doubleSpinBox_57 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_57->setObjectName(QStringLiteral("doubleSpinBox_57"));

        gridLayout_9->addWidget(doubleSpinBox_57, 0, 0, 1, 1);

        doubleSpinBox_58 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_58->setObjectName(QStringLiteral("doubleSpinBox_58"));

        gridLayout_9->addWidget(doubleSpinBox_58, 1, 2, 1, 1);

        doubleSpinBox_59 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_59->setObjectName(QStringLiteral("doubleSpinBox_59"));

        gridLayout_9->addWidget(doubleSpinBox_59, 1, 0, 1, 1);

        doubleSpinBox_60 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_60->setObjectName(QStringLiteral("doubleSpinBox_60"));

        gridLayout_9->addWidget(doubleSpinBox_60, 0, 2, 1, 1);

        doubleSpinBox_61 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_61->setObjectName(QStringLiteral("doubleSpinBox_61"));

        gridLayout_9->addWidget(doubleSpinBox_61, 0, 1, 1, 1);

        doubleSpinBox_62 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_62->setObjectName(QStringLiteral("doubleSpinBox_62"));

        gridLayout_9->addWidget(doubleSpinBox_62, 2, 2, 1, 1);

        doubleSpinBox_63 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_63->setObjectName(QStringLiteral("doubleSpinBox_63"));

        gridLayout_9->addWidget(doubleSpinBox_63, 2, 0, 1, 1);

        doubleSpinBox_64 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_64->setObjectName(QStringLiteral("doubleSpinBox_64"));

        gridLayout_9->addWidget(doubleSpinBox_64, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_4, 1, 1, 1, 1);

        QWidget::setTabOrder(doubleSpinBox_1_LT, doubleSpinBox_1_T);
        QWidget::setTabOrder(doubleSpinBox_1_T, doubleSpinBox_1_RT);
        QWidget::setTabOrder(doubleSpinBox_1_RT, doubleSpinBox_1_L);
        QWidget::setTabOrder(doubleSpinBox_1_L, doubleSpinBox_1_R);
        QWidget::setTabOrder(doubleSpinBox_1_R, doubleSpinBox_1_LB);
        QWidget::setTabOrder(doubleSpinBox_1_LB, doubleSpinBox_1_B);
        QWidget::setTabOrder(doubleSpinBox_1_B, doubleSpinBox_1_RB);
        QWidget::setTabOrder(doubleSpinBox_1_RB, doubleSpinBox_17);
        QWidget::setTabOrder(doubleSpinBox_17, doubleSpinBox_21);
        QWidget::setTabOrder(doubleSpinBox_21, doubleSpinBox_20);
        QWidget::setTabOrder(doubleSpinBox_20, doubleSpinBox_19);
        QWidget::setTabOrder(doubleSpinBox_19, doubleSpinBox_18);
        QWidget::setTabOrder(doubleSpinBox_18, doubleSpinBox_23);
        QWidget::setTabOrder(doubleSpinBox_23, doubleSpinBox_24);
        QWidget::setTabOrder(doubleSpinBox_24, doubleSpinBox_22);
        QWidget::setTabOrder(doubleSpinBox_22, doubleSpinBox_49);
        QWidget::setTabOrder(doubleSpinBox_49, doubleSpinBox_53);
        QWidget::setTabOrder(doubleSpinBox_53, doubleSpinBox_52);
        QWidget::setTabOrder(doubleSpinBox_52, doubleSpinBox_51);
        QWidget::setTabOrder(doubleSpinBox_51, doubleSpinBox_50);
        QWidget::setTabOrder(doubleSpinBox_50, doubleSpinBox_55);
        QWidget::setTabOrder(doubleSpinBox_55, doubleSpinBox_56);
        QWidget::setTabOrder(doubleSpinBox_56, doubleSpinBox_54);
        QWidget::setTabOrder(doubleSpinBox_54, doubleSpinBox_57);
        QWidget::setTabOrder(doubleSpinBox_57, doubleSpinBox_61);
        QWidget::setTabOrder(doubleSpinBox_61, doubleSpinBox_60);
        QWidget::setTabOrder(doubleSpinBox_60, doubleSpinBox_59);
        QWidget::setTabOrder(doubleSpinBox_59, doubleSpinBox_58);
        QWidget::setTabOrder(doubleSpinBox_58, doubleSpinBox_63);
        QWidget::setTabOrder(doubleSpinBox_63, doubleSpinBox_64);
        QWidget::setTabOrder(doubleSpinBox_64, doubleSpinBox_62);
        QWidget::setTabOrder(doubleSpinBox_62, pushButton_Test);
        QWidget::setTabOrder(pushButton_Test, pushButton_Save);

        retranslateUi(fqqParticleWidget);

        QMetaObject::connectSlotsByName(fqqParticleWidget);
    } // setupUi

    void retranslateUi(QWidget *fqqParticleWidget)
    {
        fqqParticleWidget->setWindowTitle(QApplication::translate("fqqParticleWidget", "fqqParticleWidget", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("fqqParticleWidget", "Save", Q_NULLPTR));
        pushButton_Test->setText(QApplication::translate("fqqParticleWidget", "Test", Q_NULLPTR));
        label_3->setText(QApplication::translate("fqqParticleWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">2</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("fqqParticleWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">1</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("fqqParticleWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">3</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("fqqParticleWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">4</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fqqParticleWidget: public Ui_fqqParticleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FQQPARTICLEWIDGET_H
