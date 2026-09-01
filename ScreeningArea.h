#ifndef SCREENINGAREA_H
#define SCREENINGAREA_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a room/area where a film is screened.
 */
class ScreeningArea : public EventComponent {
public:
    explicit ScreeningArea(const std::string& name);
    void printEventComponent(int level) const override;
    void update(NoticeType notice) override;
    EventComponent* get(std::string name); 
};

#endif
