#include <iostream>
#include <iomanip>         // für setw()
#include <cstdlib>         // für atol()
//#include <cmath>
#include "projekt8.h"
// hi

using namespace std ;


// Dimension des linearen Gleichungssystems
size_t Dim ;


// gib das lineare Gleichungssystem auf cout aus
void gibAusLGS ( Bruch* const matrix[], Bruch const rechteSeite[] )
{
	for ( size_t i = 0 ;  i < Dim ;  ++i )
	{
		for ( size_t j = 0 ;  j < Dim ;  ++j )
			cout << " " << setw( 6 ) << matrix[ i ][ j ] ;
		cout << " |" << setw( 4 ) << rechteSeite[ i ] << endl ;
	}
	cout << endl ;

}  // gibAusLGS()


/**************************************************************************/

int main ( int narg, char* argv[] )
{
/***  gebe Usage aus  ***/

	if (     narg < 3             // zuwenig Argumente
		 ||  narg % 2 == 0 )      // eine y-Koordinate fehlt
	{
		cout << "usage: " << argv[ 0 ] << " x1 y1 [x2 y2 ...]"       << endl ;
		cout << "       x1, y1: ganzz. Koordinaten eines Punktes"    << endl ;
		cout << "       x2, y2, ...: Koordinaten weiterer Punkte"    << endl ;
		cout << "Bestimmt das durch die Punkte festgelegte Polynom." << endl ;

		return 0 ;
	}

/***  setze Parameter des LGS  ***/

	// setze Dimension des Vektorraums
	Dim = ( narg - 1 ) / 2 ;

	// erstelle Matrix und rechte Seite
	Bruch** matrix      = new Bruch*[ Dim ] ;
	Bruch*  rechteSeite = new Bruch [ Dim ] ;

	for ( size_t i = 0 ;  i < Dim ;  ++i )
	{
		Bruch x = atol( argv[ 2 * i + 1 ] ) ;
		Bruch y = atol( argv[ 2 * i + 2 ] ) ;

		// init. Matrix mit Potenzen von x
		matrix[ i ]      = new Bruch[ Dim ] ;
		matrix[ i ][ 0 ] = 1 ;
		for ( size_t j = 1 ;  j < Dim ;  ++j )
			matrix[ i ][ j ] = x * matrix[ i ][ j - 1 ] ;

		// init. rechte Seite mit Funktionswerten y
		rechteSeite[ i ] = y ;
	}

/***  gebe LGS zur Kontrolle aus  ***/

	cout << "das LGS lautet:" << endl ;
	gibAusLGS( matrix, rechteSeite ) ;

/***  berechne Lösung mit Gauß-Algorithmus,
	  gebe Ergebnispolynom aus               ***/

	Bruch* koeff = loeseLGS( matrix, rechteSeite ) ;

	// wurde Lösung gefunden?
	if ( koeff == nullptr )
		cout << "Es gibt keine Loesung!" << endl ;
	else
	{
		// gib Lösungsvektor aus
		cout << "finde Polynom:" << endl ;

		bool erster = true ;

		for ( size_t i = 0 ;  i < Dim ;  ++i )
			if (     ( i == 0  &&  erster )
				 ||  koeff[ i ] != 0 )
			{
				// gebe Koeffizient aus
				if ( erster )
					cout << koeff[ i ] ;
				else if ( koeff[ i ] >= 0 )
				{
					cout << " +" ;
					if ( koeff[ i ] != 1 )
						cout << " " << koeff[ i ] ;
				}
				else
				{
					cout << " -" ;
					if ( koeff[ i ] != -1 )
						cout << " " << -koeff[ i ] ;
				}

				// erster Koeffizient != 0 jetzt ausgegeben
				erster = false ;

				// gebe Potenz aus
				if ( i >= 2 )
					cout << " x^" << i ;
				else if ( i == 1 )
					cout << " x" ;
			}
		cout << endl ;

	}  // else ( koeff == NULL )

/***  räume Speicher auf  ***/

	delete[] rechteSeite ;
	for ( size_t i = 0 ;  i < Dim ;  ++i )
		delete[] matrix[ i ] ;
	delete[] matrix ;

	return 0 ;

}  // main()