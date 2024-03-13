#ifndef ZaehlerStatisch_h
#define ZaehlerStatisch_h
#include <iostream>
using namespace std;

class ZaehlerStatisch
{
public:
	ZaehlerStatisch();
	~ZaehlerStatisch();
	static int getAnzahl(); // stat. methode

private:
	static int Anzahl;
	// stat. attribut welches in main erst initialisiert wird
};
#endif

