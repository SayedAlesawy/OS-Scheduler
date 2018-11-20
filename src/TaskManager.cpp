#include "TaskManager.h"

// #include <iostream>
#include <QDebug>

TaskManager::TaskManager(Scheduler* scheduler)
{
    scheduler->subscribe(this);
    this->scheduler = scheduler;
    index = 0;
}

void TaskManager::submitProcesses(std::vector<Process> processes)
{
    std::sort(processes.begin(), processes.end(), comparator);
    this->processes = processes;

    qDebug() << "List of processes";
    for(auto process : this->processes)
    {
        qDebug() << process.id << " " << process.arrivalTime << " " << process.burstTime << " " << process.priority;
    }
    qDebug() << "End list";
}

void TaskManager::update(const Event& e)
{
    if(index >= processes.size() && scheduler->isQueueEmpty())
        scheduler->endSimulation();
    while(index < processes.size() && processes[index].arrivalTime <= e.timestep)
        scheduler->submitProcess(processes[index++]);
}
