#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

/**
 * @brief Composite-pattern Component. Represents anything that can hold
 * or be a physical/operational resource in the festival (a whole venue,
 * a zone, or a single desk/area).
 *
 * Leaves (ScreeningArea, TicketDesk, InformationDesk, FoodArea,
 * SpecialEventArea) override the printResources() hook only.
 * Composites (Zone, OutdoorVenue, Cinema, Theatre) additionally own and
 * manage children via add()/remove()/get().
 */
class EventComponent {
protected:
    std::string name;
    int capacity;
    bool status;

public:
    explicit EventComponent(const std::string& name);
    virtual ~EventComponent();

    virtual void printResources() const = 0;

    std::string getName() const;
    int getCapacity() const;
    bool getStatus() const;
    void setCapacity(int capacity);
    void setStatus(bool status);

    // Composite-only operations. Default (Leaf) behaviour is a no-op /
    // failure; Composites override these meaningfully.
    virtual bool add(EventComponent* component);
    virtual bool remove(EventComponent* component);
    virtual EventComponent* get(const std::string& name);
};

#endif // EVENTCOMPONENT_H
