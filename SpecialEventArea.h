#ifndef SPECIALEVENTAREA_H
#define SPECIALEVENTAREA_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: an area used for panels, red carpet,
 * award ceremonies, and similar special events.
 */
class SpecialEventArea : public EventComponent {
public:
    explicit SpecialEventArea(const std::string& name);
    void printEventComponent() const override;
    void update(NoticeType notice) override;
};

#endif
