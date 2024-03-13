#include "Aufg2Datum.h"
#include <iostream>
using namespace std;

Aufg2Datum::Aufg2Datum()
{
}


Aufg2Datum::~Aufg2Datum()
{
}

void Aufg2Datum::setTag(int t) {
	int temp = tag;         // den aktuellen Tag merken, falls die Aenderung nicht klappt
	if (istGueltig()) {
		tag = t;
	}
	else {
		cout << "WARNUNG: Tag " << t << " nicht gueltig!" << endl;
		tag = temp;       // Der alte Tag wird nicht veraendert
	}
}

void Aufg2Datum::setMonat(int m) {
	int temp = monat;
	if (istGueltig()) {
		monat = m;
	}
	else {
		cout << "WARNUNG: Monat " << m << " nicht gueltig!" << endl;
		monat = temp;
	}
}

void Aufg2Datum::setJahr(int j) {
	int temp = jahr;
	if (istGueltig()) {
		jahr = j;
	}
	else {
		cout << "WARNUNG: Jahr " << j << " nicht gueltig!" << endl;
		jahr = temp;
	}
}
int Aufg2Datum::getTag() const { return tag; }
int Aufg2Datum::getMonat() const { return monat; }
int Aufg2Datum::getJahr() const { return jahr; }

bool Aufg2Datum::istSchaltjahr() const {

	//jahreszahl durch 4 teilbar aber nicht durch 100 und jahr durch 400 teilbar
	//modulo regel: n = m*a+b also 17%3 = 2 da 17= 5*3+2
	//((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0))
	return ((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0));

}


bool Aufg2Datum::istGueltig()const {

	int maxTage[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	maxTage[1] = (istSchaltjahr()) ? 29 : 28;
	return (jahr >= 1990 && monat >= 1 && monat <= 12 && tag >= 1 && tag <= maxTage[monat - 1]);
}


// andere methoden
//
void Aufg2Datum::verschieben(int v) {
	tag += v;
	if (!istGueltig()) {
		tag = 1;
		monat += v;
		if (!istGueltig()) {
			monat = 1;
			jahr += v;
		}
	}
}
