#include "InformationDesk.h"
#include <iostream>

InformationDesk::InformationDesk(const std::string& name) : EventComponent(name) {}

void InformationDesk::printResources() const {
    std::cout << "InformationDesk: " << name << "\n";
}
