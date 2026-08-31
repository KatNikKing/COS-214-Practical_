#include "Cinema.h"
#include <algorithm>
#include <iostream>

Cinema::Cinema(const std::string& name) : EventComponent(name) {}

Cinema::~Cinema() {
    for (EventComponent* c : components) {
        delete c;
    }
    components.clear();
}

bool Cinema::add(EventComponent* component) {
    if (component == nullptr) return false;
    components.push_back(component);
    return true;
}

bool Cinema::remove(EventComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it == components.end()) return false;
    components.erase(it);
    return true;
}

EventComponent* Cinema::get(const std::string& name) {
    for (EventComponent* c : components) {
        if (c->getName() == name) return c;
    }
    return nullptr;
}

void Cinema::printEventComponent() const {
    std::cout << "Cinema: " << name << "\n";
    for (EventComponent* c : components) {
        c->printEventComponent();
    }
}

void Cinema::update(NoticeType notice) {
    if (notice == NoticeType::EVACUATE) {
        setStatus(ResourceStatus::CLOSED);
        std::cout << "Cinema " << name << " closing for evacuation.\n";
    }
    for (EventComponent* c : components) {
        c->update(notice);
    }
}
