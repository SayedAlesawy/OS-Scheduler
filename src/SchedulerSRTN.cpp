#include "SchedulerSRTN.h"

SchedulerSRTN::SchedulerSRTN()
{ }

void SchedulerSRTN::submitProcess(Process process)
{
    processQueue.push(process);
}


int SchedulerSRTN::currentTask()
{
    return processQueue.top().id;
}

void SchedulerSRTN::beginStep()
{
    if(processQueue.empty()) return;
    Process p = processQueue.top();
    processQueue.pop();
    p.remainingTime--;
    if(p.remainingTime != 0)
        processQueue.push(p);
}

