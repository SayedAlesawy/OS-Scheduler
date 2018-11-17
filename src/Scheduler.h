#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"
#include "Broadcaster.h"
#include "Event.h"

class Scheduler : public Broadcaster
{
public:
    Scheduler(int contextSwitchTime=0);

    void simulate();
    virtual void submitProcess(Process process) = 0;
    virtual int currentTask() = 0;
    virtual ~Scheduler() {};
    
protected:
    virtual void beginStep() = 0;
    int currentSlice() const;
    void switchContext();
	
private:
    int slice;
    const int contextSwitchTime;
    int csRemainingTime;
};

#endif
