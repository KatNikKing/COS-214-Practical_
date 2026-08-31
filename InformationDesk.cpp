#include "InformationDesk.h"
#include <iostream>

InformationDesk::InformationDesk(const std::string& name) : EventComponent(name) {}

void InformationDesk::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "InformationDesk: " << name << "\n";
}

void InformationDesk::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "InformationDesk '" << name << "' opened.\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "InformationDesk '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "InformationDesk '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "InformationDesk '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "InformationDesk '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "InformationDesk '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "InformationDesk '" << name << "' event fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating InformationDesk '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "InformationDesk '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "InformationDesk '" << name << "' received a notice.\n";
            break;
    }
}

EventComponent* InformationDesk::get(std::string name) {
    if (this->name == name) return this;
    else return nullptr;
}
