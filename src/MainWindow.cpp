#include "MainWindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    series(new QLineSeries()),
    chart(new QChart()),
    chartView(new QChartView(chart)),
    scheduler(nullptr)
{
    ui->setupUi(this);
    setUpChart();

    ui->horizontalLayout->setStretch(0, 0);
    ui->horizontalLayout->setStretch(1, 4);

    ui->comboBox->addItem("FCFS", FCFS);
    ui->comboBox->addItem("HPF", HPF);
    ui->comboBox->addItem("RR", RR);
    ui->comboBox->addItem("SRTN", SRTN);
}

void MainWindow::update(const Event& e)
{
    qDebug() << e.timestep << " " << scheduler->currentTask();
    series->append(e.timestep, scheduler->currentTask());
    series->append(e.timestep + 1, scheduler->currentTask());
    chart->axisX(series)->setMax(e.timestep);
}

void MainWindow::setUpChart()
{
    chart->addSeries(series);
    chart->legend()->markers(series)[0]->setVisible(false);
    chart->createDefaultAxes();
    ui->horizontalLayout->addWidget(chartView);
    chart->axisY(series)->setMin(-1);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseBtn_clicked()
{
    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);
    dialog.setFileMode(QFileDialog::FileMode::ExistingFile);
    dialog.exec();
    QStringList selectedFiles = dialog.selectedFiles();
    if(selectedFiles.empty()) return;
    QString selectedFile = selectedFiles[0];

    IO inputReader;
    GenerationParams params = inputReader.readParamsFile("../Input/input");
    if(inputReader.error)
    {
        QMessageBox msgBox(this);
        msgBox.setText("Couldn't open the file!");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.show();
        return;
    }
    ProcessGenerator gen(params.processesCount,
                         params.arrivalTimeMu,
                         params.arrivalTimeSigma,
                         params.burstTimeMu,
                         params.burstTimeSigma,
                         params.priorityLambda);
    processes = gen.run();
    chart->axisY(series)->setMax((int) processes.size() + 1);
    ui->fileEdit->setText(selectedFile);
}
void MainWindow::on_simulateBtn_clicked()
{
    series->clear();
    if(scheduler) delete scheduler;
    switch((SchedulerType)ui->comboBox->currentData().toInt())
    {
    case FCFS:
        scheduler = new SchedulerFCFS();
        break;
    case HPF:
        scheduler = new SchedulerHPF();
        break;
    case RR:
        scheduler = new SchedulerRR();
        break;
    case SRTN:
        scheduler = new SchedulerSRTN();
        break;
    }
    scheduler->setContextSwitchTime(ui->spinBox->value());
    TaskManager manager(scheduler);
    manager.submitProcesses(processes);
    scheduler->subscribe(this);
    scheduler->simulate();
}
