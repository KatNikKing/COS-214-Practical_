#ifndef EVENTSTATUS_H
#define EVENTSTATUS_H

/**
 * @brief Lifecycle status of an Event.
 */
enum class EventStatus {
    SCHEDULED,
    RESCHEDULED,
    POSTPONED,
    CANCELLED,
    IN_PROGRESS,
    COMPLETED,
    PAUSED
};

#endif
