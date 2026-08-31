#include "ScreeningArea.h"
#include <iostream>

ScreeningArea::ScreeningArea(const std::string& name) : EventComponent(name) {}

void ScreeningArea::printEventComponent() const {
    std::cout << "ScreeningArea: " << name << " (capacity " << capacity << ")\n";
}

void ScreeningArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::PAUSE:
        case NoticeType::WEATHER_ALERT:
            setStatus(ResourceStatus::SUSPENDED);
            std::cout << "ScreeningArea " << name << " pausing playback.\n";
            break;
        case NoticeType::RESUME:
            setStatus(ResourceStatus::OPEN);
            std::cout << "ScreeningArea " << name << " resuming playback.\n";
            break;
        case NoticeType::EVACUATE:
            setStatus(ResourceStatus::CLOSED);
            std::cout << "ScreeningArea " << name << " clearing the room.\n";
            break;
        default:
            break;
    }
}
