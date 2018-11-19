#ifndef SCHEDULERSRTN_H
#define SCHEDULERSRTN_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"
#include "Event.h"

class SchedulerSRTN : public Scheduler
{
public:
    SchedulerSRTN();
    void submitProcess(Process process) override;
    int _currentTask() override;
    bool isQueueEmpty() override {return processQueue.empty();}


protected:
    void beginStep() override;

private:
    struct Comparator
    {
        bool operator() (const Process& p1, const Process& p2) const
        {
            return p1.remainingTime >= p2.remainingTime;
        }
    };
    std::priority_queue<Process, std::vector<Process>, Comparator> processQueue;
};

#endif // SCHEDULERSRTN_H
