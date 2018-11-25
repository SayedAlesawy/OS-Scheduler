#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QFileDialog>
#include "ProcessStat.h"
#include "IO.h"
#include "Process.h"

namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(std::vector<Process> processes, QWidget *parent = nullptr);
    ~StatsDialog();

private slots:
    void on_pushButton_clicked();

private:
    class MyTableWidgetItem : public QTableWidgetItem {
    public:
        MyTableWidgetItem(const QString& txt, int sortingOrder=0) :
            sortingOrder(sortingOrder)
        {
            setText(txt);
        }
        bool operator <(const QTableWidgetItem &other) const
        {
            if(sortingOrder == 0)
                return text().toInt() < other.text().toInt();
            else
                return text().toInt() > other.text().toInt();
        }
    private:
        int sortingOrder;
    };
    Ui::StatsDialog *ui;
};

#endif // STATSDIALOG_H
