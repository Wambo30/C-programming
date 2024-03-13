/*
*  FractionError.h
*  Programmieren IIb - Uebung 3, Aufgabe 3
*
*/

#ifndef FractionError_H
#define FractionError_H

#include <exception>
using namespace std;


class NullDivisionError : public exception {
public:
	NullDivisionError();
	virtual const char* what() const throw();
};


class NullDenominatorError : public exception {
public:
	NullDenominatorError();
	virtual const char* what() const throw();
};

#endif // ERROR_H
