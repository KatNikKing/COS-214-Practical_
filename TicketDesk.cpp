#include "TicketDesk.h"
#include <iostream>

TicketDesk::TicketDesk(const std::string& name) : EventComponent(name) {}

void TicketDesk::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "TicketDesk: " << name << "\n";
}

void TicketDesk::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "TicketDesk '" << name << "' opened.\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "TicketDesk '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "TicketDesk '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "TicketDesk '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "TicketDesk '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "TicketDesk '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "TicketDesk '" << name << "' event fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating TicketDesk '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "TicketDesk '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "TicketDesk '" << name << "' received a notice.\n";
            break;
    }
}

EventComponent* TicketDesk::get(std::string name) {
    if (this->name == name) return this;
    else return nullptr;
}
