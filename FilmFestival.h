#ifndef FILMFESTIVAL_H
#define FILMFESTIVAL_H

#include <vector>
#include "Event.h"
#include "NoticeType.h"

/**
 * @brief Top-level coordinator (EventControl). Owns the list of Events.
 */
class FilmFestival {
private:
    std::vector<Event*> events;

public:
    FilmFestival();
    ~FilmFestival();

    /**
     * @brief Send a notice to a specific event.
     *
     * The event reacts (via its own update()) and, via its own notify(),
     * cascades the notice to any attached dependants.
     *
     * @param event Event to notify. Must not be nullptr.
     * @param notice The notice being sent.
     */
    void sendNotice(Event* event, NoticeType notice);

    EventComponent* getComponent(std::string name);

    /**
     * @brief Register a new event with the festival.
     * @param event Event to add. FilmFestival takes ownership.
     */
    void addEvent(Event* event);

    /**
     * @brief Remove an event from the festival.
     *
     * NOTE: the class diagram shows this with no parameter, which has no
     * sensible semantics for a vector of events -- confirm with your
     * team whether this should take an Event* or a name, or whether it
     * is meant to remove e.g. "the most recently added" event. Taking
     * an Event* here as the most defensible reading; adjust the
     * signature (and this comment) once your team decides.
     *
     * @param event Event to remove and destroy. Must be registered.
     */
    void removeEvent(Event* event);
    void printEvents() const;

    /**
     * @brief Start the festival.
     *
     * NOTE: Event has no start()/begin() operation in the current
     * design (it was removed from an earlier version of the diagram),
     * so this currently just transitions every event's EventStatus to
     * IN_PROGRESS. Revisit once your team decides what "starting" an
     * Event actually does.
     */
    void start();
};

#endif 
