#include "TicketDesk.h"
#include <iostream>

TicketDesk::TicketDesk(const std::string& name) : EventComponent(name) {}

void TicketDesk::printResources() const {
    std::cout << "TicketDesk: " << name << "\n";
}
