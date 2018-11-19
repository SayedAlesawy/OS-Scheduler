#include "SchedulerSRTN.h"

SchedulerSRTN::SchedulerSRTN()
{ }

void SchedulerSRTN::submitProcess(Process process)
{
    int lastId = -1;
    if(!processQueue.empty())
        lastId = processQueue.top().id;
    processQueue.push(process);
    if(lastId != processQueue.top().id)
        switchContext();
}


int SchedulerSRTN::_currentTask()
{
    if(processQueue.empty())
        return -1;
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
    else
        switchContext();
}

