#include "SpecialEvent.h"
#include <iostream>

SpecialEvent::SpecialEvent(const std::string& name, const std::string& description,
                            SpecialEventType type, const std::string& host)
    : Event(name, description), type(type), host(host) {}

SpecialEvent::~SpecialEvent() {}

void SpecialEvent::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::CANCEL:
            std::cout << "SpecialEvent '" << name << "' cancelled.\n";
            setEventStatus(EventStatus::CANCELLED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "SpecialEvent '" << name << "' rescheduled.\n";
            setEventStatus(EventStatus::RESCHEDULED);
            break;
        default:
            std::cout << "SpecialEvent '" << name << "' received a notice.\n";
            break;
    }
    currentNotice = notice;
    notify();
}
