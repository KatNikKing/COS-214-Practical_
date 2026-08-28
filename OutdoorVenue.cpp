#include "OutdoorVenue.h"
#include <algorithm>
#include <iostream>

OutdoorVenue::OutdoorVenue(const std::string& name) : EventComponent(name) {}

OutdoorVenue::~OutdoorVenue() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

bool OutdoorVenue::add(EventComponent* component) {
    if (component == nullptr) return false;
    components.push_back(component);
    return true;
}

bool OutdoorVenue::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return false;
    components.erase(it);
    return true;
}

EventComponent* OutdoorVenue::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }
    return nullptr;
}

void OutdoorVenue::printResources() const {
    std::cout << "OutdoorVenue: " << name << "\n";
    for (EventComponent* c : components) {
        c->printResources();
    }
}
