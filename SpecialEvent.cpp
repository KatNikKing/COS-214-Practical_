#include "SpecialEvent.h"
#include "EventComponent.h"
#include <iostream>

SpecialEvent::SpecialEvent(const std::string& name, const std::string& description,
                            SpecialEventType type, const std::string& host)
    : Event(name, description), type(type), host(host) {}

SpecialEvent::~SpecialEvent() {}

void SpecialEvent::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "SpecialEvent '" << name << "' started. Description: " << description << "\n";
            setEventStatus(EventStatus::IN_PROGRESS);
            break;
        case NoticeType::CLOSE:
            std::cout << "SpecialEvent '" << name << "' ended.\n";
            setEventStatus(EventStatus::COMPLETED);
            break;
        case NoticeType::PAUSE:
            std::cout << "SpecialEvent '" << name << "' pausing screening.\n";
            setEventStatus(EventStatus::PAUSED);
            break;
        case NoticeType::RESUME:
            std::cout << "SpecialEvent '" << name << "' resuming screening.\n";
            setEventStatus(EventStatus::IN_PROGRESS);
            break;
        case NoticeType::CANCEL:
            std::cout << "SpecialEvent '" << name << "' cancelled.\n";
            setEventStatus(EventStatus::CANCELLED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "SpecialEvent '" << name << "' rescheduled.\n";
            setEventStatus(EventStatus::RESCHEDULED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "SpecialEvent '" << name << "' fully booked.\n";
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating SpecialEvent '" << name << "'.\n";
            setEventStatus(EventStatus::POSTPONED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "SpecialEvent '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "SpecialEvent '" << name << "' received a notice.\n";
            break;
    }
    currentNotice = notice;
    notify();
}

void SpecialEvent::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "SpecialEvent: " << name << "\n";
    for (EventComponent* c : resources) {
        c->printEventComponent(level + 1);
    }
}
