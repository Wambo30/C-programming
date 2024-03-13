#include <iostream>
#include "Ampel.h"
using namespace std;

int main()
{

		Ampel ampel;                // neues Ampel-Objekt
		ampel.setzeRot();           // initialisiere ampel
		do
		{
			cout << "ampel hat Zustand ";

			//ampel.gibAus(cout) --> alter code
			ampel << (cout);   // gib ampel auf cout aus
			cout << endl;
			//...  // hier ggf. weitere Aktionen, die Lichter oder Phasen abfragen
			++ampel;	//nächstephase geschaltet mit ++ operator

			//ampel.naechstePhase();  // schalte ampel weiter --> alter code ohne operator
		} while (!ampel.istRot());	// wenn ampel rot dann while schleife abgebrochen
		return 0;
	}  // main()






