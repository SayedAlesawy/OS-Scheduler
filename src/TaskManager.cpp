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
    switch(e.eventType())
    {
		case Event::NEW_TIME_SLICE:
			while(index < processes.size() && processes[index].arrivalTime == e.timeStep())
				scheduler->submitProcess(processes[index++]);
			break;
		case Event::TASK_FINISHED:
			ScheduledTask task = e.finishedTask();
			break;
    }
}
