#include "FoodArea.h"
#include <iostream>

FoodArea::FoodArea(const std::string& name) : EventComponent(name) {}

void FoodArea::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "FoodArea: " << name << "\n";
}

void FoodArea::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "FoodArea '" << name << "' opened.\n";
            setStatus(ResourceStatus::OPEN);
            break;
        case NoticeType::CLOSE:
            std::cout << "FoodArea '" << name << "' closed.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::PAUSE:
            std::cout << "FoodArea '" << name << "' event paused.\n";
            break;
        case NoticeType::RESUME:
            std::cout << "FoodArea '" << name << "' event resumed.\n";
            break;
        case NoticeType::CANCEL:
            std::cout << "FoodArea '" << name << "' event cancelled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "FoodArea '" << name << "' event rescheduled.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "FoodArea '" << name << "' event fully booked.\n";
            setStatus(ResourceStatus::FULL);
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating FoodArea '" << name << "'.\n";
            setStatus(ResourceStatus::CLOSED);
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "FoodArea '" << name << "' received weather alert.\n";
            break;
        default:
            std::cout << "FoodArea '" << name << "' received a notice.\n";
            break;
    }
}

EventComponent* FoodArea::get(std::string name) {
    if (this->name == name) return this;
    else return nullptr;
}
