#ifndef SCHEDULERFCFS_H
#define SCHEDULERFCFS_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"
#include "ScheduledTask.h"

class SchedulerFCFS : public Scheduler
{
public:
    void submitProcess(Process process) override;
    int currentTask() override;
    
protected:
    void beginStep() override;

private:
    std::queue<Process> processQueue;
    ScheduledTask completedTask;
};

#endif 
