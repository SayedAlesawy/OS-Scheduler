#ifndef BROADHCASTER_H
#define BROADHCASTER_H

#include <list>

#include "Event.h"
#include "Subscriber.h"

class Broadcaster
{
public:
    void subscribe(Subscriber* subscriber);
    virtual ~Broadcaster() {};

protected:
    void notifySubscribers(const Event& e);

private:
    std::list<Subscriber*> subscribers;
};

#endif 
