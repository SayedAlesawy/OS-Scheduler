#include "SchedulerFCFS.h"

void SchedulerFCFS::submitProcess(Process process)
{
    processQueue.push(process);
}

int SchedulerFCFS::_currentTask()
{
    if(processQueue.empty())
        return -1;
    return processQueue.front().id;
}

void SchedulerFCFS::beginStep()
{
    if(processQueue.empty())
        return;

    processQueue.front().remainingTime--;

    if(processQueue.front().remainingTime == 0)
    {
        processQueue.pop();
        switchContext();
    }
}
