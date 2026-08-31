#include "FilmFestival.h"
#include <algorithm>
#include <iostream>

FilmFestival::FilmFestival() {}

FilmFestival::~FilmFestival() {
    for (Event* e : events) {
        delete e;
    }
}

void FilmFestival::sendNotice(Event* event, NoticeType notice) {
    if (event != nullptr) {
        event->update(notice);
    }
}

void FilmFestival::addEvent(Event* event) {
    if (event != nullptr) {
        events.push_back(event);
    }
}

void FilmFestival::removeEvent(Event* event) {
    auto it = std::find(events.begin(), events.end(), event);
    if (it == events.end()) return;
    delete *it;
    events.erase(it);
}

void FilmFestival::printEvents() const {
    for (Event* e : events) {
        std::cout << "Event: " << e->getName()
                   << " (status " << static_cast<int>(e->getEventStatus()) << ")\n";
    }
}

void FilmFestival::start() {
    for (Event* e : events) {
        e->setEventStatus(EventStatus::IN_PROGRESS);
    }
}
