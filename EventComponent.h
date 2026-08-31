#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
#include "ResourceStatus.h"
#include "NoticeType.h"

/**
 * @brief Composite-pattern Component. Represents anything that can hold
 * or be a physical/operational resource in the festival (a whole venue,
 * a zone, or a single desk/area).
 *
 * Also acts as the Observer "leaf" of the resource-side notice cascade:
 * update() is pure virtual, so every concrete resource decides how it
 * reacts to a NoticeType. Composites additionally forward update() to
 * their children, so a notice cascades down the containment tree rather
 * than via a separate registration list (contrast with Event, which
 * uses a genuine dynamic attach/detach Observer list).
 *
 * Leaves (ScreeningArea, TicketDesk, InformationDesk, FoodArea,
 * SpecialEventArea) override printEventComponent() and update() only.
 * Composites (Zone, OutdoorVenue, Cinema, Theatre) additionally own and
 * manage children via add()/remove()/get().
 */
class EventComponent {
protected:
    std::string name;
    int capacity;
    ResourceStatus status;

public:
    explicit EventComponent(const std::string& name);
    virtual ~EventComponent();

    virtual void printEventComponent(int level) const = 0;

    std::string getName() const;
    int getCapacity() const;
    ResourceStatus getStatus() const;
    void setCapacity(int capacity);
    void setStatus(ResourceStatus status);
    virtual void update(NoticeType notice) = 0;
    virtual void add(EventComponent* component);
    virtual void remove(EventComponent* component);
    virtual EventComponent* get(const std::string& name);
};

#endif
