#include "Event.h"
#include "EventComponent.h"
#include <algorithm>

Event::Event(const std::string& name, const std::string& description)
    : name(name), description(description), scheduled(false) {}

Event::~Event() {
    // Non-owning: do not delete resources or dependants here.
    // TODO: decide/implement safe detach-on-destruction policy so that
    // dependants don't hold dangling pointers to this Event.
}

void Event::attach(Event* event) {
    if (event == nullptr) return;
    if (std::find(dependants.begin(), dependants.end(), event) != dependants.end()) {
        return; // TODO: confirm duplicate-registration policy
    }
    dependants.push_back(event);
}

void Event::detach(Event* event) {
    auto it = std::find(dependants.begin(), dependants.end(), event);
    if (it != dependants.end()) {
        dependants.erase(it);
    }
    // TODO: decide policy for detach() called with an unregistered observer
}

void Event::notify() {
    for (Event* dependant : dependants) {
        dependant->update(start, end);
    }
}

void Event::update(DateTime start, DateTime end) {
    // Default: do nothing. Concrete Events override to react.
}

void Event::setDateTime(DateTime start, DateTime end) {
    this->start = start;
    this->end = end;
}

void Event::setResources(std::vector<EventComponent*> resources) {
    this->resources = resources;
}

bool Event::isScheduled() const {
    return scheduled;
}

std::string Event::getName() const {
    return name;
}
