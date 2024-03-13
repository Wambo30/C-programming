#include "TierDestr.h"
#include <iostream>
using namespace std;


TierDestr::TierDestr(){
	cout << "Tier-Konstruktor" << endl;
}


TierDestr::~TierDestr(){
	cout << "Tier-Destruktor" << endl;
}


Hund2::Hund2():knochen(0),anzahlKnochen(0) {
	cout << "Hund-Konstruktor" << endl;
}

Hund2::~Hund2() {
	cout << "Hund-Destruktor" << endl;
	delete[] knochen;
}