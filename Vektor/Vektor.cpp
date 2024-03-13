#include "Vektor.h"

/**
 * Definitionen zur Klasse Vektor
 */

// definiere das Klassenattribut
size_t Vektor::_dim = UINT_MAX ;


/***  Konstruktoren  ***/

// Standardkonstruktor
Vektor::Vektor ()
{
	// alloziere Array dynamisch
	_x = new double[ _dim ] ;

	// weise den Ursprung als Standardwert zu
	for ( size_t i = 0 ;  i < _dim ;  ++i )
		_x[ i ] = 0 ;
}

// Kopierkonstruktor
Vektor::Vektor ( Vektor const& vek )
{
//cout << "Kopierkonstruktor gerufen!" << endl ;

	// alloziere Array dynamisch
	_x = new double[ _dim ] ;

	// delegiere Initialisierung an Zuweisungsoperator
	*this = vek ;
}

// Umwandlungskonstruktor von double-Array
Vektor::Vektor ( double const array[] )
{
//cout << "Umwandlungskonstruktor( array ) gerufen!" << endl ;

	// alloziere Array dynamisch
	_x = new double[ _dim ] ;

	// kopiere komponentenweise
	for ( size_t i = 0 ;  i < _dim ;  ++i )
		_x[ i ] = array[ i ] ;
}

// Umwandlungskonstruktor von double,
// init. alle Komponenten mit wert
Vektor::Vektor ( double wert )
{
//cout << "Umwandlungskonstruktor( wert ) gerufen!" << endl ;

	// alloziere Array dynamisch
	_x = new double[ _dim ] ;

	// kopiere komponentenweise
	for ( size_t i = 0 ;  i < _dim ;  ++i )
		_x[ i ] = wert ;
}


/***  set-Methoden  ***/

// Zuweisungsoperator
void Vektor::operator = ( Vektor const& vek )
{
	// sind Objekt und vek nicht identisch?
	// Jeder Zuweisungsoperator muss dazu
	// prüfen, ob beide Objekte an derselben
	// Stelle im Speicher stehen.
	// Der unäre '&'-Operator berechnet die
	// Speicheradresse des Objekts rechts von ihm.
	if ( this != &vek )
		// kopiere Objekte komponentenweise
		for ( size_t i = 0 ;  i < _dim ;  ++i )
			_x[ i ] = vek._x[ i ] ;
}

/***  Rechenmethoden  ***/

// Subtraktionsoperator, erzeugt neues Objekt
Vektor Vektor::operator - ( Vektor const& vek ) const
{
	Vektor ergebnis ;
	for ( size_t i = 0 ;  i < _dim ;  ++i )
		ergebnis._x[ i ] = _x[ i ] - vek._x[ i ] ;
	return ergebnis ;
}

// Skalarprodukt
double Vektor::operator * ( Vektor const& vek ) const
{
	double ergebnis = 0 ;
	for ( size_t i = 0 ;  i < _dim ;  ++i )
		ergebnis += _x[ i ] * vek._x[ i ] ;
	return ergebnis ;
}


/***  globale Funktionen  ***/

// gib Objekt formatiert auf ostr aus
ostream& operator << ( ostream& ostr, Vektor const& vek )
{
	ostr << "(" ;
	for ( size_t i = 0 ;  i < Vektor::dim() ;  ++i )
	{
		if ( i > 0 )
			ostr << "," ;
		ostr << " " << vek[ i ] ;
	}
	return ostr << " )" << endl ;
}
