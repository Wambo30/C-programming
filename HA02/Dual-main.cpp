/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666
*/

/* Dual-main.cpp */

#include "Dual.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	char antwort;
	do {

		// Addieren von 2 Zahlen und umgewandelt in eine Dualzahl
		cout << "Addition von 2 Zahlen:" << endl;
		Dual d1(7);
		Dual d2(9);
		Dual d3;

		d3 = d1 + d2;
		d1 += d2;

		cout << "d1 + d2 = " << d3.toString() << " als Dualzahl und als Dezimalzahl " << d3.toDezimal() << endl;
		cout << "Aus d1 += d2 folgt " << d1.toString() << " als Dualzahl und als Dezimalzahl " << d1.toDezimal() << endl;

		cout << endl;
		//Multiplikation von 2 Zahlen und umgewandelt in eine Dualzahl
		cout << endl << "Multiplikation von 2 Zahlen:" << endl;

		Dual d4(8);
		Dual d5(2);
		Dual d6;

		d6 = d4 * d5;
		d4 *= d5;

		cout << "d4 * d5 = " << d6.toString() << " als Dualzahl und als Dezimalzahl " << d6.toDezimal() << endl;
		cout << "Aus d4 *= d5 folgt " << d4.toString() << " als Dualzahl und als Dezimalzahl " << d4.toDezimal() << endl;


		cout << "gib eine Dezimalzahl an, die > 0 ist:";
		size_t dezimal;
		cin >> dezimal;
		cout << "Die Dezimalzahl: " << dezimal << " ist als Dualzahl: ";

		Dual d(dezimal);
		d.ausgeben();

		cout << endl << "Test der toDezimal Funktion:" << endl;
		d.toDezimal();
		cout << "dezimal ist: " << d.toDezimal() << endl;

		cout << "Nochmal? (j/n)";
		cin >> antwort;
	} while (antwort == 'j');

	return 0;

}
