#include "ZaehlerStatisch.h"



ZaehlerStatisch::ZaehlerStatisch() { Anzahl++; }

ZaehlerStatisch::~ZaehlerStatisch() { Anzahl--; }

int ZaehlerStatisch::getAnzahl() {
	return Anzahl;
}
