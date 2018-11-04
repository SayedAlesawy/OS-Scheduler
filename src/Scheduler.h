#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"
#include "ScheduledTask.h"

class Scheduler
{
    typedef std::vector<Process>::iterator ProcessIterator;
    typedef std::vector<ScheduledTask> ScheduledTaskIterator;

    virtual bool submitProcesses(ProcessIterator begin, ProcessIterator end) = 0;
    virtual void simulate() = 0;
    virtual ScheduledTaskIterator outputBegin() = 0;
    virtual ScheduledTaskIterator outputEnd() = 0;

    virtual ~Scheduler() = 0;
};

#endif
