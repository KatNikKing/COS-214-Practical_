#include "EventComponent.h"

EventComponent::EventComponent(const std::string& name)
    : name(name), capacity(0), status(false) {}

EventComponent::~EventComponent() {}

std::string EventComponent::getName() const {
    return name;
}

int EventComponent::getCapacity() const {
    return capacity;
}

bool EventComponent::getStatus() const {
    return status;
}

void EventComponent::setCapacity(int capacity) {
    this->capacity = capacity;
}

void EventComponent::setStatus(bool status) {
    this->status = status;
}

// Default Leaf behaviour: leaves don't have children.
bool EventComponent::add(EventComponent* component) {
    return false;
}

bool EventComponent::remove(EventComponent* component) {
    return false;
}

EventComponent* EventComponent::get(const std::string& name) {
    return nullptr;
}
