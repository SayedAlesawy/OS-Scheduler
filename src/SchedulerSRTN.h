#ifndef SCHEDULERSRTN_H
#define SCHEDULERSRTN_H

#include <queue>
#include "Scheduler.h"
#include "Process.h"
#include "ScheduledTask.h"
#include "Event.h"

class SchedulerSRTN : public Scheduler
{
public:
    SchedulerSRTN();
    void submitProcess(Process process) override;
    int currentTask() override;

protected:
    void beginStep() override;

private:
    struct Comparator
    {
        bool operator() (const Process& p1, const Process& p2) const
        {
            return p1.remainingTime < p2.remainingTime;
        }
    };
    typedef std::priority_queue<Process, std::vector<Process>, Comparator> PriorityQueue;

    PriorityQueue processQueue;
};

#endif // SCHEDULERSRTN_H