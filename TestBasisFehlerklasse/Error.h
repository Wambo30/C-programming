/*
Error == basisfehlerklasse
*/

#ifndef Error_h
#define Error_h

#include <string>
#include <iostream>
using namespace std;

class Error
{
public:
	Error(string );
	virtual ~Error();
	virtual void meldeFehler() const;
protected:
	string ursache;

};

class NegativeZahlFehler : public Error
{
public:
	NegativeZahlFehler(double);
	virtual ~NegativeZahlFehler();

};

class NullDivisionFehler : public Error {
public:
	NullDivisionFehler(double);
	virtual	~NullDivisionFehler();

};

/*
class TestCalculator: public Error {

	double wurzel(double d) throw(NegativeZahlFehler);
	double kehrwert(double d) throw (NullDivisionFehler);

};
*/


#endif