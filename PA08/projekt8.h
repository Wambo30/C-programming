/***  HEADER f�r die 8. Projektaufgabe  ***/

#include "Bruch.h"          // f�r Klasse Bruch

// Dimension des linearen Gleichungssystems
extern size_t Dim;

/***  in MAIN.CPP  ***/

// gib das lineare Gleichungssystem auf cout aus
void gibAusLGS ( Bruch* const matrix[], Bruch const rechteSeite[] ) ;


/***  in GAUSS.CPP  ***/

// l�se das lineare Gleichungssystem
// gib neuen Vektor der L�sungen zur�ck
// oder NULL, wenn es keine L�sung gibt
Bruch* loeseLGS(Bruch* matrix[], Bruch rechteSeite[]);
