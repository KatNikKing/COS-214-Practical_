#ifndef FILMSHOWING_H
#define FILMSHOWING_H

#include "Event.h"
#include "Genre.h"
#include <vector>
#include <string>

/**
 * @brief Concrete Event: a scheduled screening of one or more films.
 */
class FilmShowing : public Event {
private:
    std::vector<Genre> genre;
    std::vector<std::string> director;

public:
    FilmShowing(const std::string& name, const std::string& description,
                std::vector<Genre> genres, std::string director);
    ~FilmShowing() override;

    void start_event() override;
    void update(DateTime start, DateTime end) override;
};

#endif // FILMSHOWING_H
