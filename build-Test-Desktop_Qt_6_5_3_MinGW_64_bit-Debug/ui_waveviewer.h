/********************************************************************************
** Form generated from reading UI file 'waveviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEVIEWER_H
#define UI_WAVEVIEWER_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveViewer
{
public:
    QVBoxLayout *verticalLayout;
    QChartView *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Start;
    QPushButton *startCatch;
    QPushButton *dropData;
    QLineEdit *statusMed;
    QLineEdit *statusMax;

    void setupUi(QWidget *WaveViewer)
    {
        if (WaveViewer->objectName().isEmpty())
            WaveViewer->setObjectName("WaveViewer");
        WaveViewer->resize(767, 510);
        verticalLayout = new QVBoxLayout(WaveViewer);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QChartView(WaveViewer);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout->addWidget(widget);

        Start = new QPushButton(WaveViewer);
        Start->setObjectName("Start");

        verticalLayout->addWidget(Start);

        startCatch = new QPushButton(WaveViewer);
        startCatch->setObjectName("startCatch");

        verticalLayout->addWidget(startCatch);

        dropData = new QPushButton(WaveViewer);
        dropData->setObjectName("dropData");

        verticalLayout->addWidget(dropData);

        statusMed = new QLineEdit(WaveViewer);
        statusMed->setObjectName("statusMed");
        statusMed->setReadOnly(true);

        verticalLayout->addWidget(statusMed);

        statusMax = new QLineEdit(WaveViewer);
        statusMax->setObjectName("statusMax");
        statusMax->setReadOnly(true);

        verticalLayout->addWidget(statusMax);


        retranslateUi(WaveViewer);

        QMetaObject::connectSlotsByName(WaveViewer);
    } // setupUi

    void retranslateUi(QWidget *WaveViewer)
    {
        WaveViewer->setWindowTitle(QCoreApplication::translate("WaveViewer", "Wave Viewer", nullptr));
        Start->setText(QCoreApplication::translate("WaveViewer", "Start", nullptr));
        startCatch->setText(QCoreApplication::translate("WaveViewer", "Single catch", nullptr));
        dropData->setText(QCoreApplication::translate("WaveViewer", "dropData", nullptr));
        statusMed->setText(QCoreApplication::translate("WaveViewer", "median is: ", nullptr));
        statusMax->setText(QCoreApplication::translate("WaveViewer", "maximum is:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaveViewer: public Ui_WaveViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEVIEWER_H
