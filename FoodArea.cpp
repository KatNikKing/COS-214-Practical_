#include "FoodArea.h"
#include <iostream>

FoodArea::FoodArea(const std::string& name) : EventComponent(name) {}

void FoodArea::printResources() const {
    std::cout << "FoodArea: " << name << "\n";
}
