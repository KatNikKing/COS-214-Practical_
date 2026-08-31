#ifndef SPECIALEVENT_H
#define SPECIALEVENT_H

#include "Event.h"
#include "SpecialEventType.h"
#include <string>

/**
 * @brief Concrete Event: a non-screening event such as a panel, award
 * ceremony, red carpet walk, or workshop.
 */
class SpecialEvent : public Event {
private:
    SpecialEventType type;
    std::string host;

public:
    SpecialEvent(const std::string& name, const std::string& description,
                 SpecialEventType type, const std::string& host);
    ~SpecialEvent() override;

    void update(NoticeType notice) override;
};

#endif
