/*
Autoren:
 Wahid Far, Okhtay 870485
 Bieber, Okan 874666
*/
/* Dual.h */

#ifndef DUAL_H
#define DUAL_H
#include <string>
using namespace std;

class Dual {

public:

	//Konstruktoren 
	Dual();								//Standartkonstruktor
	Dual(size_t dezimal);				//Konstruktor
	~Dual();							//Destruktor
	Dual(const Dual& d);
	Dual& operator=(const Dual& d);	//zuweisungsoperator

	//Setter und Getter	

	// andere methoden
	void ausgeben();
	double toDezimal();
	string toString() const;
	Dual operator+(const Dual& d);
	Dual& operator+=(const Dual& d);
	Dual& operator*=(const Dual& d);
	Dual operator*(const Dual& d);

	//Berechnungen
	void umrechnenDezimalZuDual(size_t dezimal);

private:
	size_t anzahl;
	bool* ziffern;

	bool addieren(bool, bool, bool&);

};

#endif //DUAL_H