#ifndef ZONE_H
#define ZONE_H

#include "EventComponent.h"
#include <vector>

/**
 * @brief Composite-pattern Composite: a general grouping area that can
 * contain any mix of Leaves or further Composites.
 *
 * Owns its children: destroying a Zone destroys everything beneath it.
 */
class Zone : public EventComponent {
private:
    std::vector<EventComponent*> components;

public:
    explicit Zone(const std::string& name);
    ~Zone() override;

    bool add(EventComponent* component) override;
    bool remove(EventComponent* component) override;
    EventComponent* get(const std::string& name) override;
    void printEventComponent() const override;
    void update(NoticeType notice) override;
};

#endif
