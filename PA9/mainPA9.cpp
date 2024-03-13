#include <cstdlib>
#include <iostream>
#include "natuerlich.h"

// symbolische case-Marken
char const ADDITION       = '+' ;
char const MULTIPLIKATION = '*' ;
char const POTENZ		  = '^' ;
char const FAKULTAET      = '!' ;
char const FIBONACCI1     = 'f' ;
char const FIBONACCI2     = 'F' ;


int main ( int narg, char* argv[] )
{
    if (	 narg < 3			// zuwenige Argumente gegeben
		 ||	 (	   narg < 4
			   &&  argv[ 2 ][ 0 ] != FIBONACCI1
			   &&  argv[ 2 ][ 0 ] != FIBONACCI2
			   &&  argv[ 2 ][ 0 ] != FAKULTAET
	   )     )
    {
        cout << "usage: " << argv[ 0 ] << "  m  op  n" << endl ;
        cout << "       m, n: natuerliche Zahlen >= 0" << endl ;
        cout << "       op  : Operator '+' '*' '^' 'f' 'F' '!'" << endl ;
		cout << endl ;

		cout << "Berechnet Ergebnis des Ausdrucks \"m op n\"." << endl ;
		cout << "    op = '^'     : Potenz \"m hoch n\", auf Windows als \"^\" zu schreiben" << endl ;
		cout << "    op = 'f' 'F' : fibonacci( m ) [n wird ggf. ignoriert]" << endl ;
		cout << "    op = '!'     : fakultaet( m ) [n wird ggf. ignoriert]" << endl ;

        return 0 ;
    }

    // setze Inputgrößen
    Natuerlich m = argv[ 1 ] ;		// warum funktioniert das? ;-)
    Natuerlich n ;
    char op = argv[ 2 ][ 0 ] ;
	if ( narg >= 4 )
		n = string( argv[ 3 ] ) ;

	// berechne den Ausdruck, gebe Ergebnis aus
	Natuerlich ergebnis ;

	switch ( op )
	{
	case ADDITION:
		ergebnis = m + n ;
		break ;

	case MULTIPLIKATION:
		ergebnis = m * n ;
		break ;

	case POTENZ:
	{
		size_t exponent = atoi( argv[ 3 ] ) ;
		ergebnis = potenz( m, exponent ) ;
		break ;
	}

	case FIBONACCI1:
	case FIBONACCI2:
	{
		size_t index = atoi( argv[ 1 ] ) ;
		ergebnis = fibonacci( index ) ;
		break ;
	}

	case FAKULTAET:
	{
		size_t argument = atoi( argv[ 1 ] ) ;
		ergebnis = fakultaet( argument ) ;
		break ;
	}

	// alles andere
	default:
		cerr << "kann Operator " << op << " nicht erkennen!" << endl ;
		
	}  // switch ( op ) 

	cout << ergebnis << endl ;

	return 0 ;     // alles OK

}  // main()