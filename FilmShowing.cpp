#include "FilmShowing.h"
#include <iostream>

FilmShowing::FilmShowing(const std::string& name, const std::string& description,
                          std::vector<Genre> genres, std::string director)
    : Event(name, description), genre(genres) {
    this->director.push_back(director);
}

FilmShowing::~FilmShowing() {}

void FilmShowing::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::PAUSE:
            std::cout << "FilmShowing '" << name << "' pausing screening.\n";
            setEventStatus(EventStatus::PAUSED);
            break;
        case NoticeType::RESUME:
            std::cout << "FilmShowing '" << name << "' resuming screening.\n";
            setEventStatus(EventStatus::IN_PROGRESS);
            break;
        case NoticeType::CANCEL:
            std::cout << "FilmShowing '" << name << "' cancelled.\n";
            setEventStatus(EventStatus::CANCELLED);
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "FilmShowing '" << name << "' rescheduled.\n";
            setEventStatus(EventStatus::RESCHEDULED);
            break;
        default:
            std::cout << "FilmShowing '" << name << "' received a notice.\n";
            break;
    }
    currentNotice = notice;
    notify();
}
