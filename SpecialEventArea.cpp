#include "SpecialEventArea.h"
#include <iostream>

SpecialEventArea::SpecialEventArea(const std::string& name) : EventComponent(name) {}

void SpecialEventArea::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "SpecialEventArea: " << name << "\n";
}

void SpecialEventArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "SpecialEventArea '" << name << "' opened.\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "SpecialEventArea '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "SpecialEventArea '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "SpecialEventArea '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "SpecialEventArea '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "SpecialEventArea '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "SpecialEventArea '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating SpecialEventArea '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "SpecialEventArea '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "SpecialEventArea '" << name << "' received a notice.\n";
            break;
    }
}

EventComponent* SpecialEventArea::get(std::string name) {
    if (this->name == name) return this;
    else return nullptr;
}
