/********************************************************************************
** Form generated from reading ui file 'properties.ui'
**
** Created: Tue 5. Feb 15:12:05 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROPERTIES_H
#define UI_PROPERTIES_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDialog>
#include <QFrame>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QTextBrowser>
#include <QWidget>
#include "qmeter.h"

class Ui_propertiesDialog
{
public:
    QGroupBox *groupBox;
    QMeter *qMeter;
    QPushButton *exit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_4;
    QLabel *label_13;
    QWidget *tab_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_24;
    QLabel *label_25;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget;
    QGridLayout *gridLayout2;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_4;
    QGroupBox *groupBox_6;
    QLabel *label_19;
    QLabel *label_20;
    QGroupBox *groupBox_8;
    QLabel *label_23;
    QWidget *tab_5;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout3;
    QLabel *label_26;
    QLabel *label_27;
    QTextBrowser *textBrowser;
    QWidget *tab_6;
    QLabel *label_28;
    QLabel *label_29;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *urlLabel;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *propertiesDialog)
    {
    if (propertiesDialog->objectName().isEmpty())
        propertiesDialog->setObjectName(QString::fromUtf8("propertiesDialog"));
    propertiesDialog->resize(677, 454);
    groupBox = new QGroupBox(propertiesDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 211, 361));
    qMeter = new QMeter(groupBox);
    qMeter->setObjectName(QString::fromUtf8("qMeter"));
    qMeter->setGeometry(QRect(20, 20, 161, 181));
    qMeter->setValue(0);
    qMeter->setMinValue(0);
    qMeter->setMaxValue(100);
    qMeter->setStartAngle(210);
    qMeter->setEndAngle(-30);
    exit = new QPushButton(propertiesDialog);
    exit->setObjectName(QString::fromUtf8("exit"));
    exit->setGeometry(QRect(290, 400, 75, 23));
    tabWidget = new QTabWidget(propertiesDialog);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(230, 20, 421, 351));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    groupBox_2 = new QGroupBox(tab);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 10, 381, 81));
    label_7 = new QLabel(groupBox_2);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(20, 20, 321, 16));
    label_8 = new QLabel(groupBox_2);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(20, 40, 321, 16));
    groupBox_3 = new QGroupBox(tab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 90, 381, 131));
    frame = new QFrame(groupBox_3);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(119, 20, 111, 80));
    frame->setFrameShape(QFrame::HLine);
    frame->setFrameShadow(QFrame::Raised);
    frame->setLineWidth(2);
    frame_2 = new QFrame(frame);
    frame_2->setObjectName(QString::fromUtf8("frame_2"));
    frame_2->setGeometry(QRect(-10, 10, 131, 61));
    frame_2->setFrameShape(QFrame::VLine);
    frame_2->setFrameShadow(QFrame::Raised);
    frame_2->setLineWidth(2);
    label_9 = new QLabel(groupBox_3);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(240, 50, 21, 21));
    label_10 = new QLabel(groupBox_3);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(170, 10, 21, 20));
    label_11 = new QLabel(groupBox_3);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(55, 50, 54, 21));
    label_12 = new QLabel(groupBox_3);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(170, 110, 21, 16));
    groupBox_4 = new QGroupBox(tab);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 230, 381, 81));
    label_13 = new QLabel(groupBox_4);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(20, 40, 351, 16));
    tabWidget->addTab(tab, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    groupBox_5 = new QGroupBox(tab_3);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(10, 10, 381, 151));
    gridLayout = new QGridLayout(groupBox_5);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout1 = new QGridLayout();
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label_14 = new QLabel(groupBox_5);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    gridLayout1->addWidget(label_14, 1, 0, 1, 1);

    label_15 = new QLabel(groupBox_5);
    label_15->setObjectName(QString::fromUtf8("label_15"));

    gridLayout1->addWidget(label_15, 2, 0, 1, 1);

    label_16 = new QLabel(groupBox_5);
    label_16->setObjectName(QString::fromUtf8("label_16"));

    gridLayout1->addWidget(label_16, 4, 0, 1, 1);

    label_17 = new QLabel(groupBox_5);
    label_17->setObjectName(QString::fromUtf8("label_17"));

    gridLayout1->addWidget(label_17, 5, 0, 1, 1);

    label_18 = new QLabel(groupBox_5);
    label_18->setObjectName(QString::fromUtf8("label_18"));

    gridLayout1->addWidget(label_18, 6, 0, 1, 1);

    label_24 = new QLabel(groupBox_5);
    label_24->setObjectName(QString::fromUtf8("label_24"));

    gridLayout1->addWidget(label_24, 3, 0, 1, 1);

    label_25 = new QLabel(groupBox_5);
    label_25->setObjectName(QString::fromUtf8("label_25"));

    gridLayout1->addWidget(label_25, 0, 0, 1, 1);


    gridLayout->addLayout(gridLayout1, 0, 0, 1, 1);

    groupBox_7 = new QGroupBox(tab_3);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    groupBox_7->setGeometry(QRect(10, 170, 381, 91));
    layoutWidget = new QWidget(groupBox_7);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 30, 320, 36));
    gridLayout2 = new QGridLayout(layoutWidget);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    gridLayout2->setContentsMargins(0, 0, 0, 0);
    label_21 = new QLabel(layoutWidget);
    label_21->setObjectName(QString::fromUtf8("label_21"));

    gridLayout2->addWidget(label_21, 0, 0, 1, 1);

    label_22 = new QLabel(layoutWidget);
    label_22->setObjectName(QString::fromUtf8("label_22"));

    gridLayout2->addWidget(label_22, 1, 0, 1, 1);

    tabWidget->addTab(tab_3, QString());
    tab_4 = new QWidget();
    tab_4->setObjectName(QString::fromUtf8("tab_4"));
    groupBox_6 = new QGroupBox(tab_4);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(20, 20, 381, 81));
    label_19 = new QLabel(groupBox_6);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(20, 20, 272, 16));
    label_20 = new QLabel(groupBox_6);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setGeometry(QRect(20, 40, 268, 16));
    groupBox_8 = new QGroupBox(tab_4);
    groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
    groupBox_8->setGeometry(QRect(20, 110, 381, 81));
    label_23 = new QLabel(groupBox_8);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setGeometry(QRect(20, 40, 351, 16));
    tabWidget->addTab(tab_4, QString());
    tab_5 = new QWidget();
    tab_5->setObjectName(QString::fromUtf8("tab_5"));
    layoutWidget1 = new QWidget(tab_5);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    layoutWidget1->setGeometry(QRect(10, 30, 397, 234));
    gridLayout3 = new QGridLayout(layoutWidget1);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    gridLayout3->setContentsMargins(0, 0, 0, 0);
    label_26 = new QLabel(layoutWidget1);
    label_26->setObjectName(QString::fromUtf8("label_26"));

    gridLayout3->addWidget(label_26, 0, 0, 1, 1);

    label_27 = new QLabel(layoutWidget1);
    label_27->setObjectName(QString::fromUtf8("label_27"));

    gridLayout3->addWidget(label_27, 1, 0, 1, 1);

    textBrowser = new QTextBrowser(layoutWidget1);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

    gridLayout3->addWidget(textBrowser, 2, 0, 1, 1);

    tabWidget->addTab(tab_5, QString());
    tab_6 = new QWidget();
    tab_6->setObjectName(QString::fromUtf8("tab_6"));
    label_28 = new QLabel(tab_6);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setGeometry(QRect(20, 20, 371, 16));
    label_29 = new QLabel(tab_6);
    label_29->setObjectName(QString::fromUtf8("label_29"));
    label_29->setGeometry(QRect(20, 50, 318, 16));
    checkBox = new QCheckBox(tab_6);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    checkBox->setGeometry(QRect(50, 110, 151, 18));
    checkBox->setChecked(true);
    checkBox_2 = new QCheckBox(tab_6);
    checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
    checkBox_2->setGeometry(QRect(50, 140, 151, 18));
    checkBox_2->setChecked(true);
    tabWidget->addTab(tab_6, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    layoutWidget2 = new QWidget(tab_2);
    layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
    layoutWidget2->setGeometry(QRect(10, 10, 397, 148));
    gridLayout4 = new QGridLayout(layoutWidget2);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    gridLayout4->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(layoutWidget2);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);

    gridLayout4->addWidget(label, 0, 0, 1, 1);

    label_2 = new QLabel(layoutWidget2);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout4->addWidget(label_2, 1, 0, 1, 1);

    label_3 = new QLabel(layoutWidget2);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout4->addWidget(label_3, 2, 0, 1, 1);

    label_4 = new QLabel(layoutWidget2);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout4->addWidget(label_4, 3, 0, 1, 1);

    urlLabel = new QLabel(layoutWidget2);
    urlLabel->setObjectName(QString::fromUtf8("urlLabel"));

    gridLayout4->addWidget(urlLabel, 6, 0, 1, 1);

    label_5 = new QLabel(layoutWidget2);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout4->addWidget(label_5, 4, 0, 1, 1);

    label_6 = new QLabel(layoutWidget2);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout4->addWidget(label_6, 5, 0, 1, 1);

    tabWidget->addTab(tab_2, QString());

    retranslateUi(propertiesDialog);
    QObject::connect(exit, SIGNAL(released()), propertiesDialog, SLOT(accept()));
    QObject::connect(checkBox, SIGNAL(toggled(bool)), qMeter, SLOT(setThresholdEnabled(bool)));
    QObject::connect(checkBox_2, SIGNAL(toggled(bool)), qMeter, SLOT(setNumericIndicatorEnabled(bool)));

    tabWidget->setCurrentIndex(5);


    QMetaObject::connectSlotsByName(propertiesDialog);
    } // setupUi

    void retranslateUi(QDialog *propertiesDialog)
    {
    propertiesDialog->setWindowTitle(QApplication::translate("propertiesDialog", "QMeter property dialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("propertiesDialog", "Preview", 0, QApplication::UnicodeUTF8));
    qMeter->setToolTip(QApplication::translate("propertiesDialog", "Meter", 0, QApplication::UnicodeUTF8));
    qMeter->setWhatsThis(QApplication::translate("propertiesDialog", "Meter widget", 0, QApplication::UnicodeUTF8));
    qMeter->setUnits(QApplication::translate("propertiesDialog", "Km/h", 0, QApplication::UnicodeUTF8));
    exit->setText(QApplication::translate("propertiesDialog", "Exit", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("propertiesDialog", "Definition", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("propertiesDialog", "startAngle = The angle associated to the minimum value (double)", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("propertiesDialog", "endAngle = The angle associated to the maximum value (double)", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("propertiesDialog", "Values", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("propertiesDialog", "0", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("propertiesDialog", "90", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("propertiesDialog", "180 = -180", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("propertiesDialog", "-90", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("propertiesDialog", "Preview Example", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("propertiesDialog", "The preview example shows a startAngle = 210 and an EndAngle = -30", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("propertiesDialog", "Angle", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("propertiesDialog", "Definition", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("propertiesDialog", "minValue = The minimum Value (int or double)", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("propertiesDialog", "maxValue= The maximum value (int or double)", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("propertiesDialog", "precision = Number of deciman digits (int)", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("propertiesDialog", "steps = Number of scale ticks (int)", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("propertiesDialog", "units = The measurement unit string (QString)", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("propertiesDialog", "threshold= The threshold value (int or double)", 0, QApplication::UnicodeUTF8));
    label_25->setText(QApplication::translate("propertiesDialog", "value= Input Value (int or double)", 0, QApplication::UnicodeUTF8));
    groupBox_7->setTitle(QApplication::translate("propertiesDialog", "Preview Example", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("propertiesDialog", "The preview example shows a minValue = 0 and a maxValue = 100", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("propertiesDialog", "steps = 10 and precision = 0", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("propertiesDialog", "Value", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("propertiesDialog", "Definition", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("propertiesDialog", "foreground = Foreground Color", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("propertiesDialog", "background = BackGround Color", 0, QApplication::UnicodeUTF8));
    groupBox_8->setTitle(QApplication::translate("propertiesDialog", "Preview Example", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("propertiesDialog", "The preview example shows a black background and a green foreground", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("propertiesDialog", "Colors", 0, QApplication::UnicodeUTF8));
    label_26->setText(QApplication::translate("propertiesDialog", "errorSignal = This signal repots an enum value containing the error code", 0, QApplication::UnicodeUTF8));
    label_27->setText(QApplication::translate("propertiesDialog", "thresholdAlarm = This signal reports when the input (value) exceeds the threshold", 0, QApplication::UnicodeUTF8));
    textBrowser->setHtml(QApplication::translate("propertiesDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Q_ENUMS(errorCode) :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> MaxValueError=1,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> MinValueError,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> ThresholdError"
        ",</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> TargetError,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> PrecisionError,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> ColorError,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> UnitsEmpty,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"> OutOfRange</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">}</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px"
        "; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Note: error management is under development...</p></body></html>", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("propertiesDialog", "Signals", 0, QApplication::UnicodeUTF8));
    label_28->setText(QApplication::translate("propertiesDialog", "enableThreshold = This flag enables the threshold curve and management", 0, QApplication::UnicodeUTF8));
    label_29->setText(QApplication::translate("propertiesDialog", "enableNumericIndicator = This flag enables the numerical indicator", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("propertiesDialog", "enableThreshold", 0, QApplication::UnicodeUTF8));
    checkBox_2->setText(QApplication::translate("propertiesDialog", "enableNumericIndicator", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("propertiesDialog", "Flags", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("propertiesDialog", "QMeter v 0.5.0 beta", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("propertiesDialog", "QMeter custom widget plugin allows you to easily modify", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("propertiesDialog", "min and max values, start and end angle, number of steps", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("propertiesDialog", "background and foreground color, number of digits and units", 0, QApplication::UnicodeUTF8));
    urlLabel->setText(QApplication::translate("propertiesDialog", "Click here to visit <a href=\"http://www.sereno-online.com\">author</a> website", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("propertiesDialog", "WARNING: This widget plugin is in beta version. If you find", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("propertiesDialog", "bugs or if you want to contribute, please contact me.", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("propertiesDialog", "About", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(propertiesDialog);
    } // retranslateUi

};

namespace Ui {
    class propertiesDialog: public Ui_propertiesDialog {};
} // namespace Ui

#endif // UI_PROPERTIES_H
