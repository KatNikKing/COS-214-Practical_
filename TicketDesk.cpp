#include "TicketDesk.h"
#include <iostream>

TicketDesk::TicketDesk(const std::string& name) : EventComponent(name) {}

void TicketDesk::printEventComponent() const {
    std::cout << "TicketDesk: " << name << "\n";
}

void TicketDesk::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::CAPACITY_ALERT:
            setStatus(ResourceStatus::FULL);
            std::cout << "TicketDesk " << name << " stopping sales (capacity).\n";
            break;
        case NoticeType::EVACUATE:
            setStatus(ResourceStatus::CLOSED);
            std::cout << "TicketDesk " << name << " closing for evacuation.\n";
            break;
        default:
            break;
    }
}
