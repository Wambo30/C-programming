//  IntArray.cpp

#include "IntArray.h"
#include <iostream>
using namespace std;

// Standardkonstruktor
IntArray::IntArray() : laenge(1) {
	array = new int[laenge];
	array[0] = 0;
}

// Mit n mal Wert a
IntArray::IntArray(int n, int a) : laenge(n) {
	array = new int[laenge];
	for (size_t i = 0; i < laenge; i++)
		array[i] = a;
}

//Kopierkonstruktor
IntArray::IntArray(const IntArray& ia) : laenge(ia.laenge) {
	array = new int[laenge];
	for (size_t i = 0; i < laenge; i++) {
		array[i] = ia.array[i];
	}
}

//Zuweisungsoperator
IntArray& IntArray::operator=(const IntArray& ia) {
	if (array) delete[] array;
	array = new int[ia.laenge];
	for (size_t i = 0; i < ia.laenge; i++) {
		array[i] = ia.array[i];
	}
	laenge = ia.laenge;
	return *this;
}

IntArray::~IntArray() {
	if (array) delete[] array;
}

// Ruckgabetyp ist die Referenz auf ein array-Element,
// damit ein array-Element auf der linken Seite der Zuweisung stehen kann
int& IntArray::operator[](size_t i) {
	if (i < 0 || i >= laenge) {
		cout << "FEHLER: Ungueliger Index!" << endl;
	}
	return array[i];
}

