#include "Scheduler.h"

Scheduler::Scheduler(int contextSwitchTime) :
    contextSwitchTime(contextSwitchTime),
    csRemainingTime(0)
{ }

void Scheduler::simulate()
{
    for(slice = 0; ; slice++)
    {
        notifySubscribers(Event(slice));
        if(csRemainingTime > 0)
            csRemainingTime--;
        else
            beginStep();
    }
}

int Scheduler::currentSlice() const
{
    return slice;
}

void Scheduler::switchContext()
{
    csRemainingTime = contextSwitchTime;
}
