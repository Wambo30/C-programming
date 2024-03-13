/**
 * Aufgabe 22.6
 * Verarbeitung mehrdimensionaler Punkte aus Datei
 */

#include <iostream>
#include <fstream>       // für ifstream
#include <iomanip>       // für setw(), setprecision(), left, right, fixed
int dim, nPunkte;
using namespace std ;


// euklidischer Abstand zweier Punkte mit Dimension dim
double abstand ( double const punkt1[], double const punkt2[], int dim )
{

	return 0 ;		// TO DO! Compiliert erstmal

}  // abstand()


// gib eine Zeile der Ausgabe aus (fertig)
void gibAus ( double const punkt[], int dim, double abstand )
{
	cout << fixed ;
	for ( int j = 0 ;  j < dim ;  ++j )
		cout << setw( 6 ) << setprecision( 0 ) << punkt[ j ] ;
	cout << setw( 11 ) << setprecision( 3 ) << abstand << endl ;
}



/***  Hauptprogramm  *********************************************/

int main ( int narg, char* argv[] )
{

// TO DO: gebe Hilfetext (Usage) aus, wenn kein Argument gegeben wurde

/***  lese Datei  ***/

	// öffne Datei
	//int dim, nPunkte;
	char const* dateiName = "punkte20_3.txt<" ;	// TODO: woher kommt der Dateiname?
	ifstream fin( dateiName ) ;

	if ( ! fin )
	{
		cerr << "kann Datei " << dateiName << " nicht oeffnen!" << endl ;
		return -1 ;		// Fehler aufgetreten
	}

	// lese die Punkte als Koordinatenmatrix aus Datei ein,
	// die Matrix hat nPunkte Zeilen und dim Spalten
	//int      nPunkte, dim ;
	double** punkte ;

// TO DO: lese nPunkte und dim aus der Datei ein,
// alloziere damit die Matrix punkte[][] dynamisch,
// lese die Punktdaten aus der Datei ein

	fin.close() ;

/***  behandle Referenzpunkt  ***/

	// lese Index des Referenzpunkts ein
	
	int i0 ;
	cout << "Index i < " << nPunkte << " : " ;
	cin >> i0 ;

// TO DO: suche den nächsten Nachbarn zu punkte[ i0 ]

	// gebe Ergebnisse aus
	cout << left << setw( dim * 6 + 3 ) << "   Punkte"
		 << right << setw( 11 ) << "Entfernung" << endl ;

// TO DO: gebe die beiden Punkte aus

// TO DO: lösche die dynamisch allozierten Speicherbereiche

	return 0 ;

}  // main()