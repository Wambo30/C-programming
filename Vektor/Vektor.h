#include <iostream>    // f�r ostream
#include <cmath>       // f�r sqrt()

using namespace std ;


/**
 * Klasse f�r Vektoren beliebiger L�nge
 */

class Vektor
{
/***  private Attribute  ***/

	// Array der Vektorkomponenten
	double* _x ;

	// Dimension des Objekts als Klassenattribut
	static size_t  _dim ;

public:
/***  static-Funktionen  ***/
// static-Funktionen sind keine Methoden,
// denn sie werden nicht �ber ein Objekt gerufen!

	// setze L�nge der Objekte, gib Erfolg zur�ck
	static bool setzeDim ( size_t dim )
	{
		// akzeptiere nur positive Dimensionen
		if ( dim > 0 )
		{
			_dim = dim ;
			return true ;
		}
		return false ;
	}

	// gib Dimension der Objekte aus
	static size_t dim ()
	{
		return _dim ;
	}

/***  Konstruktoren  ***/

	// Standardkonstruktor, ist ein Standardelement.
	// M�ssen wir hier selbst schreiben, um das Array
	// zu initialisieren. Definition in Vektor.cpp,
	// da K�rper eine Schleife enth�lt -> Regel
	// guten Stils 8.6.5
	Vektor () ;

	// Kopierkonstruktor, ist ein Standardelement.
	// M�ssen wir hier selbst schreiben, weil der
	// Compiler die Kopie des Arrays nicht selbst
	// machen kann.
	Vektor ( Vektor const& vek ) ;

	// Umwandlungskonstruktor von double-Array
	// "explicit" unterdr�ckt die �quivalente
	// Aufrufsyntax "Vektor x = array" und die
	// impliziten Aufrufe in gemischten Ausdr�cken
	// wie "Vektor + Array"
	explicit Vektor ( double const array[] ) ;

	// Umwandlungskonstruktor von double,
	// init. alle Komponenten mit wert
	explicit Vektor ( double wert ) ;

/***  get-Methoden  ***/

	// gib Komponente x[i] als Wert zur�ck
	double operator [] ( size_t i ) const
	{
		if ( i < _dim )		// i zul�ssig?
			return _x[ i ] ;
		else
		{
			// Dilemma! Wir l�sen das in Prog2b
			// Als Workaround diese L�sung:
			static double dummy ;
			return dummy ;
		}
	}

	// berechne euklidische Norm des Objekts
	double norm () const
	{
		// "this" ist ein Zeiger auf das eigene Objekt.
		// Das Objekt selbst ist dessen Dereferenz
		// mit dem un�ren '*'-Operator: *this.

		// berechne Norm laut Definition: ||x|| = sqrt( <x,x> )
		return sqrt( (*this) * (*this) ) ;
	}

	// berechne Abstand zwischen Objekt und vek
	double dist ( Vektor const& vek ) const
	{
		// berechne Abstand laut Definition:
		// dist(x,v) = ||x-v||
		return ( *this - vek ).norm() ;
	}

/***  set-Methoden  ***/

	// gib Komponente x[i] als Referenz zur�ck
	double& operator [] ( size_t i )
	{
		if ( i < _dim )		// i zul�ssig?
			return _x[ i ] ;
		else
		{
			// Dilemma! Wir l�sen das in Prog2b
			// Als Workaround diese L�sung:
			static double dummy ;
			return dummy ;
		}
	}
	// Diese set-Methode operator[] ist semantisch 
	// identisch zur get-Methode operator[]. Der
	// Zusatz "const" ist signifikant f�r den Typ,
	// sodass beide ben�tigt werden.

	// Zuweisungsoperator, ist ein Standardelement.
	// M�ssen wir hier selbst schreiben, weil der
	// Compiler die Kopie des Arrays nicht selbst
	// machen kann.
	void operator = ( Vektor const& vek ) ;

/***  Rechenmethoden  ***/

	// Subtraktionsoperator, erzeugt neues Objekt
	Vektor operator - ( Vektor const& vek ) const ;

	// Skalarprodukt
	double operator * ( Vektor const& vek ) const ;

/***  Destruktor  ***/

	// Der Destruktor ist ein Standardelement.
	// M�ssen wir hier selbst schreiben, weil der
	// Compiler die R�ckgabe des Arrays nicht selbst
	// erkennen kann.
	~Vektor ()
	{
		// l�sche dynamischen Speicher
		delete[] _x ;
	}

} ;  // class Vektor


/***  globale Funktionen  ***/

// gib Objekt formatiert auf ostr aus
ostream& operator << ( ostream& ostr, Vektor const& vek ) ;
