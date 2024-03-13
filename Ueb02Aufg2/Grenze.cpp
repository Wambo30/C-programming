/*
*  Grenze.cpp
*  ProgIIb-Projekt3
*/

#include "Grenze.h"
#include <float.h> // wegen DBL_MAX
using namespace std;

const double INF = DBL_MAX;

Grenze::Grenze() : wert(INF), klammer('('), in(false) {}

Grenze::Grenze(double d, char z, bool b)
	: wert(d), klammer(z), in(b) {}

void Grenze::set(const Grenze& g) {
	wert = g.wert;
	klammer = g.klammer;
	in = g.in;
}

double Grenze::getWert()  const { return wert; }
char Grenze::getKlammer() const { return klammer; }
bool Grenze::istIn() const { return in; }

void Grenze::setWert(double d) { wert = d; }
void Grenze::setKlammer(char k) { klammer = k; }
void Grenze::setIn(bool b) { in = b; }


bool Grenze::operator<(const Grenze& g) const {
	if (wert < g.wert) {
		return true;
	}
	if (wert == g.wert) {
		switch (klammer) {
		case '[': if (g.klammer == '(' || g.klammer == '{') return true;
		case '{':
		case ']': if (g.klammer == '(') return true;
		case '}': if (g.klammer == '(' || g.klammer == ']') return true;
		}
		if (klammer == ')' && g.klammer != ')') {
			return true;
		}
	}
	return false;
}

bool Grenze::operator==(const Grenze& g) const {
	return (wert == g.wert && klammer == g.klammer && in == g.in);
}

ostream& operator<<(ostream& aus, const Grenze& g) {
	aus << g.getKlammer();
	return aus;
}