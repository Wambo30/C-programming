#include <iostream>
using namespace std;

// probleme: typumwandlung von gr��eren typ zum kleineren typ erfolgt
//hierbei gehen die vordersten eintr�ge verloren, wenn eintrag in gr��eren typ
//den des kleineren typs �bersteigt

int main ()
{
 /* explizite Typumwandlungen */
	
	// int in char
	int zahl = 45 ;
	cout << zahl << endl ;			// ausgabe: 45
	cout << char( zahl ) << endl ;  // ausgabe: -
	


 /* implizite Typumwandlungen */
	
	// Zuweisung
	char zeichen = zahl ;
	cout << zeichen << endl;		// ausgabe: -
	

	// Operationen + , - , * , / , %
	int kleineZahl = 2147483647 ;  // gr��te mit int darstellb. Zahl
	cout << kleineZahl << endl;
	long long gro�eZahl = kleineZahl + kleineZahl ; // long long sollte diese Zahl darstellen k�nnen
	cout << gro�eZahl << endl; // ausgabe: -2, Fall �berlauf: da int + int = wert int datentyp zugewiesen
	//werden bzw. auf int ebene sein --> sonst fehler, dh dadurch entsteht �berlauf

	long long gro�eZahl2 = 1LL - 1LL + kleineZahl + kleineZahl; //ausgabe: 4294967294
	//sobald in summe/berechnung mindestens ein longlong operand existiert, dann rechnet auf LL ebene
	//WENN die zuweisende variable wo der neu berechnete wert rein kommt, auch LL datentyp hat
	//--> sonst wieder FEHLER von oben !

	// Funktionsaufruf

	//konstanten 

	double const FAKTOR = 2.5; // ist nicht ver�nderbar nachtr�glich, dieser wert wird immer benutzt
	
	bool fastGleich(double x, double y, double const EPSILON)
	{
		double const MAX_DIFF = FAKTOR * EPSILON;
		return betrag(x - y) < MAX_DIFF;
	}











	// Initialisierung eines statischen Arrays mit {}


	return 0 ;
}