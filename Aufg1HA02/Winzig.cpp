/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#include "Winzig.h"
#include "Fehler.h"
#include <iostream>
#include <string>
using namespace std;

const int OBERGRENZE = 100;
const int UNTERGRENZE = -100;

Winzig::Winzig(){}

Winzig::Winzig(int w):wert(w) {}

Winzig::~Winzig(){}


int Winzig::getWert() const {
	return wert;
}

void Winzig::setWert(int w) {
	if (w > OBERGRENZE) throw UeberlaufFehler(w, OBERGRENZE, ' ');
	
	if (w < UNTERGRENZE) throw UnterlaufFehler(w, UNTERGRENZE, ' ');
	
	wert = w; 
}

void Winzig::ueberpruefen(char op) {
	if (wert > OBERGRENZE) throw UeberlaufFehler(wert, OBERGRENZE, ' ');

	if (wert < UNTERGRENZE) throw UnterlaufFehler(wert, UNTERGRENZE, ' ');

}

const Winzig Winzig::operator+ (const Winzig& w) const {
	Winzig kopie;
	int result = this->getWert() + w.getWert();
	kopie.setWert(result);
	kopie.ueberpruefen(' ');

	return kopie;

}
const Winzig Winzig::operator- (const Winzig& w) const {
	Winzig kopie;

	int result = this->getWert() - w.getWert();
	kopie.setWert(result);
	kopie.ueberpruefen(' ');
	return kopie;
}
const Winzig Winzig::operator* (const Winzig& w) const {
	Winzig kopie;
	
	int result = this->getWert() * w.getWert();

	kopie.setWert(result);
	kopie.ueberpruefen(' ');

	return kopie;

}
const Winzig Winzig::operator/ (const Winzig& w) const {
		Winzig kopie;
		if (w.getWert() == 0) throw NulldivisionFehler();
			int result = (this->getWert()) / (w.getWert());
			kopie.setWert(result);
		
		return kopie;
	
}


// globale funktionen

ostream& operator<<(ostream& aus, const Winzig& t) {
	aus << t.getWert();

	return aus;
}


istream& operator >> (istream& ein, Winzig& t) {
	int zahl;
	cout << "Eine Zahl im Bereich (-100 .. 100): ";
	ein >> zahl;
	t.setWert(zahl);
	return ein;
}
