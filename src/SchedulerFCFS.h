#ifndef SCHEDULERFCFS_H
#define SCHEDULERFCFS_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"

class SchedulerFCFS : public Scheduler
{
public:
    void submitProcess(Process process) override;
    int _currentTask() override;
    bool isQueueEmpty() override {return processQueue.empty();}
    
protected:
    void beginStep() override;

private:
    std::queue<Process> processQueue;
};

#endif 
