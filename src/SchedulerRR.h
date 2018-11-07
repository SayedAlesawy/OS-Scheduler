#ifndef SCHEDULERRR_H
#define SCHEDULERRR_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"
#include "ScheduledTask.h"

class SchedulerRR : public Scheduler
{
public:
	void submitProcess(Process process) override;
	int currentTask() override;

protected:
	void beginStep() override;

private:
	std::queue<Process> processQueue;
	ScheduledTask completedTask;
	Process currentProcess;
	bool busy = false;
	int quantum = 5, quanta = 5;
};

#endif 
