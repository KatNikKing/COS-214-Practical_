#include "OutdoorVenue.h"
#include <algorithm>
#include <iostream>

OutdoorVenue::OutdoorVenue(const std::string& name) : EventComponent(name) {}

OutdoorVenue::~OutdoorVenue() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

void OutdoorVenue::add(EventComponent* component) {
    if (component == nullptr) return;
    if (dynamic_cast<Event*>(component) != nullptr) return;
    components.push_back(component);
}

void OutdoorVenue::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return;
    components.erase(it);
}

EventComponent* OutdoorVenue::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }

    for (EventComponent* c : components) {
        EventComponent* result = c->get(name);
        if (result != nullptr) return result;
    }
    
    return nullptr;
}

void OutdoorVenue::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "OutdoorVenue: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent(level + 1);
    }
}

void OutdoorVenue::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "OutdoorVenue '" << name << "' opened. Capacity: " << capacity << "\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "OutdoorVenue '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "OutdoorVenue '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "OutdoorVenue '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "OutdoorVenue '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "OutdoorVenue '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "OutdoorVenue '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating OutdoorVenue '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "OutdoorVenue '" << name << "' received weather alert. Evacuating.\n";
            setStatus(ResourceStatus::CLOSED);
            notice = NoticeType::EVACUATE;
        default:
            std::cout << "OutdoorVenue '" << name << "' received a notice.\n";
            break;
    }

    for (EventComponent* c : components) {
        c->update(notice);
    }
}
