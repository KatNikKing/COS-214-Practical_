#include "SpecialEventArea.h"
#include <iostream>

SpecialEventArea::SpecialEventArea(const std::string& name) : EventComponent(name) {}

void SpecialEventArea::printResources() const {
    std::cout << "SpecialEventArea: " << name << "\n";
}
