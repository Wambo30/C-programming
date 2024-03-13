#include "rational.h"
#include <iostream>
#include <cmath>
using namespace std;


Rational::Rational():zaehler(0), nenner(1){}
/* ODER:
	Rational::Rational(){
	zaehler =0;
	nenner = 1; }	
*/

Rational::Rational(int z): zaehler(z), nenner(1){}

Rational::Rational(int z, int n) : zaehler(z), nenner(n) {

	if (nenner == 0) {
		zaehler = 0; 
		nenner = 1;
		cout << "warnung! 0 ist im nenner" << endl;
	}
	else {
		kuerzen();
	}
}

Rational::~Rational()
{
}


void Rational::setZaehler(int z) {
	zaehler = z;
	kuerzen();
}
void Rational::setNenner(int n){
	nenner = n;
	kuerzen();
}

int Rational::getZaehler() const {
	return zaehler;
}
int Rational::getNenner() const {
	return nenner;
}




// andere methoden

// diese methode gehört NICHT zur klasse und wurde rekursiv definiert!
long ggt(long a, long b) {
	if (b == 0) {
		return a;
	}
	else {
		return ggt(b, a%b);
	}

}

void Rational::kuerzen() {
	// nenner muss positiv sein
	if (nenner < 0) {
		zaehler *= -1;
		nenner *= -1;
	}
	else {
		long teiler = ggt(abs(zaehler), nenner);
		zaehler /= teiler;
		nenner /= teiler;
	}
}