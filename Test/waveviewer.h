#ifndef WAVEVIEWER_H
#define WAVEVIEWER_H

#include "qudpsocket.h"
#include <QWidget>
#include <QVector>
#include <QChart>
#include <QtCharts>


namespace Ui {
class WaveViewer;
}

class WaveViewer : public QWidget
{
    Q_OBJECT

public:
    explicit WaveViewer(QWidget *parent = nullptr);
    ~WaveViewer();

private slots:

    void readSmth();

    void parseArray();

    void drowChart();

    void on_startCatch_clicked();

    void on_dropData_clicked();

    void on_Start_clicked();

    void timeShot();

    void countMed();

    void findMax();
private:
    Ui::WaveViewer *ui;
    QUdpSocket *Socket;
    QVector<QByteArray> msgs;
    QVector<qint16> semples;
    QChart* chrt;
    QValueAxis *axisY = new QValueAxis;
    QValueAxis *axisX = new QValueAxis;
    QLineSeries *line;
    QLineSeries *median;
    double med;
    QTimer *timer = new QTimer;
    bool asking = false;
};

#endif // WAVEVIEWER_H
