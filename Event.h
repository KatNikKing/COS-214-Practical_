#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include "DateTime.h"

class EventComponent;

/**
 * @brief Abstract festival event. Doubles as both Subject and Observer:
 * an Event can notify() its dependants (other Events observing it, e.g.
 * a panel that depends on a screening's schedule) and can itself be
 * updated when an Event it depends on changes.
 *
 * Observer registration (dependants) is a non-owning relationship,
 * distinct from resource ownership (resources).
 */
class Event {
protected:
    std::string name;
    std::string description;
    DateTime start;
    DateTime end;
    bool scheduled;
    std::vector<EventComponent*> resources;
    std::vector<Event*> dependants; // non-owning: registered observers

public:
    Event(const std::string& name, const std::string& description);
    virtual ~Event();

    void attach(Event* event);
    void detach(Event* event);
    void notify();

    // Pull/push hook: dependants are told what changed. Concrete Events
    // decide how to react (e.g. reschedule themselves).
    virtual void update(DateTime start, DateTime end);

    void setDateTime(DateTime start, DateTime end);
    void setResources(std::vector<EventComponent*> resources);
    bool isScheduled() const;

    std::string getName() const;

    virtual void start_event() = 0; // named to avoid clashing with `start` member
};

#endif // EVENT_H
