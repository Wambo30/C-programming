/**
 * potenz.cpp
 * Datum: 27.11.17
 *
 * Der Benutzer gibt auf der Console eine
 * nat�rliche Zahl n ein und es wird 2^n berechnet.
 */

#include <iostream>
using namespace std ;

int main ()
{
	// f�hre Dialog mit Benutzer
	int n ;
	cout << "gib ein n = " ;
	cin >> n ;

	// berechne Ergebnis 2^n
	int potenz = 1 ;
	for ( int i = 1 ;  i <= n ;  ++i )
		
		potenz *= 2 ; // potenz = potenz * 2;

	// behandle �berlauf
	if ( potenz <= 0 )
	{
		// gib Fehlermeldung aus
		cerr << "Ueberlauf aufgetreten!" << endl ;

		// gib Fehlercode zur�ck (Wert willk�rlich)
		return -1 ;
	}

	// gib Ergebnis aus
	cout << "Ergebnis 2^" << n << " = " << potenz << endl ;

	return 0 ;		// alles OK

}  // main()

