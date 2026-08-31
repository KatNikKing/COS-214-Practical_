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
    /*  
    The main needs to create every kind of composite 
    (FilmShowing, SpecialEvent, Zone, OutdoorVenue, Cinema, Theatre)
    with every kind of leaf
    (ScreeningArea, TicketDesk, InformationDesk, FoodArea, SpecialEventArea).
    Events are top-level composites, so Venues (Zone, OutdoorVenue, Cinema, Theatre) cannot contain them.
    Build the trees first, and call building functions like add and remove. 
    Add all events to FilmFestival.
    Send all kinds of notices to each top-level event through FilmFestival to show ripple effects. 
    Calling printEvents() in FilmFestival calls all printEventComponent() in the tree.
    You can also simply call getComponent() in FilmFestival to search the whole tree. 
    Remember to attach some events to each other as well.
    If necessary for coverage, you can add trivial uses of unused functions 
    like some of the getters and setters in EventComponent.
    */

    Zone* mainZone = new Zone("Main Zone");                 
    Cinema* cinemaA = new Cinema("Cinema A");                
    ScreeningArea* screen1 = new ScreeningArea("Screen 1");  
    TicketDesk* ticketDesk = new TicketDesk("Main Ticket Desk");
    cinemaA->add(screen1);
    cinemaA->add(ticketDesk);

    OutdoorVenue* lawn = new OutdoorVenue("Riverside Lawn"); 
    FoodArea* foodArea = new FoodArea("Food Court");        
    lawn->add(foodArea);

    Theatre* theatre = new Theatre("Grand Theatre");         
    SpecialEventArea* redCarpetArea = new SpecialEventArea("Red Carpet Walk"); 
    InformationDesk* infoDesk = new InformationDesk("Info Desk");
    theatre->add(redCarpetArea);
    theatre->add(infoDesk);

    mainZone->add(cinemaA);
    mainZone->add(lawn);
    mainZone->add(theatre);
    FilmFestival festival;
    FilmShowing* showing = new FilmShowing(
        "Opening Night Screening", "Festival opener",
        {Genre::DRAMA}, {"A. Director"});
    SpecialEvent* panel = new SpecialEvent(
        "Director Q&A", "Post-screening panel",
        SpecialEventType::DIRECTOR_PANEL, "A. Director");

    showing->attach(panel);
    showing->add(screen1);
    showing->add(ticketDesk);

    festival.addEvent(showing);
    festival.addEvent(panel);

    std::cout << "--- Resources ---\n";
    mainZone->printEventComponent(0);

    std::cout << "\n--- Sending WEATHER_ALERT through the resource tree ---\n";
    mainZone->update(NoticeType::WEATHER_ALERT);

    std::cout << "\n--- Sending PAUSE notice to the showing (cascades to its panel) ---\n";
    festival.sendNotice(showing, NoticeType::PAUSE);

    std::cout << "\n--- Detaching panel, then resuming the showing ---\n";
    showing->detach(panel);
    festival.sendNotice(showing, NoticeType::RESUME);

    std::cout << "\n--- Starting the festival ---\n";
    festival.start();
    festival.printEvents();

    std::cout << "\n--- Removing the panel event ---\n";
    festival.removeEvent(panel); 
    festival.printEvents();

    delete mainZone;

    return 0;
}
