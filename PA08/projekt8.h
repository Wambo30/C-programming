/***  HEADER für die 8. Projektaufgabe  ***/

#include "Bruch.h"          // für Klasse Bruch

// Dimension des linearen Gleichungssystems
extern size_t Dim;

/***  in MAIN.CPP  ***/

// gib das lineare Gleichungssystem auf cout aus
void gibAusLGS ( Bruch* const matrix[], Bruch const rechteSeite[] ) ;


/***  in GAUSS.CPP  ***/

// löse das lineare Gleichungssystem
// gib neuen Vektor der Lösungen zurück
// oder NULL, wenn es keine Lösung gibt
Bruch* loeseLGS(Bruch* matrix[], Bruch rechteSeite[]);
