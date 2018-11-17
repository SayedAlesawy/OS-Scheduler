#ifndef EVENT_H
#define EVENT_H

struct Event
{
    int timestep;
    Event(int timestep) : timestep(timestep)
    { }
};

#endif 
