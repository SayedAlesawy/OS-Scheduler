#ifndef OBSERVER_H
#define OBSERVER_H

#include "Event.h"

class Subscriber
{
public:
    virtual void update(const Event& e) = 0;
    virtual ~Subscriber() {};
};

#endif 
