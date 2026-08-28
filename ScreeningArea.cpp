#include "ScreeningArea.h"
#include <iostream>

ScreeningArea::ScreeningArea(const std::string& name) : EventComponent(name) {}

void ScreeningArea::printResources() const {
    std::cout << "ScreeningArea: " << name << " (capacity " << capacity << ")\n";
}
