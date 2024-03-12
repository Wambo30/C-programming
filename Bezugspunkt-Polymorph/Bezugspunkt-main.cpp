/*  
 * Bezugspunkt-main.cpp
 * Programmieren IIb, Übungsblatt 2, Ü1
 */

#include "Bezugspunkt.h"

#include <iostream>
using namespace std;

int main(void) {
	Kreis kreis(0., -1., 4);
    Rechteck rechteck(-1., 1., 2., 1.);
    Rechteck quadrat(0., 0., 2., 2.);
	
	Bezugspunkt* figuren[] = { &kreis, &rechteck, &quadrat};
	
	for( int i = 0; i < 3; i++) {
		cout << endl;
		cout << *figuren[i] << endl;
		cout << "Flaeche: " << figuren[i]->flaecheBerechnen() << endl;
	}
	
	for( int i = 0; i < 3; i++) {
		cout << endl;
        cout << "Bezugspunkt um (-1,1) verschieben:"; 
        // Die Methode der Basisklasse aufrufen
		figuren[i]->Bezugspunkt::ausgeben(cout);
		figuren[i]->verschieben(-1., 1.);
		cout << *figuren[i] << endl;
	}
	
    return 0;
}



