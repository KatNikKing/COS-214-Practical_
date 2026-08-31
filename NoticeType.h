#ifndef NOTICETYPE_H
#define NOTICETYPE_H

/**
 * @brief Notices/orders that can be broadcast through the festival.
 * Covers ordinary operational changes (OPEN/CLOSE/SCHEDULE_CHANGE),
 * capacity-related changes (CAPACITY_ALERT) and safety-related changes
 * (WEATHER_ALERT/EVACUATE), per the practical's minimum requirements.
 */
enum class NoticeType {
    OPEN,
    CLOSE,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    PAUSE,
    RESUME,
    CANCEL,
    EVACUATE
};

#endif 
