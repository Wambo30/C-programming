/* 02-wurzel-it.cpp */

/* Berechnen von der Wurzel einer Zahl mit
 * Bisektions- und Newton-Verharen
 *
 * iterative Variante 
 */

#include <iostream>
#include <cmath>                /* fuer die Wurzelfunktion sqrt() */

using namespace std;

const float EPS = 0.001;
enum verfahren {BIS = 1, NEWT, SQRT};

double betrag(double x) {
	return (x >= 0) ? (x) : -(x);
}

/* Bisektion - iterativ */
double bisection(double a) {
	double links = 0;			/* Intervallgrenzen bei der Bisektion */
	double rechts = a;		
	
	/* iteriere bis der Intervall klein genug ist */
	while( betrag(rechts - links) > EPS ) {
		double mitte = (rechts + links) * 0.5; 
		if (mitte * mitte > a)       
			rechts = mitte;
		else
			links  = mitte;
	}
	return (rechts + links)/2;
}

/* Newtonverfahren - iterativ */
double newton(double a) {
	double xAlt = 0;    /* alter Iterationsschritt */	
	double xNeu = a;	/* aktueller Iterationsschritt */	
	
	/* iteriere bis der Intervall klein genug ist */
	while( betrag(xNeu - xAlt) > EPS ) {
		xAlt = xNeu;
		xNeu = (xAlt + a/xAlt) * 0.5;
	}
	return xNeu;
}

int main(void) {
	double a;              /* Zahl deren Wurzel berechnet wird */
    int v;
	enum verfahren ver;	   /* Verfahrenstyp */
    char nochmal;
	
    do {
        /* Eingabe - Zahl */
        /* Eingabe - Zahl */
        do {
            cout << "Eine positive Zahl eingeben:" << endl;
            cin >> a;
        }
        while( a <= 0 );
	
        /* Eingabe - Verfahren */
        cout << "Welches Verfahren soll benutzt werden?" << endl;
        cout << BIS << " - Bisektion" << endl;
        cout << NEWT << " - Newtoniteration, Nullstelle von f(x) = x^2 - a" << endl;
        cout << SQRT << " - Bibliotheksfunktion sqrt" << endl;
        cin >> v;
	
        ver = (enum verfahren) v;
	
        /* Berechnung und Ausgabe */
        switch(ver) {
            case BIS:
                cout << "---------- Berechnung der Wurzel von " << a << " mit Bisektion  ----- " << endl << endl;
                cout << "bis(" << a << ") = " << bisection(a) << endl;
                break;
            case NEWT:
                cout << "---------- Berechnung der Wurzel von " << a << " mit Newton-Verfahren, f(x) = x^2 - a  ----- " << endl << endl;
                cout << "newton(" << a << ") = " << newton(a) << endl;
                break;		
            case SQRT:
                cout << "Bibliotheksfunktion sqrt(" << a << ") = " << sqrt(a) << endl;
                break;
            default: cout << "FEHLER: Falsche Eingabe!" << endl;
        }
        cout << endl << "Nochmal? (j/n): ";
        cin >> nochmal;
    }
    while( nochmal == 'j');
	
    return 0;
}




