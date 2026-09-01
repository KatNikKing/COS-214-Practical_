#include "ScreeningArea.h"
#include <iostream>

ScreeningArea::ScreeningArea(const std::string& name) : EventComponent(name) {}

void ScreeningArea::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "ScreeningArea: " << name << " (capacity " << capacity << ")\n";
}

void ScreeningArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "ScreeningArea '" << name << "' opened. Capacity: " << capacity << "\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "ScreeningArea '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "ScreeningArea '" << name << "' pausing playback.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "ScreeningArea '" << name << "' resuming playback.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "ScreeningArea '" << name << "' film cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "ScreeningArea '" << name << "' film rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "ScreeningArea '" << name << "' fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating ScreeningArea '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "ScreeningArea '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "ScreeningArea '" << name << "' received a notice.\n";
            break;
    }
}

EventComponent* ScreeningArea::get(std::string name) {
    if (this->name == name) return this;
    else return nullptr;
}
