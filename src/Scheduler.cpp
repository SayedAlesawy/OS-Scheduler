#include "Scheduler.h"

void Scheduler::simulate()
{
    for(slice = 0; ; slice++)
    {
        notifySubscribers(Event(slice));
        beginStep();
    }
}

int Scheduler::currentSlice() const
{
    return slice;
}
