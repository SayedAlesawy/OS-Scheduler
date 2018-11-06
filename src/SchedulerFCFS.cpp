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

    if(processQueue.front().remainingTime == processQueue.front().burstTime) {
        completedTask.begin = currentSlice();
        completedTask.id = processQueue.front().id;
    }
    if(processQueue.front().remainingTime == 0)
    {
        completedTask.end = currentSlice();
        processQueue.pop();
        notifySubscribers(Event(completedTask));
    }
    else
    {
        processQueue.front().remainingTime--;
    }
}
