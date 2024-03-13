#ifndef TestStandardFehlerklasse_h
#define TestStandardFehlerklasse_h
#include <iostream>
#include <exception>
using namespace std;


class FehlerNegativeZahl :public exception {
public:
	FehlerNegativeZahl(double d);
	virtual const char* what() const throw();
private:
	char meldung[100];
};

class FehlerNullDivision : public exception {
	public:
		//FehlerNullDivision(double d);
		virtual const char* what() const throw();
};

class Berechnungsklasse {
public:
	double wurzel(double d) throw (FehlerNegativeZahl);
	double kehrwert(double d) throw (FehlerNullDivision);


};



#endif

