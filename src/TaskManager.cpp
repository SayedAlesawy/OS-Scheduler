#include "TaskManager.h"

#include <iostream>

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

    for(auto process : this->processes)
    {
		std::cout << process.id << " " << process.arrivalTime << " " << process.burstTime << " " << process.priority << '\n';
    }
}

void TaskManager::update(const Event& e)
{
    while(index < processes.size() && processes[index].arrivalTime >= e.timestep)
        scheduler->submitProcess(processes[index++]);
}
