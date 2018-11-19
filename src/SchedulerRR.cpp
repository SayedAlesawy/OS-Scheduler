#include "SchedulerRR.h"
//#include<iostream>

void SchedulerRR::submitProcess(Process process)
{
	processQueue.push(process);
}

int SchedulerRR::_currentTask()
{
	return currentProcess.id;
}

void SchedulerRR::beginStep()
{
	if (busy) {
        if (quantum == 0) {
            processQueue.push(currentProcess);
			busy = false;
            switchContext();
			//std::cout << "Run finished" << std::endl;
			//std::cout << "Id = " << completedTask.id << " begin: " << completedTask.begin << " end: " << completedTask.end << std::endl;
		}
		else {
			currentProcess.remainingTime--;
			quantum--;
            if (currentProcess.remainingTime == 0) {
                busy = false;
                switchContext();
                //std::cout << "Task finished" << std::endl;
                //std::cout << "Id = " << completedTask.id << " begin: " << completedTask.begin << " end: " << completedTask.end << std::endl;
            }
		}
	}
	else {
		if (processQueue.empty()) return;

		currentProcess = processQueue.front();
		processQueue.pop();
        busy = true;
		quantum = quanta;

		//std::cout << "New task #: " << currentProcess.id << " burst time: " << currentProcess.remainingTime << " at: " << currentSlice() << std::endl;

		currentProcess.remainingTime--;
		quantum--;
	}
}
