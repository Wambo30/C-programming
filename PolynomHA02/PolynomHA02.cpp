/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/
/* Polynom.cpp */

#include "PolynomHA02.h"
#include <iostream>
#include <cfloat>   // wegen DBL_EPSILON
#include <cmath>    // wegen abs
using namespace std;

// Der Standardkonstruktor erzeugt die Nullfunktion p(x) = 0
Polynom::Polynom() : grad(0) {
	koeffizienten = new double[1];
	koeffizienten[0] = 0;
}

// Ein Polynom vom Grad g und allen Koeffizienten gleich a anlegen
Polynom::Polynom(size_t g, double a) : grad(g) {
	if (a) {
		koeffizienten = new double[grad + 1];
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] = a;
		}
	}
	else { // Eine Nullfunktion
		cout << "WARNUNG: Nullkoefizienten -> p(x) = 0";
		koeffizienten = new double[1];
		koeffizienten[0] = 0;
		grad = 0;
	}
}

// Konstruktor fuer ein Polynom mit Zufallskoeffizienten in [-1.,1.]
Polynom::Polynom(size_t g) : grad(g) {
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++) {
		// Eine Zahl zwischen -10000 und 10000 (zum Beispiel)
		// die Zahl auf den Intervall [-1,1] skalieren
		koeffizienten[i] = (rand() % 20001 - 10000) / 10000.;
	}
	// solange der f¸hrende Koeffizient auf Null gesetzt wird
	// Rundungsfehler bei double Datentyp beachten
	while (abs(koeffizienten[grad]) < DBL_EPSILON) { // == 0
		koeffizienten[grad] = (rand() % 20001 - 10000) / 10000.;
	}
}

/*

//Typumwandlungskonstruktor wo grad von flieﬂkommazahl in positive ganze zahl
//umgewandelt wird
Polynom::Polynom(double g,double a){
grad = size_t(g);
if (a) {
koeffizienten = new double[grad + 1];
for (size_t i = 0; i < grad + 1; i++) {
koeffizienten[i] = a;
}
}
else { // Eine Nullfunktion
cout << "WARNUNG: Nullkoefizienten -> p(x) = 0";
koeffizienten = new double[1];
koeffizienten[0] = 0;
grad = 0;
}

}

grad = size_t(g);
if (a) {
koeffizienten = new double[grad + 1];
for (size_t i = 0; i < grad + 1; i++) {
koeffizienten[i] = a;
}
}
else { // Eine Nullfunktion
cout << "WARNUNG: Nullkoefizienten -> p(x) = 0";
koeffizienten = new double[1];
koeffizienten[0] = 0;
grad = 0;
}
}
*/


// Kopierkonstruktor
Polynom::Polynom(const Polynom& p) : grad(p.grad) {
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
Polynom& Polynom::operator=(const Polynom& p) {

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
Polynom::~Polynom() {
	if (koeffizienten) {
		delete[] koeffizienten;
		koeffizienten = 0;
	}
}

// Setter und Getter
// den i-ten Koeffizienten setzen
void Polynom::setKoeffizienten(size_t i, double a) {
	if (i < grad || (i == grad && abs(koeffizienten[grad]) >= DBL_EPSILON)) {
		koeffizienten[i] = a;
	}
	else if (i == grad && abs(koeffizienten[grad]) < DBL_EPSILON) {
		cout << "FEHLER: Koeffizient bei Grad-Potenz darf nicht Null sein!" << endl;
	}
	else {
		cout << "FEHLER: Ungueltige Potenz!" << endl;
	}
}

double Polynom::getKoeffizienten(size_t i) const {
	if (i <= grad) {
		return koeffizienten[i];
	}
	else {
		cout << "FEHLER: Ungueltige Potenz!" << endl;
		return 0;
	}
}

size_t Polynom::getGrad() const { return grad; }


// Den Wert des Polynoms an der Stelle x berechnen
double Polynom::wertBerechnen(double x) const {
	double wert = koeffizienten[grad];
	for (int i = (int)grad - 1; i >= 0; i--) {  // Bei size_t 0-- ist eine groﬂe Zahl
		wert = wert * x + koeffizienten[i];
	}
	return wert;
}

bool Polynom::istNullstelle(double wert) {
	return abs(wertBerechnen(wert)) < DBL_EPSILON;
}

// Mit einer Gleitkommazahl multiplizieren
// Faelle unterscheiden wenn wert gleich 0
void Polynom::multiplizieren(double w) {
	if (abs(w) > DBL_EPSILON) { // w != 0
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] *= w;
		}
	}
	else { // das Polynom ist gleich 0
		Polynom p;  // Nullfunktion erzeugen
		*this = p;
	}
}

// Ein anderes Polynom aufaddieren
void Polynom::addieren(const Polynom& p) {
	if (grad == p.grad) {
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
		// Es kann passieren, dass die fuehrenden Koeffizienten Null ergeben
		gradRunterSetzen();
	}
	else if (grad > p.grad) {
		for (size_t i = 0; i < p.grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
	}
	else { // grad < p.grad
		   // Kopie gleich dem Polynom p erstellen, weil p const und kann nicht benutzt werden
		   // zur Kopie unser aktuelles Objekt aufsumieren
		Polynom pol = p;
		for (size_t i = 0; i < grad + 1; i++) {
			pol.koeffizienten[i] += koeffizienten[i];
		}
		// unser Objekt mit der Kopie ersetzen
		*this = pol;
	}
}

// Ein anderes Polynom aufaddieren
void Polynom::subtrahieren(const Polynom& p) {
	Polynom pol = p;
	pol.multiplizieren(-1.);
	addieren(pol);
}

// Ein anderes Polynom aufmultiplizieren
void Polynom::multiplizieren(const Polynom& p) {
	if (p.grad == 0) {
		multiplizieren(p.koeffizienten[0]);
	}
	else if (grad == 0) {
		Polynom pkopie = p;
		pkopie.multiplizieren(koeffizienten[0]);
		*this = pkopie;
	}
	else {
		Polynom kopie = *this;
		delete[] koeffizienten;
		koeffizienten = new double[kopie.grad + p.grad + 1];
		grad = kopie.grad + p.grad;

		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] = 0.;
		}

		for (size_t i = 0; i < kopie.grad + 1; i++) {
			for (size_t j = 0; j < p.grad + 1; j++) {
				koeffizienten[i + j] += kopie.koeffizienten[i] * p.koeffizienten[j];
			}
		}
	}
}

