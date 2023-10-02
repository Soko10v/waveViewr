#include "waveviewer.h"
#include "ui_waveviewer.h"

#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include <QChart>
#include <QTimer>

WaveViewer::WaveViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaveViewer)
{
    ui->setupUi(this);

    /// graphik
    chrt = new QChart;

    ui->widget->setChart(chrt);

    chrt->setTitle("График");
    axisX->setRange(0,4500);
    axisX->setLabelFormat("%.2f");
    axisY->setRange(-100, 4500);
    axisY->setLabelFormat("%g");


    chrt->addAxis(axisX, Qt::AlignBottom);
    chrt->addAxis(axisY, Qt::AlignLeft);

    line = new QLineSeries;
     line->setName("Datagram");

    timer->setInterval(10);
    connect(timer, &QTimer::timeout, this, &WaveViewer::timeShot);

    Socket  = new QUdpSocket;
    Socket->bind(QHostAddress::LocalHost, 10002);
}

WaveViewer::~WaveViewer()
{
    delete ui;
}

void WaveViewer::readSmth()
{
    QHostAddress addr;
    quint16 senderport = 10002;
    while(Socket->hasPendingDatagrams()){
        QByteArray data;
        data.resize(Socket->pendingDatagramSize());
        Socket->readDatagram(data.data(), data.size(), &addr, &senderport );
        msgs.push_back(data);

    }
    parseArray();
}

void WaveViewer::parseArray()
{
    semples.clear();
    for(const auto& msg : msgs )
        for(int i =0; i< 8192; i= i+2){
            QByteArray sempleByte;
            sempleByte.push_back(msg[i]);
            sempleByte.push_back(msg[i+1]);
            QDataStream ds(sempleByte);
            short  size;
            ds>>size;
            semples.push_back(size);
        }
}

void WaveViewer::drowChart()
{
    if(semples.size() == 0)
        return;
    line->clear();
    chrt->removeSeries(line);
    for(int i =0; i< semples.size(); i++)
        line->append(i,semples[i]);
    chrt->addSeries(line);
}

void WaveViewer::on_startCatch_clicked()
{
    readSmth();
    //qDebug()<<semples.size();
    drowChart();
    countMed();
    findMax();
    chrt->removeAxis(axisX);
    axisX->setMax(semples.size());
    chrt->addAxis(axisX,  Qt::AlignBottom);
}


void WaveViewer::on_dropData_clicked()
{
    semples.clear();
    msgs.clear();
    //qDebug()<<semples.size();
    line->clear();

}

void WaveViewer::on_Start_clicked()
{
    if(asking)
    {
        asking = false;
        timer->stop();
        ui->Start->setText("start");
    }
    else
    {
        asking = true;
        timer->start();
        ui->Start->setText("stop");

    }
    //qDebug()<<"start";
}

void WaveViewer::timeShot()
{
    readSmth();
   //qDebug()<<semples.size();
    drowChart();
    countMed();
    findMax();
    chrt->removeAxis(axisX);
    axisX->setMax(semples.size());
    chrt->addAxis(axisX,  Qt::AlignBottom);
}

void WaveViewer::countMed()
{
    if(semples.size() == 0)
        return;
    med =0;

    for(const auto& el : semples){
        med += el ;
    }
    med = med/(semples.size());
    QString msgMed = "Median: " + QString::number(med);
    ui->statusMed->setText(msgMed);
}

void WaveViewer::findMax()
{
    if(semples.size() == 0)
        return;
    int max = semples[0];
    int numMax = 0;
    for(int i =0; i< semples.size(); i++)
    {
        if(max<semples[i])
        {
            max = semples[i];
            numMax =i;
        }
    }

    QString msgMax = "Maximum is: " + QString::number( max) + " element: "+ QString::number( numMax);
    ui->statusMax->setText(msgMax);
}

