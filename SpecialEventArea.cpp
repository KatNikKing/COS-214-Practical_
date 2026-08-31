#include "SpecialEventArea.h"
#include <iostream>

SpecialEventArea::SpecialEventArea(const std::string& name) : EventComponent(name) {}

void SpecialEventArea::printEventComponent() const {
    std::cout << "SpecialEventArea: " << name << "\n";
}

void SpecialEventArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "SpecialEventArea " << name << " reprinting running order.\n";
            break;
        case NoticeType::CANCEL:
            setStatus(ResourceStatus::CLOSED);
            std::cout << "SpecialEventArea " << name << " cancelling programme.\n";
            break;
        case NoticeType::EVACUATE:
            setStatus(ResourceStatus::CLOSED);
            std::cout << "SpecialEventArea " << name << " clearing the area.\n";
            break;
        default:
            break;
    }
}
