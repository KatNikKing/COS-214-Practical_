#include "Cinema.h"
#include "Event.h"
#include <algorithm>
#include <iostream>

Cinema::Cinema(const std::string& name) : EventComponent(name) {}

Cinema::~Cinema() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

void Cinema::add(EventComponent* component) {
    if (component == nullptr) return;
    if (dynamic_cast<Event*>(component) != nullptr) return;
    components.push_back(component);
}

void Cinema::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return;
    components.erase(it);
}

EventComponent* Cinema::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }

    for (EventComponent* c : components) {
        EventComponent* result = c->get(name);
        if (result != nullptr) return result;
    }
    
    return nullptr;
}

void Cinema::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "Cinema: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent(level + 1);
    }
}

void Cinema::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "Cinema '" << name << "' opened. Capacity: " << capacity << "\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "Cinema '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "Cinema '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "Cinema '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "Cinema '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "Cinema '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "Cinema '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating Cinema '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "Cinema '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "Cinema '" << name << "' received a notice.\n";
            break;
    }
    for (EventComponent* c : components) {
        c->update(notice);
    }
}
