#ifndef AUFG2DATUM_H
#define AUFG2DATUM_H
#include <iostream>

class Aufg2Datum
{
public:
	Aufg2Datum();
	~Aufg2Datum();

//setter und getter
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	int getTag() const;
	int getMonat() const;
	int getJahr() const;

	bool istGueltig()const;
	bool istSchaltjahr() const;

// andere methoden
	void verschieben(int v);

private:
	int tag, monat, jahr;



};

#endif 