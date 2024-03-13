#include <iostream>
using namespace std;

// probleme: typumwandlung von größeren typ zum kleineren typ erfolgt
//hierbei gehen die vordersten einträge verloren, wenn eintrag in größeren typ
//den des kleineren typs übersteigt

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
	int kleineZahl = 2147483647 ;  // größte mit int darstellb. Zahl
	cout << kleineZahl << endl;
	long long großeZahl = kleineZahl + kleineZahl ; // long long sollte diese Zahl darstellen können
	cout << großeZahl << endl; // ausgabe: -2, Fall Überlauf: da int + int = wert int datentyp zugewiesen
	//werden bzw. auf int ebene sein --> sonst fehler, dh dadurch entsteht überlauf

	long long großeZahl2 = 1LL - 1LL + kleineZahl + kleineZahl; //ausgabe: 4294967294
	//sobald in summe/berechnung mindestens ein longlong operand existiert, dann rechnet auf LL ebene
	//WENN die zuweisende variable wo der neu berechnete wert rein kommt, auch LL datentyp hat
	//--> sonst wieder FEHLER von oben !

	// Funktionsaufruf

	//konstanten 

	double const FAKTOR = 2.5; // ist nicht veränderbar nachträglich, dieser wert wird immer benutzt
	
	bool fastGleich(double x, double y, double const EPSILON)
	{
		double const MAX_DIFF = FAKTOR * EPSILON;
		return betrag(x - y) < MAX_DIFF;
	}











	// Initialisierung eines statischen Arrays mit {}


	return 0 ;
}