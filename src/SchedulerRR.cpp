#include "SchedulerRR.h"
//#include<iostream>

void SchedulerRR::submitProcess(Process process)
{
	processQueue.push(process);
}

int SchedulerRR::currentTask()
{
	return currentProcess.id;
}

void SchedulerRR::beginStep()
{
	if (busy) {
		if (currentProcess.remainingTime == 0) {
			completedTask.end = currentSlice();
			busy = false;

			//std::cout << "Task finished" << std::endl;
			//std::cout << "Id = " << completedTask.id << " begin: " << completedTask.begin << " end: " << completedTask.end << std::endl;
		}
		else if (quantum == 0) {
			completedTask.end = currentSlice();
			processQueue.push(currentProcess);
			busy = false;

			//std::cout << "Run finished" << std::endl;
			//std::cout << "Id = " << completedTask.id << " begin: " << completedTask.begin << " end: " << completedTask.end << std::endl;
		}
		else {
			currentProcess.remainingTime--;
			quantum--;
		}
	}
	else {
		if (processQueue.empty()) return;

		currentProcess = processQueue.front();
		processQueue.pop();
		completedTask.begin = currentSlice();
		completedTask.id = currentProcess.id;
		busy = true;
		quantum = quanta;

		//std::cout << "New task #: " << currentProcess.id << " burst time: " << currentProcess.remainingTime << " at: " << currentSlice() << std::endl;

		currentProcess.remainingTime--;
		quantum--;
	}
}
