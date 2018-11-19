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
    void endSimulation();
    int currentTask();
    void setContextSwitchTime(int cst) { this->contextSwitchTime = cst; }
    virtual void submitProcess(Process process) = 0;
    virtual bool isQueueEmpty() = 0;
    virtual ~Scheduler() {};
    
protected:
    virtual void beginStep() = 0;
    virtual int _currentTask() = 0;

    int currentSlice() const;
    void switchContext();
	
private:
    int slice;
    int contextSwitchTime;
    int csRemainingTime;
    bool end;
};

#endif
