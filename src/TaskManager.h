#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <algorithm>
#include <queue>
#include "Process.h"
#include "Scheduler.h"
#include "Subscriber.h"

class TaskManager : public Subscriber
{
public:
    TaskManager(Scheduler* scheduler);
    void submitProcesses(std::vector<Process> processes);
    void update(const Event& e) override;
    ~TaskManager() {};

private:
    static bool comparator(const Process& p1, const Process& p2)
    {
        return p1.arrivalTime < p2.arrivalTime;
    }

    std::vector<Process> processes;
    Scheduler* scheduler;
    size_t index;
};

#endif 
