#ifndef THEATRE_H
#define THEATRE_H

#include "EventComponent.h"
#include <vector>

/**
 * @brief Composite-pattern Composite: a theatre/hall used for special
 * events such as award ceremonies. Owns its children.
 */
class Theatre : public EventComponent {
private:
    std::vector<EventComponent*> components;

public:
    explicit Theatre(const std::string& name);
    ~Theatre() override;

    void add(EventComponent* component) override;
    void remove(EventComponent* component) override;
    EventComponent* get(const std::string& name) override;
    void printEventComponent(int level) const override;
    void update(NoticeType notice) override;
};

#endif
