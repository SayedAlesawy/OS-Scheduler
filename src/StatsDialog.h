#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QHeaderView>
#include <QTableWidgetItem>

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

private:
    class MyTableWidgetItem : public QTableWidgetItem {
    public:
        MyTableWidgetItem(const QString& txt)
        {
            setText(txt);
        }
        bool operator <(const QTableWidgetItem &other) const
        {
            return text().toInt() < other.text().toInt();
        }
    };
    Ui::StatsDialog *ui;
};

#endif // STATSDIALOG_H
