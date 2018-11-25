#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QScrollArea>

#include "ProcessGenerator.h"
#include "GenerationParams.h"
#include "Process.h"
#include "IO.h"
#include "SchedulerFCFS.h"
#include "SchedulerHPF.h"
#include "SchedulerRR.h"
#include "SchedulerSRTN.h"
#include "TaskManager.h"
#include "StatsDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Subscriber
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUpChart();

    void update(const Event& e) override;

private slots:
    void on_browseBtn_clicked();
    void on_simulateBtn_clicked();
    void on_showStatsBtn_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    enum SchedulerType : int
    {
        FCFS, HPF, RR, SRTN
    };

    Ui::MainWindow *ui;

    QtCharts::QLineSeries* series;
    QtCharts::QChart* chart;
    QtCharts::QChartView* chartView;

    vector<Process> processes;
    Scheduler* scheduler;
};

#endif // MAINWINDOW_H
