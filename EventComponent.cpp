#include "EventComponent.h"

EventComponent::EventComponent(const std::string& name)
    : name(name), capacity(0), status(ResourceStatus::CLOSED) {}

EventComponent::~EventComponent() {}

std::string EventComponent::getName() const {
    return name;
}

int EventComponent::getCapacity() const {
    return capacity;
}

ResourceStatus EventComponent::getStatus() const {
    return status;
}

void EventComponent::setCapacity(int capacity) {
    this->capacity = capacity;
}

void EventComponent::setStatus(ResourceStatus status) {
    this->status = status;
}

void EventComponent::add(EventComponent* component) {}

void EventComponent::remove(EventComponent* component) {}

EventComponent* EventComponent::get(const std::string& name) {
    return nullptr;
}
