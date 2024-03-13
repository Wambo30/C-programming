/*
*  FractionError.h
*  Programmieren IIb - Uebung 3, Aufgabe 3
*
*/

#ifndef FRACTIONERROR_H
#define FRACTIONERROR_H

#include <exception>
using namespace std;


class NullDivisionError : public exception {
public:
	virtual const char* what() const throw();
};


class NullDenominatorError : public exception {
public:
	virtual const char* what() const throw();
};

#endif // ERROR_H
