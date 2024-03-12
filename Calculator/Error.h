/*
 *  Error.h
 *  Programmieren IIb - Uebung 3, Aufgabe 1
 *
 */

#ifndef ERROR_H
#define ERROR_H
#include <string>
using namespace std;

class Error {
public:
    Error(string op);
    virtual void meldeFehler() const;

protected:
    string ursache;
};

class NegativeNumberError : public Error {
public:
    NegativeNumberError(double d);
    virtual void meldeFehler() const;

private:
	double zahl;
};

class NullDivisionError : public Error {
public:
	NullDivisionError();
};

class NonpositiveNumberError : public Error {
public:
	NonpositiveNumberError(double d);
    virtual void meldeFehler() const;

private:
	double zahl;
};
#endif //ERROR_H
