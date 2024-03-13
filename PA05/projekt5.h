/**
* Prog1b WS2017/18
* 5. Projekt: Zeichenstatistik einer Datei
*/

#include <iostream>
using namespace std ;

// globale Konstante Spalten für die Tabelle der Statistik 
int const NSPALTEN = 4;


// Fehlercodes
int const ALLES_OK     = 0 ;        // alles in Ordnung
int const KEINE_DATEI  = 1 ;        // Datei konnte nicht geöffnet werden
int const DATEI_LEER   = 2 ;        // Datei enthält keine ASCII-Zeichen
int const SONST_FEHLER = 3 ;        // sonstiger Fehler ist aufgetreten

// sprechende Fehlerbeschreibungen
char const FEHLER[ 4 ][ 40 ] = { "alles OK",
							     "Datei konnte nicht geoeffnet werden",
								 "Datei enthaelt keine ASCII-Zeichen",
								 "sonstiger Fehler" } ;
							 

// berechne Zeichenstatistik der Datei
// gib Fehlercode zurück
int statistik( char const dateiName[] ) ;
