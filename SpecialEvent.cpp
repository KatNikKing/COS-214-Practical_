#include "SpecialEvent.h"
#include <iostream>

SpecialEvent::SpecialEvent(const std::string& name, const std::string& description,
                            SpecialEventType type, const std::string& host)
    : Event(name, description), type(type), host(host) {}

SpecialEvent::~SpecialEvent() {}

void SpecialEvent::start_event() {
    std::cout << "SpecialEvent '" << name << "' is starting.\n";
    notify();
}

void SpecialEvent::update(DateTime start, DateTime end) {
    // TODO: react to a dependency changing, e.g. reschedule this event
    setDateTime(start, end);
}
