/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666

* Winzig.h
* Ausnahmebehandlung beim BereichsUeberschreiten
*/


#ifndef WINZIG_H
#define WINZIG_H

#include "Fehler.h"
#include <iostream>
using namespace std;

class Winzig {
public:
	static int const UNTERGRENZE;
	static int const OBERGRENZE;

	Winzig();
	~Winzig();
	Winzig(int w);

	int getWert() const;
	void setWert(int w);
	const Winzig operator+ (const Winzig&) const;
	const Winzig operator- (const Winzig&) const;
	const Winzig operator* (const Winzig&) const;
	const Winzig operator/ (const Winzig&) const;

private:
	int wert;
	void ueberpruefen(char op);
};

ostream& operator<<(ostream& aus, const Winzig& t);
istream& operator >> (istream& ein, Winzig& t);

#endif // WINZIG_H
