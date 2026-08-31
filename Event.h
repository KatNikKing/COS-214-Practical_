#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include "EventStatus.h"
#include "NoticeType.h"

class EventComponent;

/**
 * @brief Abstract festival event. Doubles as both Subject and Observer:
 * an Event can notify() its dependants (other Events observing it, e.g.
 * a panel that depends on a screening) and is itself updated via
 * update(NoticeType) when a notice is sent to it (e.g. by
 * FilmFestival::sendNotice()).
 *
 * Observer registration (dependants) is a non-owning relationship,
 * distinct from resource ownership (resources).
 *
 * NOTE: update(NoticeType) and the stored `currentNotice` are not shown
 * explicitly on the Event box in the latest class diagram, but
 * FilmShowing/SpecialEvent both override update(), which only compiles
 * if Event declares it -- confirm with your team that this is the
 * intended shape before treating it as final.
 */
class Event {
protected:
    std::string name;
    std::string description;
    EventStatus eventStatus;
    std::vector<EventComponent*> resources; 
    std::vector<Event*> dependants;         
    NoticeType currentNotice;               

public:
    Event(const std::string& name, const std::string& description);
    virtual ~Event();

    void setEventStatus(EventStatus status);
    EventStatus getEventStatus() const;

    void attach(Event* event);
    void detach(Event* event);
    void notify();
    virtual void update(NoticeType notice) = 0;
    void add(EventComponent* component);
    void remove(EventComponent* component);
    EventComponent* get(const std::string& name);

    std::string getName() const;
};

#endif 
