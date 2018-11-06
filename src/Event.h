#ifndef EVENT_H
#define EVENT_H

#include "ScheduledTask.h"

struct Event
{
public:
    enum EventType
    {
        NEW_TIME_SLICE,
        TASK_FINISHED
    };

private:
    EventType m_eventType;

    int timestep;
    ScheduledTask task;

public:
    Event(int timestep) : m_eventType(NEW_TIME_SLICE), timestep(timestep)
    { }

    Event(ScheduledTask task) : m_eventType(TASK_FINISHED), task(task)
    { }

    int timeStep() const {if(m_eventType == NEW_TIME_SLICE) return timestep; return -1;}

    ScheduledTask finishedTask() const {if(m_eventType == TASK_FINISHED) return task; return ScheduledTask();}

    EventType eventType() const {return m_eventType;}
};

#endif 
