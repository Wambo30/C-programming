/**
 * Prog1b WS2017/18
 * 5. Projekt: Zeichenstatistik einer Datei
 */

#include "projekt5.h"


// max. Länge von Dateinamen (Annahme!)
int const MAX_DATEI = 60 ;


int main ()
{
/***  lese Input-Parameter ein  ***/
	
	char dateiName[ MAX_DATEI ] ;

	cout << "Name der Inputdatei: " ;
	cin >> dateiName ;
	cout << endl ;

/***  rufe eigentliche Aufgabe auf  ***/

	int fehlerNr = statistik( dateiName ) ;

	if ( fehlerNr != ALLES_OK )
		cerr << "Fehler aufgetreten: " << FEHLER[ fehlerNr ] << endl ;
	else
		cout << FEHLER[ fehlerNr ] << endl ;

// Extra-Halt für doppelklickbares Programm.
// Kann bei Start mit Visual Studio wegfallen.
char halt ;
cin >> halt ;

	return fehlerNr ;

}  // main()