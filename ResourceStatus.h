#ifndef RESOURCESTATUS_H
#define RESOURCESTATUS_H

/**
 * @brief Operational status of an EventComponent (venue/area/desk).
 */
enum class ResourceStatus {
    OPEN,
    CLOSED,
    FULL,
    SUSPENDED,
    MAINTENANCE
};

#endif
