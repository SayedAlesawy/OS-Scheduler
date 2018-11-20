#include "StatsDialog.h"
#include "ui_statsdialog.h"


StatsDialog::StatsDialog(std::vector<Process> processes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsDialog)
{
    ui->setupUi(this);
    QStringList headerLabels =
    {
        "Id", "Priority", "Arrival Time", "Burst Time",
        "Finish Time", "Waiting Time", "TAT", "Weighted TAT"
    };
    ui->tableWidget->setColumnCount(headerLabels.size());
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    ui->tableWidget->setRowCount(processes.size());
    for(size_t i = 0; i < processes.size(); i++)
    {
        int turnaround = processes[i].finishTime - processes[i].arrivalTime;
        float weightedTurnaround = ((float)turnaround) / processes[i].burstTime;
        int waitingTime = turnaround - processes[i].burstTime;

        MyTableWidgetItem* idL = new MyTableWidgetItem(QString::number(processes[i].id));
        MyTableWidgetItem* priorityL = new MyTableWidgetItem(QString::number(processes[i].priority));
        MyTableWidgetItem* arriveL = new MyTableWidgetItem(QString::number(processes[i].arrivalTime));
        MyTableWidgetItem* burstL = new MyTableWidgetItem(QString::number(processes[i].burstTime));
        MyTableWidgetItem* finishL = new MyTableWidgetItem(QString::number(processes[i].finishTime));
        MyTableWidgetItem* waitingL = new MyTableWidgetItem(QString::number(waitingTime));
        MyTableWidgetItem* tatL = new MyTableWidgetItem(QString::number(turnaround));
        MyTableWidgetItem* wtatL = new MyTableWidgetItem(QString::number(weightedTurnaround));

        ui->tableWidget->setItem(i, 0, idL);
        ui->tableWidget->setItem(i, 1, priorityL);
        ui->tableWidget->setItem(i, 2, arriveL);
        ui->tableWidget->setItem(i, 3, burstL);
        ui->tableWidget->setItem(i, 4, finishL);
        ui->tableWidget->setItem(i, 5, waitingL);
        ui->tableWidget->setItem(i, 6, tatL);
        ui->tableWidget->setItem(i, 7, wtatL);
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
    ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
    ui->tableWidget->setSortingEnabled(true);

    QTableWidget* table = ui->tableWidget;
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, [table](QTableWidgetItem* item)
    {
        for(int i = 0; i < table->columnCount(); i++)
        if(item == table->horizontalHeaderItem(i))
        {
            table->sortByColumn(i);
            break;
        }
    });

}

StatsDialog::~StatsDialog()
{
    delete ui;
}
