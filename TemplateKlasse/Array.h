//
//  Array.h
//  prog2b-SU
//

#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
using namespace std;

template <typename T =int>
class Array {
public:
	// Standardkonstruktor
	Array();
	// Mit n mal Wert a
	Array(size_t, const T&);
	// Kopierkostruktor
	Array(const Array<T>&);
	// Zuweisungsoperator
	Array<T>& operator=(const Array<T>&);

	T& operator[](size_t);  // elemente[i]

	~Array();


private:
	size_t laenge;
	T* array;
};
#endif /* ARRAY_H */

// Standardkonstruktor
template <typename T>
Array<T>::Array() : laenge(1) {
	elemente = new T[laenge];
	elemente[0] = 0;
}

// Mit n mal Wert a
template <typename T>
Array<T>::Array(size_t n, const T& a) : laenge(n) {
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