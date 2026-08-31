#include "Theatre.h"
#include <algorithm>
#include <iostream>

Theatre::Theatre(const std::string& name) : EventComponent(name) {}

Theatre::~Theatre() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

bool Theatre::add(EventComponent* component) {
    if (component == nullptr) return false;
    components.push_back(component);
    return true;
}

bool Theatre::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return false;
    components.erase(it);
    return true;
}

EventComponent* Theatre::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }
    return nullptr;
}

void Theatre::printEventComponent() const {
    std::cout << "Theatre: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent();
    }
}

void Theatre::update(NoticeType notice) {
    if (notice == NoticeType::EVACUATE) {
        setStatus(ResourceStatus::CLOSED);
        std::cout << "Theatre " << name << " closing for evacuation.\n";
    }
    for (EventComponent* c : components) {
        c->update(notice);
    }
}
