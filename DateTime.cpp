#include "DateTime.h"

DateTime::DateTime() : year(0), month(0), day(0), hour(0), minute(0) {}

DateTime::DateTime(int year, int month, int day, int hour, int minute)
    : year(year), month(month), day(day), hour(hour), minute(minute) {}

// TODO: replace with real comparisons (e.g. convert to a comparable total-minutes value)
bool DateTime::operator<(const DateTime& other) const {
    return false;
}

bool DateTime::operator>(const DateTime& other) const {
    return other < *this;
}

bool DateTime::operator<=(const DateTime& other) const {
    return !(other < *this);
}

bool DateTime::operator>=(const DateTime& other) const {
    return !(*this < other);
}

bool DateTime::operator==(const DateTime& other) const {
    return year == other.year && month == other.month && day == other.day &&
           hour == other.hour && minute == other.minute;
}

bool DateTime::operator!=(const DateTime& other) const {
    return !(*this == other);
}
