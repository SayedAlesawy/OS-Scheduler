#ifndef SCHEDULERHPF_H
#define SCHEDULERHPF_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"

class SchedulerHPF : public Scheduler
{
public:
	void submitProcess(Process process) override;
    int _currentTask() override;
    bool isQueueEmpty() override {return processQueue.empty() && !busy;}

protected:
	void beginStep() override;

private:
	struct Comparator {
		public:
			bool operator() (Process p1, Process p2) {
				return p1.priority < p2.priority;
			}
	};

	std::priority_queue <Process, std::vector<Process>, Comparator> processQueue;
	Process currentProcess;
	bool busy = false;
};

#endif 
