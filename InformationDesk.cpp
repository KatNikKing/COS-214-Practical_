#include "InformationDesk.h"
#include <iostream>

InformationDesk::InformationDesk(const std::string& name) : EventComponent(name) {}

void InformationDesk::printEventComponent() const {
    std::cout << "InformationDesk: " << name << "\n";
}

void InformationDesk::update(NoticeType notice) {
    if (notice == NoticeType::EVACUATE) {
        setStatus(ResourceStatus::CLOSED);
        std::cout << "InformationDesk " << name << " relocating to muster point.\n";
    } else {
        std::cout << "InformationDesk " << name << " remains staffed, relaying notice.\n";
    }
}
