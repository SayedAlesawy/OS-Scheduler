#ifndef SCHEDULERRR_H
#define SCHEDULERRR_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"

class SchedulerRR : public Scheduler
{
public:
    SchedulerRR(int quanta);
	void submitProcess(Process process) override;
    int _currentTask() override;
    bool isQueueEmpty() override {return processQueue.empty();}

protected:
	void beginStep() override;

private:
	std::queue<Process> processQueue;
	int quantum = 5, quanta = 5;
};

#endif 
