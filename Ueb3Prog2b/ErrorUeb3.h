/*
*  Error.h
*  Programmieren IIb - Uebung 3, Aufgabe 1
*
*/

#ifndef ERRORUeb3_H
#define ERRORUeb3_H
#include <string>
using namespace std;

class ErrorUeb3 {
public:
	ErrorUeb3(string op);
	virtual void meldeFehler() const;

protected:
	string ursache;
};

class NegativeNumberError : public ErrorUeb3 {
public:
	NegativeNumberError(double d);
	virtual void meldeFehler() const;

private:
	double zahl;
};

class NullDivisionError : public ErrorUeb3 {
public:
	NullDivisionError();
};

class NonpositiveNumberError : public ErrorUeb3 {
public:
	NonpositiveNumberError(double d);
	virtual void meldeFehler() const;

private:
	double zahl;
};
#endif //ERROR_H