// operatoren
// ausgabe const ist nicht vorhanden da man sonst gradRunterSetzen() nicht
//nutzen kann
const Polynom Polynom::operator+(const Polynom& p) {
	if (grad == p.grad) {
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
		// Es kann passieren, dass die fuehrenden Koeffizienten Null ergeben
		gradRunterSetzen();
	}
	else if (grad > p.grad) {
		for (size_t i = 0; i < p.grad + 1; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
	}
	else { // grad < p.grad
		   // Kopie gleich dem Polynom p erstellen, weil p const und kann nicht benutzt werden
		   // zur Kopie unser aktuelles Objekt aufsumieren
		Polynom pol = p;
		for (size_t i = 0; i < grad + 1; i++) {
			pol.koeffizienten[i] += koeffizienten[i];
		}
		// unser Objekt mit der Kopie ersetzen
		*this = pol;
	}
	return *this;
}

Polynom& Polynom::operator+=(const Polynom& p) {
	*this = *this + p;
	return *this;
}

const Polynom Polynom::operator-(const Polynom& p) {
	Polynom pol = p;
	pol.multiplizieren(-1.);
	addieren(pol);
	return *this;
}

Polynom& Polynom::operator-=(const Polynom& p) {
	Polynom pol = p;
	pol.multiplizieren(-1.);
	addieren(pol);
	*this = *this - p;
	return *this;
}

const Polynom Polynom::operator*(const Polynom& p) {
	if (p.grad == 0) {
		multiplizieren(p.koeffizienten[0]);
	}
	else if (grad == 0) {
		Polynom pkopie = p;
		pkopie.multiplizieren(koeffizienten[0]);
		*this = pkopie;
	}
	else {
		Polynom kopie = *this;
		delete[] koeffizienten;
		koeffizienten = new double[kopie.grad + p.grad + 1];
		grad = kopie.grad + p.grad;

		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] = 0.;
		}

		for (size_t i = 0; i < kopie.grad + 1; i++) {
			for (size_t j = 0; j < p.grad + 1; j++) {
				koeffizienten[i + j] += kopie.koeffizienten[i] * p.koeffizienten[j];
			}
		}
	}
	return *this;
}

Polynom& Polynom::operator*=(const Polynom& p) {
	*this = *this * p;
	return *this;
}

// fkt schreiben damit polynom mit ganzer zahl multiplizierbar ist
const Polynom Polynom::operator*(const int& z) {
	Polynom kopie = *this;
	for (size_t i = 0; i < kopie.grad + 1; i++) {
		kopie.koeffizienten[i] *= -1;
	}
	return kopie;
}

//unaeres minus
const Polynom Polynom::operator-() {
	Polynom kopie = *this;
	kopie = kopie * -1;
	*this = kopie;
	return *this;
}

//Index operator
double& Polynom::operator [] (const size_t pos) {
	return koeffizienten[pos];
}

// Es kann passieren, dass die f¸hrenden Koeffizienten
// gleich 0 sind - diese muessen eliminiert werden
void Polynom::gradRunterSetzen() {
	size_t g = grad;
	while (abs(koeffizienten[g]) < DBL_EPSILON && g >= 1) { // Bei grad == 0 muessen wir nichts machen
		g--;
	}
	if (g < grad) {
		Polynom pol(g);
		for (size_t i = 0; i < g + 1; i++) {
			pol.koeffizienten[i] = koeffizienten[i];
		}
		grad = g;
		*this = pol;
	}
}

// Ausgabe
// Wer moechte kann auf 2 Nachkommastellen abrunden
string Polynom::toString() const {
	string pol = "p(x) = ";
	for (size_t i = grad; i > 0; i--) {
		if (abs(koeffizienten[i]) > DBL_EPSILON) { //koeffizienten[i] != 0
			pol.append(to_string(koeffizienten[i]));
			pol.append(" * x^");
			pol.append(to_string(i));
			pol.append(" + ");
		}
	}
	if (abs(koeffizienten[0]) > DBL_EPSILON) {
		pol.append(to_string(koeffizienten[0]));
	}
	else if (grad == 0) { // Bei Null macht to_string gar nichts
		pol.append("0");
	}
	return pol;
}

//Globale Funktionen
//Ueberladen von Aus- und Eingabe-Operatoren <<,>>
ostream& operator <<(ostream& ausgabe, const Polynom& p) {
	ausgabe << p.toString();
	return ausgabe;
}
istream& operator >> (istream& eingabe, Polynom& p) {
	size_t grad;
	double ziffer;

	cout << "Grad: ";
	eingabe >> grad;
	p.grad = grad;
	delete[] p.koeffizienten;
	p.koeffizienten = new double[grad + 1];
	for (int i = 0; i <= grad; i++) {
		cout << endl << "Koeffizenten fuer x^" << i << "= ";
		eingabe >> ziffer;
		p.koeffizienten[i] = ziffer;
	}
	return eingabe;
}