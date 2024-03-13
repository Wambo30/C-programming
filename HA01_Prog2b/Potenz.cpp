/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
#include "Potenz.h"
#include <iostream>
using namespace std;

// Konstruktor fuer ein Potenz mit Zufallskoeffizienten in [-1.,1.]
Potenz::Potenz(size_t g): grad(g){
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++) {
		// Eine Zahl zwischen -10000 und 10000 (zum Beispiel)
		// die Zahl auf den Intervall [-1,1] skalieren
		koeffizienten[i] = (rand() % 20001 - 10000) / 10000.;
	}
	// solange der führende Koeffizient auf Null gesetzt wird
	// Rundungsfehler bei double Datentyp beachten
	while (abs(koeffizienten[grad]) < DBL_EPSILON) { // == 0
		koeffizienten[grad] = (rand() % 20001 - 10000) / 10000.;
	}
}


// Kopierkonstruktor
Potenz::Potenz(const Potenz& p) : grad(p.grad) {
	// Speicherplatz fuer die Kopie des Feldes reservieren
	koeffizienten = new double[p.grad + 1];

	// Die Elemente des Feldes Kopieren
	for (int i = 0; i <= p.grad; i++) {
		koeffizienten[i] = p.koeffizienten[i];
	}
}

// Zuweisungsoperator
// Rueckgabewert: eine Referenz auf ein Objekt der eigenen Klasse
// Parameter: konstante Refrenz auf ein Objekt der Klasse
Potenz& Potenz::operator=(const Potenz& p) {

	// Speicherplatz des Zielobjektes freigeben
	if (koeffizienten) delete[] koeffizienten;

	// Neuen Speicherplatz anfordern
	koeffizienten = new double[p.grad + 1];

	// Dynamische Daten des Quellobjekts in das Zielobjekt speichern
	for (int i = 0; i <= p.grad; i++)
		koeffizienten[i] = p.koeffizienten[i];

	// Alle Elementvariablen, die keine Zeiger sind, kopieren
	grad = p.grad;

	// das Zielobjekt zurueckgeben
	return *this;
}

// Destruktor
Potenz::~Potenz() {
	if (koeffizienten) {
		delete[] koeffizienten;
		koeffizienten = 0;
	}
}

//p(x)
//berechne p(x) für einen bestimmten Wert x
const double Potenz::operator()(double x) const {
	double x_temp = x;
	double ergebnis = 0;
	//size_t hoch = 0;
	size_t hoch = grad;
	for (int i = 0; i <= grad; i++) {
		ergebnis += koeffizienten[i] * pow(x_temp, hoch);
		hoch++;
	}
	return ergebnis;
}

