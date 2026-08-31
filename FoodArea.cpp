#include "FoodArea.h"
#include <iostream>

FoodArea::FoodArea(const std::string& name) : EventComponent(name) {}

void FoodArea::printEventComponent() const {
    std::cout << "FoodArea: " << name << "\n";
}

void FoodArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::WEATHER_ALERT:
            setStatus(ResourceStatus::SUSPENDED);
            std::cout << "FoodArea " << name << " suspending service.\n";
            break;
        case NoticeType::EVACUATE:
            setStatus(ResourceStatus::CLOSED);
            std::cout << "FoodArea " << name << " closing for evacuation.\n";
            break;
        case NoticeType::RESUME:
            setStatus(ResourceStatus::OPEN);
            std::cout << "FoodArea " << name << " resuming service.\n";
            break;
        default:
            break;
    }
}
