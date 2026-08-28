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

int main() {
    // --- Build a sample Composite resource tree (>=3 levels below root) ---
    Zone* mainZone = new Zone("Main Zone");                 // level 1 (root)
    Cinema* cinemaA = new Cinema("Cinema A");                // level 2
    ScreeningArea* screen1 = new ScreeningArea("Screen 1");  // level 3
    TicketDesk* ticketDesk = new TicketDesk("Main Ticket Desk");
    cinemaA->add(screen1);
    cinemaA->add(ticketDesk);

    OutdoorVenue* lawn = new OutdoorVenue("Riverside Lawn"); // level 2
    FoodArea* foodArea = new FoodArea("Food Court");         // level 3
    lawn->add(foodArea);

    Theatre* theatre = new Theatre("Grand Theatre");         // level 2
    SpecialEventArea* redCarpetArea = new SpecialEventArea("Red Carpet Walk"); // level 3
    InformationDesk* infoDesk = new InformationDesk("Info Desk");
    theatre->add(redCarpetArea);
    theatre->add(infoDesk);

    mainZone->add(cinemaA);
    mainZone->add(lawn);
    mainZone->add(theatre);

    // --- Coordinator ---
    FilmFestival festival(mainZone);

    // --- Events, wired as Observer (Subject/Observer via Event::attach) ---
    FilmShowing* showing = new FilmShowing(
        "Opening Night Screening", "Festival opener",
        {Genre::DRAMA}, "A. Director");
    SpecialEvent* panel = new SpecialEvent(
        "Director Q&A", "Post-screening panel",
        SpecialEventType::DIRECTOR_PANEL, "A. Director");

    showing->attach(panel); // panel depends on the showing's schedule

    festival.scheduleEvent(showing);
    festival.scheduleEvent(panel);

    std::cout << "--- Resources ---\n";
    festival.printResources();

    std::cout << "\n--- Events ---\n";
    festival.printEvents();

    std::cout << "\n--- Running festival ---\n";
    festival.start();

    // Root of the Composite tree is owned by `festival`? -- NO: in this
    // skeleton `resources` is aggregated, not owned (see FilmFestival
    // dtor). Clean it up here explicitly for now.
    delete mainZone;

    return 0;
}
