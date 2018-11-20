#include "Scheduler.h"

Scheduler::Scheduler(int contextSwitchTime) :
    contextSwitchTime(contextSwitchTime),
    csRemainingTime(0)
{ }

void Scheduler::simulate()
{
    end = false;
    for(slice = 0; !end; slice++)
    {
        notifySubscribers(Event(slice));
        if(csRemainingTime > 0)
            csRemainingTime--;
        else
            beginStep();
    }
}

void Scheduler::endSimulation()
{
    end = true;
}


int Scheduler::currentTask()
{
    if(csRemainingTime > 0)
        return 0;
    return _currentTask();
}

int Scheduler::currentSlice() const
{
    return slice;
}

void Scheduler::switchContext()
{
    csRemainingTime = contextSwitchTime;
}
