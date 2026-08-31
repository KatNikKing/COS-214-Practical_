#ifndef OUTDOORVENUE_H
#define OUTDOORVENUE_H

#include "EventComponent.h"
#include <vector>

/**
 * @brief Composite-pattern Composite: an open-air venue (e.g. an outdoor
 * screening lawn). Owns its children.
 */
class OutdoorVenue : public EventComponent {
private:
    std::vector<EventComponent*> components;

public:
    explicit OutdoorVenue(const std::string& name);
    ~OutdoorVenue() override;

    bool add(EventComponent* component) override;
    bool remove(EventComponent* component) override;
    EventComponent* get(const std::string& name) override;
    void printEventComponent() const override;
    void update(NoticeType notice) override;
};

#endif
