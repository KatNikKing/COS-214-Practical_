#ifndef DATETIME_H
#define DATETIME_H

/**
 * @brief Simple value type representing a calendar date and time.
 *
 * Deliberately lightweight for the preliminary stage. Operator overloads
 * are stubbed and should be fleshed out once real scheduling logic
 * (comparisons, overlap checks) is implemented.
 */
class DateTime {
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    DateTime();
    DateTime(int year, int month, int day, int hour, int minute);

    bool operator<(const DateTime& other) const;
    bool operator>(const DateTime& other) const;
    bool operator<=(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
    bool operator==(const DateTime& other) const;
    bool operator!=(const DateTime& other) const;
};

#endif // DATETIME_H
