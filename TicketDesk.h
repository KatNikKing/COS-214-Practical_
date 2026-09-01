#ifndef TICKETDESK_H
#define TICKETDESK_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a ticket sales/collection point.
 */
class TicketDesk : public EventComponent {
public:
    explicit TicketDesk(const std::string& name);
    void printEventComponent(int level) const override;
    void update(NoticeType notice) override;
    EventComponent* get(std::string name); 
};

#endif
