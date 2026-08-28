#ifndef FILMFESTIVAL_H
#define FILMFESTIVAL_H

#include <vector>
#include "Event.h"

class EventComponent;
class Schedule;

/**
 * @brief Top-level coordinator (EventControl). Owns the list of Events
 * and the Schedule; aggregates (does not own) the festival's
 * EventComponent resource tree.
 */
class FilmFestival {
private:
    std::vector<Event*> events;
    Schedule* schedule;
    EventComponent* resources;

public:
    explicit FilmFestival(EventComponent* resources);
    ~FilmFestival();

    void printEvents() const;
    void printSchedule() const;
    void printResources() const;

    bool scheduleEvent(Event* event);
    bool rescheduleEvent(const std::string& event);
    bool removeEvent(const std::string& event);

    EventComponent* getResources() const;

    void plan();
    void start();
};

#endif // FILMFESTIVAL_H
