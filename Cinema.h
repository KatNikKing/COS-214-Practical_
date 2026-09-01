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

    void add(EventComponent* component) override;
    void remove(EventComponent* component) override;
    EventComponent* get(const std::string& name) override;
    void printEventComponent(int level) const override;
    void update(NoticeType notice) override;
};

#endif 
