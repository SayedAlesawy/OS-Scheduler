#include "SchedulerFCFS.h"

void SchedulerFCFS::submitProcess(Process process)
{
    processQueue.push(process);
}

int SchedulerFCFS::currentTask()
{
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
    }
}
