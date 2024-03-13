#include <iostream>
#include "Punkt.h"
#include "Kreis.h"
#include <cmath>
using namespace std;



int main() {

	/*
	//testen 1 konstruktor
	Punkt p1;
	cout << "(" <<p1.getX() <<"," << p1.getY()<< ")"<< endl;

	p1.setX(2.7);
	cout << "(" << p1.getX() << "," << p1.getY() << ")" << endl;

	*/

	/*
	// testen 2.2 kontruktor wo man werte selbst setzt

	Punkt p2(1., 4.5);
	cout << "(" << p2.getX() << "," << p2.getY() << ")" << endl;
	*/

	/*
	// testen funktion verschieben

	Punkt p3(2, 6);
	p3.verschieben(-1, 4); // verschieben um werte
	cout << "(" << p3.getX() << "," << p3.getY() << ")" << endl;
	*/

	// testen spiegeln

	/*
	Punkt p4(2, 6);
	p4.spiegelnAnX();
	cout << "(" << p4.getX() << "," << p4.getY() << ")" << endl;
	*/

	/*
	// test kreis ausgabe
	Kreis z;
	z.ausgeben();
	*/

	// test ausgeben von get methode

	Kreis p;
	
	cout << p.getRadius() << endl;

	system("pause");
	return 0;
}