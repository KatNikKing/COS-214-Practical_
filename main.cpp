#include <iostream>
#include "FilmFestival.h"
#include "Zone.h"
#include "Cinema.h"
#include "Theatre.h"
#include "OutdoorVenue.h"
#include "ScreeningArea.h"
#include "TicketDesk.h"
#include "InformationDesk.h"
#include "FoodArea.h"
#include "SpecialEventArea.h"
#include "FilmShowing.h"
#include "SpecialEvent.h"
#include "Genre.h"
#include "SpecialEventType.h"
#include "NoticeType.h"

int main() { 
    Zone* mainZone = new Zone("Main Festival Zone");
    mainZone->setCapacity(5000);
    
    Cinema* cinemaA = new Cinema("Cinema A - IMAX");
    cinemaA->setCapacity(400);
    
    OutdoorVenue* lawn = new OutdoorVenue("Riverside Lawn");
    lawn->setCapacity(1000);
    
    Theatre* theatre = new Theatre("Grand Theatre");
    theatre->setCapacity(800);
    
    ScreeningArea* screen1 = new ScreeningArea("Screen 1 - Hall A");
    screen1->setCapacity(150);
    
    ScreeningArea* screen2 = new ScreeningArea("Screen 2 - Hall B");
    screen2->setCapacity(120);
    
    TicketDesk* ticketDesk = new TicketDesk("Main Ticket Desk");
    FoodArea* foodArea = new FoodArea("Gourmet Food Court");
    InformationDesk* infoDesk = new InformationDesk("Guest Information");
    SpecialEventArea* redCarpetArea = new SpecialEventArea("Red Carpet Walkway");
    
    mainZone->add(cinemaA);
    mainZone->add(lawn);
    mainZone->add(theatre);
    
    cinemaA->add(screen1);
    cinemaA->add(screen2);
    cinemaA->add(ticketDesk);
    
    lawn->add(foodArea);
    
    theatre->add(redCarpetArea);
    theatre->add(infoDesk);
    FilmShowing* showing = new FilmShowing(
        "Opening Night: The Premiere",
        "World premiere of the festival's most anticipated film",
        {Genre::DRAMA, Genre::THRILLER},
        {"Christopher Nolan"});
    showing->setEventStatus(EventStatus::SCHEDULED);
    
    SpecialEvent* panel = new SpecialEvent(
        "Director Q&A Panel",
        "Post-screening discussion with the director and cast",
        SpecialEventType::DIRECTOR_PANEL,
        "Christopher Nolan");
    
    SpecialEvent* awardCeremony = new SpecialEvent(
        "Award Ceremony",
        "Closing night awards presentation",
        SpecialEventType::AWARD_CEREMONY,
        "Festival Host");

    ScreeningArea* showingScreen = new ScreeningArea("Premiere Screen");
    showingScreen->setCapacity(200);
    TicketDesk* showingTickets = new TicketDesk("Premiere Ticket Desk");
    
    showing->add(showingScreen);
    showing->add(showingTickets);
    
    SpecialEventArea* panelArea = new SpecialEventArea("Panel Discussion Hall");
    panelArea->setCapacity(100);
    panel->add(panelArea);
    
    SpecialEventArea* ceremonyArea = new SpecialEventArea("Awards Hall");
    ceremonyArea->setCapacity(300);
    awardCeremony->add(ceremonyArea);

    showing->attach(panel);
    showing->attach(awardCeremony);
    FilmFestival festival;
    festival.addEvent(showing);
    festival.addEvent(panel);
    festival.addEvent(awardCeremony);

    std::cout << "COMPOSITE STRUCTURE (3+ levels of nesting)\n";
    std::cout << "Festival Layout:\n";
    mainZone->printEventComponent(0);
    
    std::cout << "\nEVENT STRUCTURE\n";
    festival.printEvents();

    std::cout << "\nCOMPOSITE SEARCH (get() functionality)\n";
    EventComponent* found = mainZone->get("Screen 1 - Hall A");
    if (found) {
        std::cout << "Found: " << found->getName() 
                  << " (Capacity: " << found->getCapacity() << ")\n";
    }
    
    found = mainZone->get("Main Ticket Desk");
    if (found) {
        std::cout << "Found: " << found->getName() << "\n";
    }

    std::cout << "\nNOTICE CASCADING THROUGH COMPOSITE TREE\n";
    std::cout << "Sending WEATHER_ALERT to Main Zone (cascades to all children):\n";
    mainZone->update(NoticeType::WEATHER_ALERT);
    
    std::cout << "\nSTATUS AFTER WEATHER ALERT\n";
    std::cout << "OutdoorVenue status: " << (lawn->getStatus() == ResourceStatus::CLOSED ? "CLOSED" : "OPEN") << "\n";
    std::cout << "Cinema status: " << (cinemaA->getStatus() == ResourceStatus::OPEN ? "OPEN" : "CLOSED") << "\n";

    std::cout << "\nOBSERVER PATTERN: CASCADING NOTIFICATION\n";
    std::cout << "Sending PAUSE to showing (cascades to panel and awardCeremony observers):\n";
    festival.sendNotice(showing, NoticeType::PAUSE);

    std::cout << "\nOBSERVER DETACHMENT\n";
    std::cout << "Detaching panel from showing...\n";
    showing->detach(panel);
    
    std::cout << "Sending RESUME to showing (panel no longer receives it):\n";
    festival.sendNotice(showing, NoticeType::RESUME);
    std::cout << "\nSENDING CAPACITY_ALERT\n";
    festival.sendNotice(showing, NoticeType::CAPACITY_ALERT);
    std::cout << "\nTESTING VARIOUS NOTICE TYPES\n";
    festival.sendNotice(awardCeremony, NoticeType::OPEN);
    festival.sendNotice(awardCeremony, NoticeType::SCHEDULE_CHANGE);
    festival.sendNotice(panel, NoticeType::EVACUATE);

    std::cout << "\nSTARTING FESTIVAL\n";
    festival.start();
    
    std::cout << "\nFESTIVAL STATE AFTER START\n";
    festival.printEvents();

    std::cout << "\nRUNTIME REORGANISATION\n";
    std::cout << "Moving 'Gourmet Food Court' from Riverside Lawn to Main Zone...\n";
    lawn->remove(foodArea);
    mainZone->add(foodArea);
    
    std::cout << "Updated structure:\n";
    mainZone->printEventComponent(0);

    std::cout << "\nREMOVING AN EVENT\n";
    std::cout << "Detaching awardCeremony from showing before removal...\n";
    showing->detach(awardCeremony);
    
    std::cout << "Removing Award Ceremony from festival...\n";
    festival.removeEvent(awardCeremony);
    
    std::cout << "\nFESTIVAL EVENTS AFTER REMOVAL\n";
    festival.printEvents();

    std::cout << "\nPOLYMORPHIC RESPONSES: SAME NOTICE, DIFFERENT BEHAVIOR\n";
    std::cout << "Sending CLOSE to showing (now only panel is attached):\n";
    festival.sendNotice(showing, NoticeType::CLOSE);
    
    std::cout << "Sending CLOSE to panel:\n";
    festival.sendNotice(panel, NoticeType::CLOSE);

    std::cout << "\nSTATUS QUERIES\n";
    std::cout << "Cinema A status: " 
              << (cinemaA->getStatus() == ResourceStatus::OPEN ? "OPEN" : 
                  cinemaA->getStatus() == ResourceStatus::CLOSED ? "CLOSED" : 
                  cinemaA->getStatus() == ResourceStatus::FULL ? "FULL" : "OTHER") << "\n";
    std::cout << "Showing event status: " 
              << (showing->getEventStatus() == EventStatus::IN_PROGRESS ? "IN_PROGRESS" :
                  showing->getEventStatus() == EventStatus::PAUSED ? "PAUSED" :
                  showing->getEventStatus() == EventStatus::COMPLETED ? "COMPLETED" :
                  showing->getEventStatus() == EventStatus::SCHEDULED ? "SCHEDULED" : "OTHER") << "\n";

    std::cout << "\nADDING NEW EVENT\n";
    SpecialEvent* workshop = new SpecialEvent(
        "Filmmaking Workshop",
        "Hands-on filmmaking workshop",
        SpecialEventType::WORKSHOP,
        "Industry Expert");
    workshop->setEventStatus(EventStatus::SCHEDULED);
    festival.addEvent(workshop);
    std::cout << "Added workshop event:\n";
    workshop->printEventComponent(0);

    std::cout << "\nCOMPOSITE REMOVAL\n";
    std::cout << "Removing 'Screen 2 - Hall B' from Cinema A...\n";
    cinemaA->remove(screen2);
    std::cout << "Cinema A now contains:\n";
    cinemaA->printEventComponent(1);

    std::cout << "\nCLEAN SHUTDOWN\n";
    std::cout << "Destroying mainZone (will cascade delete all contained resources)...\n";
    delete mainZone;
    std::cout << "Destroying festival (will delete remaining events)...\n";

    return 0;
}