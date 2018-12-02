#include "SchedulerHPF.h"

bool flaga = true;

void SchedulerHPF::submitProcess(Process process)
{
    if(flaga){
        switchContext();
        flaga = false;
    }
    processQueue.push(process);
}

int SchedulerHPF::_currentTask()
{
    if(busy) return currentProcess.id;
    if(processQueue.empty()) {flaga = true; return 0;}
    return processQueue.top().id;
}

void SchedulerHPF::beginStep()
{
	if (busy) {
        currentProcess.remainingTime--;
	}
    else {
		if (processQueue.empty()) {
            flaga = true;
            return;
        }

		currentProcess = processQueue.top();
		processQueue.pop();
        busy = true;

		currentProcess.remainingTime--;
	}

    if (currentProcess.remainingTime == 0) {
        busy = false;
        switchContext();
	}
}
