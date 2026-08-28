#include "FilmShowing.h"
#include <iostream>

FilmShowing::FilmShowing(const std::string& name, const std::string& description,
                          std::vector<Genre> genres, std::string director)
    : Event(name, description), genre(genres) {
    this->director.push_back(director);
}

FilmShowing::~FilmShowing() {}

void FilmShowing::start_event() {
    std::cout << "FilmShowing '" << name << "' is starting.\n";
    notify();
}

void FilmShowing::update(DateTime start, DateTime end) {
    // TODO: react to a dependency changing, e.g. shift this showing's slot
    setDateTime(start, end);
}
