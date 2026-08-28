#ifndef SCREENINGAREA_H
#define SCREENINGAREA_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a room/area where a film is screened.
 */
class ScreeningArea : public EventComponent {
public:
    explicit ScreeningArea(const std::string& name);
    void printResources() const override;
};

#endif // SCREENINGAREA_H
