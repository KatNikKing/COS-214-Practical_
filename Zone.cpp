#include "Zone.h"
#include <algorithm>
#include <iostream>

Zone::Zone(const std::string& name) : EventComponent(name) {}

Zone::~Zone() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

bool Zone::add(EventComponent* component) {
    if (component == nullptr) return false;
    components.push_back(component);
    return true;
}

bool Zone::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return false;
    components.erase(it);
    return true;
}

EventComponent* Zone::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }
    return nullptr;
}

void Zone::printEventComponent() const {
    std::cout << "Zone: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent();
    }
}

void Zone::update(NoticeType notice) {
    for (EventComponent* c : components) {
        c->update(notice);
    }
}
