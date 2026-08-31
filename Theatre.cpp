#include "Theatre.h"
#include "Event.h"
#include <algorithm>
#include <iostream>

Theatre::Theatre(const std::string& name) : EventComponent(name) {}

Theatre::~Theatre() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

void Theatre::add(EventComponent* component) {
    if (component == nullptr) return;
    if (dynamic_cast<Event*>(component) != nullptr) return;
    components.push_back(component);
}

void Theatre::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return;
    components.erase(it);
}

EventComponent* Theatre::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }

    for (EventComponent* c : components) {
        EventComponent* result = c->get(name);
        if (result != nullptr) return result;
    }
    
    return nullptr;
}

void Theatre::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "Theatre: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent(level + 1);
    }
}

void Theatre::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "Theatre '" << name << "' opened. Capacity: " << capacity << "\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "Theatre '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "Theatre '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "Theatre '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "Theatre '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "Theatre '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "Theatre '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating Theatre '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "Theatre '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "Theatre '" << name << "' received a notice.\n";
            break;
    }
    for (EventComponent* c : components) {
        c->update(notice);
    }
}
