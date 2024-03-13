#include "Vektor.h"


int main ()
{
/***  verwalte Dimension  ***/

	// setze Dimension der Vektoren
	if ( ! Vektor::setzeDim( 4 ) )
	{
		cerr << "kann Dimension nicht setzen!" << endl ;
		return 0 ;
	}

	cout << "Vektoren haben die Dimension "
		 << Vektor::dim() << endl ;

	// hier wird der Standardkonstruktor gerufen
	Vektor vek ;

/***  Indexzugriff  ***/
/*
	// schreibender Indexzugriff
	vek[ 0 ] = -1 ;
	vek[ 3 ] =  4 ;

	// Ausgabeoperator
	cout << "vek = " << vek << endl ;
//*/

/***  Zuweisung und Kopie  ***/
/*
	Vektor vek1, vek2 ;
	vek1[ 0 ] =  1 ;
	vek2[ 3 ] = -4 ;
	cout << "vek1 = " << vek1 << endl ;
	cout << "vek2 = " << vek2 << endl ;
	cout << endl ;

	// Zuweisungsoperator
	vek1 = vek2 ;
	cout << "vek1 = " << vek1 << endl ;
	cout << endl ;
//*
	// Kopierkonstruktor (trotz des '='!)
	Vektor vek3 = vek1 ;
	cout << "vek3 = " << vek3 << endl ;
	cout << endl ;
//*
	// Kopierkonstruktor: äquivalente Schreibweise
	Vektor vek4( vek1 ) ;
	cout << "vek4 = " << vek4 << endl ;
	cout << endl ;
//*/

/***  Rechenoperatoren  ***/
/*
	Vektor vek1, vek2 ;
	vek1[ 0 ] = 1 ;
	vek2[ 0 ] = 2 ;
	vek2[ 3 ] = 4 ;
	cout << "vek1 = " << vek1 << endl ;
	cout << "vek2 = " << vek2 << endl ;
	cout << endl ;

	// Subtraktion
	cout << "vek1 - vek2 = " << vek1 - vek2 << endl ;
	cout << endl ;

	// Skalarprodukt
	cout << "vek1 * vek2 = " << vek1 * vek2 << endl ;
	cout << endl ;
//*/

/***  Umwandlungskonstruktoren  ***/
/*
	double werte[] = { 1, 2, 3, 4, 5, 6 } ;

	// Umwandlung von Array in Vektor
	Vektor vek1( werte ) ;
	cout << "vek1 = " << vek1 << endl ;
	cout << endl ;
//*
	// was tut das?
	Vektor vek2 = werte ;
	cout << "vek2 = " << vek2 << endl ;
	cout << endl ;
//*
	// implizite Umwandlung von double[]
	Vektor vek3 ;
	cout << "vek3 = " << vek3 << endl ;
	vek3 = werte ; // "Vektor = double[]" nicht deklariert!
	cout << "vek3 = " << vek3 << endl ;
	cout << endl ;
//*
	// implizite Umwandlung als Argument von operator -
	vek1[ 0 ] = 0 ;
	cout << "Differenz  = " << vek1 - werte << endl ;
	cout << endl ;

	// implizite Umwandlung als Argument von operator *
	cout << "Skalarprod = " << vek1 * werte << endl ;
	cout << endl ;
//*
	// was passiert hier?
	// Achtung: 0 wird als Vektor( nullptr ) interpretiert!
	Vektor vekt = 0 ;
	cout << "vekt = " << vekt << endl ;
//*
	// explizite Umwandlung von double
	Vektor vek4( 3 ) ;
	cout << "vek4 = " << vek4 << endl ;
	cout << "vek1 - vek4 = " << vek1 - vek4 << endl ;
	cout << endl ;

	// implizite Umwandlungen von double
	// sind Syntaxfehler, wenn der Umwandlungs-
	// konstruktor "explicit" deklariert wurde
	Vektor vek5 = 3 ;
	cout << "vek5 = " << vek5 << endl ;
	cout << "vek1 - 3    = " << vek1 - Vektor( 3 ) << endl ;
	cout << endl ;
//*/

/***  typische Vektormethoden (this) ***/
/*
	double werte[] = { -1, 2, -3, 4, -5 } ;
	Vektor vek1( werte ) ;

	// berechne eukl. Norm von vek1
	cout << "|| " << vek1 << " || = "
		 << vek1.norm() << endl ;
	cout << endl ;
//*
	Vektor vek2 = vek1 ;
	vek2[ 1 ] =  0 ;
	vek2[ 2 ] =  2 ;
	vek2[ 3 ] = -1 ;

	// berechne eukl. Abstand von vek1, vek2
	cout << "|| vek1 - vek2 || = "
		 << vek1.dist( vek2 ) << endl ;
	cout << endl ;
//*/

	return 0 ;

}  // main()