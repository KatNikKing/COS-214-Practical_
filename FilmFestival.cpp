#include "FilmFestival.h"
#include "EventComponent.h"
#include "Schedule.h"
#include <algorithm>
#include <iostream>

FilmFestival::FilmFestival(EventComponent* resources)
    : schedule(new Schedule(resources)), resources(resources) {}

FilmFestival::~FilmFestival() {
    // FilmFestival owns its Events and its Schedule...
    for (Event* e : events) {
        delete e;
    }
    delete schedule;
    // ...but does NOT own `resources` (composite-diamond aggregation in
    // the class diagram) -- TODO: confirm and document this ownership
    // decision in the design rationale.
}

void FilmFestival::printEvents() const {
    for (Event* e : events) {
        std::cout << "Event: " << e->getName() << "\n";
    }
}

void FilmFestival::printSchedule() const {
    if (schedule != nullptr) schedule->printSchedule();
}

void FilmFestival::printResources() const {
    if (resources != nullptr) resources->printResources();
}

bool FilmFestival::scheduleEvent(Event* event) {
    if (event == nullptr || schedule == nullptr) return false;
    if (!schedule->canSchedule(event)) return false;
    events.push_back(event);
    return schedule->schedule(event);
}

bool FilmFestival::rescheduleEvent(const std::string& event) {
    // TODO: look up new DateTime for `event` and call schedule->reschedule(...)
    return false;
}

bool FilmFestival::removeEvent(const std::string& event) {
    auto it = std::find_if(events.begin(), events.end(), [&](Event* e) {
        return e->getName() == event;
    });
    if (it == events.end()) return false;
    if (schedule != nullptr) schedule->remove(event);
    delete *it;
    events.erase(it);
    return true;
}

EventComponent* FilmFestival::getResources() const {
    return resources;
}

void FilmFestival::plan() {
    // TODO: high-level planning pass, e.g. attempt to schedule all events
}

void FilmFestival::start() {
    for (Event* e : events) {
        e->start_event();
    }
}
