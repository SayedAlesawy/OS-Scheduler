#include "SchedulerRR.h"
//#include<iostream>

void SchedulerRR::submitProcess(Process process)
{
	processQueue.push(process);
}

int SchedulerRR::_currentTask()
{
    if(processQueue.empty()) return 0;
    return processQueue.front().id;
}

void SchedulerRR::beginStep()
{
    if (processQueue.empty()) return;
    processQueue.front().remainingTime--;
    quantum--;
    if (processQueue.front().remainingTime == 0) {
        processQueue.pop();
        switchContext();
        quantum = quanta;
    }
    else if (quantum == 0) {
        Process p = processQueue.front();
        processQueue.pop();
        processQueue.push(p);
        switchContext();
        quantum = quanta;
    }
}
