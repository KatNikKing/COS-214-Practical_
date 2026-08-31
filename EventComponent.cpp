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

bool EventComponent::add(EventComponent* component) {
    return false;
}

bool EventComponent::remove(EventComponent* component) {
    return false;
}

EventComponent* EventComponent::get(const std::string& name) {
    return nullptr;
}
