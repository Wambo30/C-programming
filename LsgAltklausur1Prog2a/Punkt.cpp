#include "Punkt.h"
#include <iostream>
using namespace std;


Punkt::Punkt():xKomp(0), yKomp(0){}

Punkt::~Punkt(){}

void Punkt::setX(double x) {
	xKomp = x;
}

void Punkt::setY(double y) {
	yKomp = y;
}

double Punkt::getX() const {
	return xKomp;
}

double Punkt::getY() const {
	return yKomp;
}

int Punkt::getEcke() const {
	return getX() && getY();
}

//andere methoden

void Punkt::verschieben(double x, double y) {
	xKomp += x;
	yKomp += y;
}
