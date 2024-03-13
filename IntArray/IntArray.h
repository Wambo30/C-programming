//
//  IntArray.h
//  prog2A-SU
//

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cstddef>
using namespace std;

class IntArray {
public:
	// Standardkonstruktor
	IntArray();
	
	// Mit n mal Wert a
	IntArray(int, int);
	
	// Kopierkostruktor
	IntArray(const IntArray&);
	
	// Zuweisungsoperator
	IntArray& operator=(const IntArray&);

	int& operator[](size_t);  // array[i]

	~IntArray();

private:
	size_t laenge;
	int* array;
};
#endif /* INTARRAY_H */
