//  Array.cpp

#include "Array.h"
#include <iostream>
using namespace std;

// Standardkonstruktor
template <typename T>
Array<T>::Array() : laenge(1) {
	elemente = new T[laenge];
	elemente[0] = 0;
}

// Mit n mal Wert a
template <typename T>
Array<T>::Array(int n, const T& a) : laenge(n) {
	elemente = new T[laenge];
	for (size_t i = 0; i < laenge; i++)
		elemente[i] = a;
}

//Kopierkonstruktor
template <typename T>
Array<T>::Array(const Array<T>& ia) : laenge(ia.laenge) {
	elemente = new T[laenge];
	for (size_t i = 0; i < laenge; i++) {
		elemente[i] = ia.elemente[i];
	}
}

//Zuweisungsoperator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& ia) {
	if (elemente) delete[] elemente;
	elemente = new T[ia.laenge];
	for (size_t i = 0; i < ia.laenge; i++) {
		elemente[i] = ia.elemente[i];
	}
	laenge = ia.laenge;
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (elemente) delete[] elemente;
}

// Ruckgabetyp ist die Referenz auf ein array-Element,
// damit ein array-Element auf der linken Seite der Zuweisung stehen kann
template <typename T>
T& Array<T>::operator[](size_t i) {
	if (i < 0 || i >= laenge) {
		cout << "FEHLER: Ungueliger Index!" << endl;
	}
	return elemente[i];
}

