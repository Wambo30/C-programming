
#include <iostream>		/* Ein- und Ausgabe */
#include <cmath>        /* C-Bibliothek fuer die Wurzelfunktion sqrt() */

using namespace std;
const float EPS = 0.001;
enum verfahren { BIS = 1, NEWT, SQRT };



double betrag(double x) {
	return (x >= 0) ? (x) : -(x);
}

/* Bisektion - rekursiv */
double bisection(double links, double rechts, double a) {
	double mitte = (links + rechts)*0.5;
	if (betrag(links - rechts) > EPS) {
		if (mitte * mitte > a)
			rechts = mitte;
		else
			links = mitte;
		return bisection(links, rechts, a);
	}
	return mitte;
}

/* Newton-Verfahren - rekursiv */
double newton(double xAlt, double xNeu, double a) {
	if (betrag(xNeu - xAlt) > EPS) {
		xAlt = xNeu;
		xNeu = (xAlt + a / xAlt) / 2.;
		return newton(xAlt, xNeu, a);
	}
	return xNeu;
}

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
