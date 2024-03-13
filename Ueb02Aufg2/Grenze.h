/*
*  Grenze.h
*  Programieren 2B - Uebungsblatt 2, 2. Uebung
*/

#ifndef GRENZE_H
#define GRENZE_H

#include <iostream>
using namespace std;

class Grenze {
public:
	Grenze();
	Grenze(double d, char z, bool in);

	void set(const Grenze& G);

	double getWert() const;
	char getKlammer() const;
	bool istIn() const;

	void setWert(double d);
	void setKlammer(char k);
	void setIn(bool b);

	bool operator<(const Grenze& g) const;
	bool operator==(const Grenze& g) const;

private:
	double wert;
	char klammer;
	bool in;
};

ostream& operator<<(ostream& aus, const Grenze& g);

#endif // GRENZE_H
