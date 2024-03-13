#include <iostream>
#include "Nullstelle.h"
#include <cmath>        /* C-Bibliothek fuer die Wurzelfunktion sqrt() */
using namespace std;
const float EPS = 0.001;
enum verfahren { BIS = 1, NEWT, SQRT };

int main() {
	double a;              /* Zahl, derer Wurzel berechnet wird */
	int v;
	enum verfahren ver;	   /* Verfahrenstyp */
	char nochmal;


	do {
		/* Eingabe - Zahl */
		do {
			cout << "Eine positive Zahl eingeben:" << endl;
			cin >> a;
		} while (a <= 0);

		/* Eingabe - Verfahren */
		cout << "Welches Verfahren soll benutzt werden?" << endl;
		cout << BIS << " - Bisektion" << endl;
		cout << NEWT << " - Newtoniteration, Nullstelle von f(x) = x^2 - a" << endl;
		cout << SQRT << " - Bibliotheksfunktion sqrt" << endl;
		cin >> v;

		ver = (enum verfahren) v;

		/* Berechnung und Ausgabe */
		switch (ver) {
		case BIS:
			cout << " -- Berechnung der Wurzel von " << a << " mit Bisektion (rekursiv) -- " << endl << endl;
			cout << "bis(" << a << ") = " << bisection(0, a, a) << endl;
			break;
		case NEWT:
			cout << " -- Berechnung der Wurzel von " << a << " mit Newton-Verfahren, f(x) = x^2 - a (rekursiv) -- " << endl << endl;
			cout << "newton(" << a << ") = " << newton(0, a, a) << endl;
			break;
		case SQRT:
			cout << "Bibliotheksfunktion sqrt(" << a << ") = " << sqrt(a) << endl;
			break;
		default: cout << "FEHLER: Falsche Eingabe!" << endl;
		}
		cout << endl << "Nochmal? (j/n): ";
		cin >> nochmal;
	} while (nochmal == 'j');

	system("pause");
	return 0;
}



