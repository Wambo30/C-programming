/*
 *  RangeError.h
 *  Programmieren IIb - Uebung 3, Aufgabe 4
 *
 */

#ifndef RANGEERROR_H
#define RANGEERROR_H

#include <stdexcept>
using namespace std;

class RangeError : public out_of_range {
public: 
	RangeError();
};

#endif // RANGEERROR_H
