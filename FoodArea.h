#ifndef FOODAREA_H
#define FOODAREA_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a food/vendor area.
 */
class FoodArea : public EventComponent {
public:
    explicit FoodArea(const std::string& name);
    void printEventComponent() const override;
    void update(NoticeType notice) override;
};

#endif
