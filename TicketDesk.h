#ifndef TICKETDESK_H
#define TICKETDESK_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a ticket sales/collection point.
 */
class TicketDesk : public EventComponent {
public:
    explicit TicketDesk(const std::string& name);
    void printResources() const override;
};

#endif // TICKETDESK_H
