#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <map>
#include <vector>
#include <string>
#include "DateTime.h"

class EventComponent;
class Event;

/**
 * @brief Tracks which Events are booked into which EventComponent
 * resources, and over what time ranges.
 */
class Schedule {
private:
    std::map<EventComponent*, std::vector<Event*>> bookings;

public:
    explicit Schedule(EventComponent* resources);
    ~Schedule();

    void printSchedule() const;
    bool isAvailable(EventComponent* resource, DateTime start, DateTime end) const;
    bool canSchedule(Event* event) const;
    bool schedule(Event* event);
    void remove(const std::string& eventName);
    bool reschedule(const std::string& eventName, DateTime start, DateTime end);
};

#endif // SCHEDULE_H
