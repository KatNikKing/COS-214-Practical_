#include "Event.h"
#include "EventComponent.h"
#include <algorithm>

Event::Event(const std::string& name, const std::string& description)
    : EventComponent(name), description(description),
      eventStatus(EventStatus::SCHEDULED), currentNotice(NoticeType::CLOSE) {}

Event::~Event() {
    for (EventComponent* resource : resources)
        delete resource;
}

void Event::setEventStatus(EventStatus status) {
    this->eventStatus = status;
}

EventStatus Event::getEventStatus() const {
    return eventStatus;
}

void Event::attach(Event* event) {
    if (event == nullptr) return;
    if (std::find(dependants.begin(), dependants.end(), event) != dependants.end()) {
        return; 
    }
    dependants.push_back(event);
}

void Event::detach(Event* event) {
    auto it = std::find(dependants.begin(), dependants.end(), event);
    if (it != dependants.end()) {
        dependants.erase(it);
    }
}

void Event::notify() {
    for (EventComponent* resource : resources) {
        resource->update(currentNotice);
    }
    
    for (Event* dependant : dependants) {
        dependant->update(currentNotice);
    }    
}

void Event::add(EventComponent* component) {
    if (component == nullptr) return;
    if (std::find(resources.begin(), resources.end(), component) != resources.end()) return;
    resources.push_back(component);
}

void Event::remove(EventComponent* component) {
    auto it = std::find(resources.begin(), resources.end(), component);
    if (it != resources.end()) {
        resources.erase(it);
    }
}

EventComponent* Event::get(const std::string& name) {
    for (EventComponent* c : resources) {
        if (c->getName() == name) return c;
    }

    for (EventComponent* c : resources) {
        EventComponent* result = c->get(name);
        if (result != nullptr) return result;
    }
    
    return nullptr;
}

std::string Event::getName() const {
    return name;
}
