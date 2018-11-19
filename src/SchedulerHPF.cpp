#include "SchedulerHPF.h"
//#include <iostream>

void SchedulerHPF::submitProcess(Process process)
{
	processQueue.push(process);
}

int SchedulerHPF::_currentTask()
{
    if(busy)
        return currentProcess.id;
    if(processQueue.empty())
        return -1;
    return processQueue.top().id;
}

void SchedulerHPF::beginStep()
{
	if (busy) {
		if (currentProcess.remainingTime == 0) {
            busy = false;
            switchContext();
			//std::cout << "Task finished, priority: " << currentProcess.priority << " " << std::endl;
			//std::cout << "Id = " << completedTask.id << " begin: " << completedTask.begin << " end: " << completedTask.end << std::endl;
		}
		else currentProcess.remainingTime--;
	}
	else {
		if (processQueue.empty()) return;

		currentProcess = processQueue.top();
		processQueue.pop();
        busy = true;

		//std::cout << "New task #: " << currentProcess.id << " priority: " << currentProcess.priority << " at: " << currentSlice() << std::endl;

		currentProcess.remainingTime--;
	}
}
