#include "Aufg2Ferien.h"
#include "Aufg2Datum.h"
#include <iostream>
using namespace std;

//legt objekt an, die 10 nacheinander folgende tage dauern und bei zufallsdatum beginnt
Aufg2Ferien::Aufg2Ferien()
{
	/*
		tag = rand() % 31 ;
		monat = rand() % 12 ;
		jahr = rand() % 100 + 1990;
		if (!istGueltig()) {
			tag = rand() % 28 + 1;
	}
	else {
		tag = monat = 1;
		jahr = STARTJAHR;
	}
	*/

}


Aufg2Ferien::~Aufg2Ferien()
{
	if (freieTage)
		delete[] freieTage;
}

// parameter: erster tag der ferien und anzahl der freien tage
Aufg2Ferien::Aufg2Ferien(const Aufg2Datum& d, int n) {
	Aufg2Ferien* array = new Aufg2Ferien[n];
	//array[0] = d.Aufg2Datum::getTag();

	//Aufg2Ferien d1 = freieTage [0];
	int* array = new int [n];
	for (int i = 0; i < n + 1; i++) {
		freieTage[i] = array[i];
	}


}

// kopierkonstruktor
Aufg2Ferien::Aufg2Ferien(const Aufg2Ferien& f): anzahlTage(f.anzahlTage) {
	freieTage = new int[anzahlTage];
	for (int i = 0; i < anzahlTage + 1; i++) {
		freieTage[i] = f.freieTage[i];
	}
}

//zuweisungsoperator
Aufg2Ferien& Aufg2Ferien::operator= (const Aufg2Ferien& f) {
	if (freieTage)
		delete[] freieTage;

	freieTage = new int[f.anzahlTage + 1];
	for (int i = 0; i <= f.anzahlTage; i++) {
		freieTage[i] = f.freieTage[i];
	}
	anzahlTage = f.anzahlTage;
	return *this;

}

//getter
int Aufg2Ferien::getAnzahlTage() const {
	return anzahlTage;
}


// andere methoden

void Aufg2Ferien::verschieben(int n) {
	
	for (int i = 0; i <= anzahlTage; ++i) {
		freieTage[i] += n;
	}
}