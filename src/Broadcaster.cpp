#include "Broadcaster.h"

void Broadcaster::subscribe(Subscriber* subscriber)
{
    subscribers.push_back(subscriber);
}

void Broadcaster::notifySubscribers(const Event& e)
{
    for(auto subscriber : subscribers)
        subscriber->update(e);
}
