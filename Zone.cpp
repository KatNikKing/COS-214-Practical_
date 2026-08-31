#include "Zone.h"
#include "Event.h"
#include <algorithm>
#include <iostream>

Zone::Zone(const std::string& name) : EventComponent(name) {}

Zone::~Zone() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

void Zone::add(EventComponent* component) {
    if (component == nullptr) return;
    if (dynamic_cast<Event*>(component) != nullptr) return;
    components.push_back(component);
}

void Zone::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return;
    components.erase(it);
}

EventComponent* Zone::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }

    for (EventComponent* c : components) {
        EventComponent* result = c->get(name);
        if (result != nullptr) return result;
    }
    
    return nullptr;
}

void Zone::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "Zone: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent(level + 1);
    }
}

void Zone::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "Zone '" << name << "' opened. Capacity: " << capacity << "\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "Zone '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "Zone '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "Zone '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "Zone '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "Zone '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "Zone '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating Zone '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "Zone '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "Zone '" << name << "' received a notice.\n";
            break;
    }

    for (EventComponent* c : components) {
        c->update(notice);
    }
}
