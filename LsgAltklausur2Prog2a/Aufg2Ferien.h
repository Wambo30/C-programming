#ifndef Aufg2Ferien_H
#define Aufg2Ferien_H

#include "Aufg2Datum.h"
#include <iostream>
using namespace std;

class Aufg2Ferien
{
public:
	Aufg2Ferien();
	Aufg2Ferien(const Aufg2Datum& d, int n);
	Aufg2Ferien(const Aufg2Ferien&); // kopierkonstruktor
	~Aufg2Ferien();

	Aufg2Ferien& operator= (const Aufg2Ferien&); // zuweisungsoperator
	
	//getter
	int getAnzahlTage() const;
	Aufg2Datum getFerienTag(const Aufg2Datum&) const;
	void verschieben(int);


private:
	int anzahlTage;
	int*  freieTage;

};
#endif
