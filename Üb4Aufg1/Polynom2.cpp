/* PolynomD.cpp */

#include "Polynom2.h"
#include <iostream>
using namespace std;

Polynom2::Polynom2() : grad(0) {
	koeffizienten = new double[1];
	koeffizienten[0] = 0;
}


// Ein Polynom vom Grad g und allen Koeffizienten gleich a anlegen
Polynom2::Polynom2(size_t g, double a) : grad(g) {
	if (a) { // a != 0
		koeffizienten = new double[grad + 1];
		for (size_t i = 0; i < grad + 1; i++) {
			koeffizienten[i] = a;
		}
	}
	else {
		koeffizienten = new double[1];
		koeffizienten[0] = 0;
		grad = 0;
	}
}

//konstruktor für zufallskoeffizienten

Polynom2::Polynom2(size_t g): grad(g) {
	koeffizienten = new double[grad + 1];
	for (size_t i = 0; i < grad + 1; i++) {
		koeffizienten[i] = (rand() % 20001 - 10000) / 10000.;
	}
	// warum? wollen zufallszahl zwischen -1 und 1 haben und nehmen einfach 10000 zahl
	//und teulen sie einfach durch 10000--> somit haben wir eine zahl zw -1 und 1

	while (abs(koeffizienten[grad] < DBL_EPSILON)) {
		koeffizienten[grad] = (rand() % 20001 - 10000 / 10000.);
	}
}



//kopierkonstrukztor
// grad(p.grad) --> sind jene attribute ohne zeiger dh 
//nur das steht immer da
Polynom2::Polynom2(const Polynom2& p): grad(p.grad){
	// speicherplatz zuweisen
	koeffizienten = new double[grad + 1];
	
	// elemente des arrays kopieren, besser: <=grad+1
	for(size_t i = 0; i< grad+1; i++){
		koeffizienten[i] = p.koeffizienten[i];

	}

}

//zuweisungsoperator
Polynom2& Polynom2::operator=(const Polynom2& p) {
	//speicherplatz der linken seite der zuweisung freigeben

	if (koeffizienten) {
		delete[] koeffizienten;
	}
	//so viel speicherplatz wie die rechte seite hat, zuweisen
	koeffizienten = new double[p.grad + 1];

	//koeffizienten der rechte seite an die linke kopieren
	for (size_t i = 0; i < p.grad + 1; i++) {
		koeffizienten[i] = p.koeffizienten[i];
	}

	//alle attribute, die nicht zeiger sind, kopieren
	grad = p.grad;
	// getter ist nicht nötig da wir innerhalb der klasse sind!

	//zurückgegeben wird das objekt selbst
	return *this;

}

// Destruktor
Polynom2::~Polynom2() {
	if (koeffizienten) {
		delete[] koeffizienten;
		koeffizienten = 0;
	}
}

// set und get methoden


void Polynom2::setKoeffizienten(size_t i, double a) {
	if (i < grad || (i == grad && abs(a) >= DBL_EPSILON)) 
		koeffizienten[i] = a;
	
	else if (i == grad && abs(a)< DBL_EPSILON){

		cout << "Warnung: Koeffizient bei potenz ex nicht" 
			<< i <<"darf nicht 0 sein!"   <<endl;
	}
}

double Polynom2::getKoeffizienten(size_t i) const {
	if (i <= grad) {
		return koeffizienten[i];
	}
	else {
		cout << "Warnung: potenz ex nicht" << endl;
		return 0;

	}
}

// andere methoden
string Polynom2::toString() const {

	string pol = "p(x) = ";
	for (size_t i = grad; i > 0; i--) {
		if (abs(koeffizienten[i]) >= DBL_EPSILON) { //koeff !=0, gucktauf letzten koeff
			pol.append(to_string(koeffizienten[i]));
			pol.append(" * x^");
			pol.append(to_string(i));
			pol.append(" + ");
		}
	}
	if (abs(koeffizienten[0]) >= DBL_EPSILON) {
		pol.append(to_string(koeffizienten[0]));
	}
	//nullfunktion ausgeben
	else if (grad == 0) {
		pol.append("0");
	}

	return pol;
}
// nutzen hier horner schema
double Polynom2::wertBerechnen(double x) const {
	double wert = koeffizienten[grad];
	for (int i = grad-1; i >= 0; i--) {

		wert = wert * x + koeffizienten[i];
	}
	return wert;
}

bool Polynom2::istNullstelle(double x) const {

	return abs(wertBerechnen(x)) < DBL_EPSILON;
}

void Polynom2::multipliziere(double w) {
	if (abs(w) >= DBL_EPSILON) { // w!= 0
		for (size_t i = 0; i < grad; i++)
			koeffizienten[i] *= w;
	}
	else { // w==0 --> p(x) =0
		Polynom2 p;
		*this = p; // durch this* wird auf polynom gezeigt
	}
}

void Polynom2::multipliziere(const Polynom2& p) {
	if (p.grad == 0) {
		multipliziere(p.koeffizienten[0]);
	}
	else if (grad == 0) {
		// p ist const
		Polynom2 pkopie = p;
		pkopie.multipliziere(koeffizienten[0]);
		*this = pkopie;
	}
	else { // die summe der höchsten potenzen 
		Polynom2 kopie = *this;
		grad = kopie.grad + p.grad;
		delete [] koeffizienten;
		koeffizienten = new double[kopie.grad + p.grad + 1];

		for (size_t i = 0; i < grad; i++) {
			koeffizienten[0] = 0;
		}

		for (size_t i = 0; i < kopie.grad + 1; i++) {
			for (size_t j = 0; j < p.grad + 1; i++) {
				koeffizienten[i + j] += kopie.koeffizienten[i] * p.koeffizienten[j];
			}
		}
	}
}

void Polynom2::addiere(const Polynom2& p) {
	if (grad == p.grad) {
		for (size_t i = 0; i < grad+1; i++)
			koeffizienten[i] += p.koeffizienten	[i];
		//es kann passieren das bei grad-potenz 0 steht
		// grad runtersetzen
		gradRunterSetzen();
	}
	else if (grad > p.grad) {
		for (size_t i = 0; i < p.grad; i++) {
			koeffizienten[i] += p.koeffizienten[i];
		}
	}
	else { // grad < p.grad
		Polynom2 pkopie = p;
		for (size_t i = 0; i < grad; i++)
			pkopie.koeffizienten[i] += koeffizienten[i];
		*this = pkopie;
	}
}

void Polynom2::gradRunterSetzen(const Polynom2& p) {
	//if koeffizienten



}