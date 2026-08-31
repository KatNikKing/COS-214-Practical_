#include "FilmShowing.h"
#include "EventComponent.h"
#include <iostream>

FilmShowing::FilmShowing(const std::string& name, const std::string& description,
                          std::vector<Genre> genres, std::vector<std::string> directors)
    : Event(name, description), genre(genres), directors(directors) {}

FilmShowing::~FilmShowing() {}

void FilmShowing::update(NoticeType notice) {
    switch (notice) {
        case NoticeType::OPEN:
            std::cout << "FilmShowing '" << name << "' started. Description: " << description << "\n";
            setEventStatus(EventStatus::IN_PROGRESS);
            break;
        case NoticeType::CLOSE:
            std::cout << "FilmShowing '" << name << "' ended.\n";
            setEventStatus(EventStatus::COMPLETED);
            break;
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
        case NoticeType::CAPACITY_ALERT:
            std::cout << "FilmShowing '" << name << "' fully booked.\n";
            break;
        case NoticeType::EVACUATE:
            std::cout << "Evacuating FilmShowing '" << name << "'.\n";
            setEventStatus(EventStatus::POSTPONED);
            break;
        default:
            std::cout << "FilmShowing '" << name << "' received a notice.\n";
            break;
    }
    currentNotice = notice;
    notify();
}

void FilmShowing::printEventComponent(int level) const {
    std::string tabs = std::string(level, '\t');
    std::cout << tabs << "FilmShowing: " << name << "\n";
    for (EventComponent* c : resources) {
        c->printEventComponent(level + 1);
    }
}
