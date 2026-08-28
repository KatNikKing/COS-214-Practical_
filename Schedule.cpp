#include "Schedule.h"
#include "EventComponent.h"
#include "Event.h"
#include <iostream>

Schedule::Schedule(EventComponent* resources) {
    // TODO: seed bookings map from the resource tree if needed
}

Schedule::~Schedule() {
    // Non-owning: Schedule does not own EventComponents or Events.
}

void Schedule::printSchedule() const {
    std::cout << "Schedule: " << bookings.size() << " resource(s) booked.\n";
}

bool Schedule::isAvailable(EventComponent* resource, DateTime start, DateTime end) const {
    // TODO: check bookings[resource] for overlapping time ranges
    return true;
}

bool Schedule::canSchedule(Event* event) const {
    // TODO: check event's resources are all isAvailable() for its DateTime range
    return true;
}

bool Schedule::schedule(Event* event) {
    // TODO: record the booking in bookings map
    return true;
}

void Schedule::remove(const std::string& eventName) {
    // TODO: find and erase the matching booking entries
}

bool Schedule::reschedule(const std::string& eventName, DateTime start, DateTime end) {
    // TODO: locate the event and update its DateTime + booking entries
    return true;
}
