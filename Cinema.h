#ifndef CINEMA_H
#define CINEMA_H

#include "EventComponent.h"
#include <vector>

/**
 * @brief Composite-pattern Composite: a multi-screen indoor cinema
 * building. Owns its children.
 */
class Cinema : public EventComponent {
private:
    std::vector<EventComponent*> components;

public:
    explicit Cinema(const std::string& name);
    ~Cinema() override;

    bool add(EventComponent* component) override;
    bool remove(EventComponent* component) override;
    EventComponent* get(const std::string& name) override;
    void printResources() const override;
};

#endif // CINEMA_H
