#pragma once
#include <iostream>		/* Ein- und Ausgabe */
#include <cmath>        /* C-Bibliothek fuer die Wurzelfunktion sqrt() */

using namespace std;
const float EPS = 0.001;
enum verfahren { BIS = 1, NEWT, SQRT };


class Nullstelle
{
public:
	Nullstelle();
	~Nullstelle();
	double bisection(double links, double rechts, double a);
	double newton(double xAlt, double xNeu, double a);

};

