#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"
#include "ScheduledTask.h"
#include "Broadcaster.h"
#include "Event.h"

class Scheduler : public Broadcaster
{
public:
    void simulate();
    virtual void submitProcess(Process process) = 0;
    virtual int currentTask() = 0;
    
protected:
    virtual void beginStep() = 0;
    int currentSlice() const;

private:
    int slice;
};

#endif
