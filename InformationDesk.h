#ifndef INFORMATIONDESK_H
#define INFORMATIONDESK_H

#include "EventComponent.h"

/**
 * @brief Composite-pattern Leaf: a guest information/help point.
 */
class InformationDesk : public EventComponent {
public:
    explicit InformationDesk(const std::string& name);
    void printResources() const override;
};

#endif // INFORMATIONDESK_H
