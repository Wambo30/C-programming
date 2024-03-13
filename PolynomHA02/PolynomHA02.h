/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

/* Polynom.h */

#ifndef POLYNOMHA02_H
#define POLYNOMHA02_H

#include <string>
// ifndef sagt das man nur EINMAL string includen muss
//--> daher nutzt man das immer im header!! regel aufschreiben!

using namespace std;

class Polynom {
	//globale fkten
	friend ostream& operator <<(ostream&, const Polynom&);
	friend istream& operator >> (istream& eingabe, Polynom&);

public:
	Polynom();
	Polynom(size_t, double);
	Polynom(size_t);// für zufällige parameter
	Polynom(const Polynom&); // kopierkonstruktor
	Polynom& operator=(const Polynom&); // zuweisungsoperator
										//Polynom(double);// typumwandlungskonstruktor
	~Polynom();

	//set und get methoden
	size_t getGrad() const;
	double getKoeffizienten(size_t i) const;
	void setKoeffizienten(size_t i, double a);

	// andere methoden
	string toString() const;
	double wertBerechnen(double) const;
	bool istNullstelle(double wert);

	//rechnen mit polynomen
	void multiplizieren(double w);
	void multiplizieren(const Polynom&);
	void addieren(const Polynom&);
	void subtrahieren(const Polynom&);

	//ueberladen
	const Polynom operator+(const Polynom&);
	const Polynom operator-(const Polynom&);
	const Polynom operator*(const Polynom&);
	Polynom& operator+=(const Polynom&);
	Polynom& operator-=(const Polynom&);
	Polynom& operator*=(const Polynom&);

	//unaeres minus
	const Polynom operator*(const int& z);
	const Polynom operator-();

	//index operator
	double& operator[](const size_t);

private:
	size_t grad;
	double* koeffizienten;
	void gradRunterSetzen();
};

#endif //POLYNOM_H


