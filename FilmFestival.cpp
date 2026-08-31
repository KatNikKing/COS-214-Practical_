#include "FilmFestival.h"
#include "EventComponent.h"
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

EventComponent* FilmFestival::getComponent(std::string name) {
    for (Event* e : events) {
        if (e->getName() == name) return e;
    }

    for (Event* e : events) {
        return e->get(name);
    }
}

void FilmFestival::printEvents() const {
    for (Event* e : events) {
        e->printEventComponent(0);
    }
}

void FilmFestival::start() {
    for (Event* e : events) {
        sendNotice(e, NoticeType::OPEN);
    }
}
