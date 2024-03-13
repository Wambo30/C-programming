/* Intervall-Main.cpp
*  Programieren 2B - Uebungsblatt 2, 2. Uebung
*/

#include "Intervall.h"
#include <iostream>
using namespace std;

int main(int argc, char * const argv[]) {
	OIntervall oi1(-2, 1), oi2(-3, -1.5);
	AIntervall ai1(-2, 1), ai2(-3, -1.5);
	LOIntervall loi1(-2, 1), loi2(-3, -1.5);
	ROIntervall roi1(-2, 1), roi2(-3, -1.5);
	AIntervall z1(-2), z2(-1), z3(2);

	Intervall* elem[] = { &oi1, &ai1, &loi1, &roi1,
		&oi2, &ai2, &loi2, &roi2,
		&z1, &z2, &z3 };

	for (int i = 0; i < 11; i++) {
		cout << *(elem[i]) << " : " << endl;

		if (elem[i]->enthaelt(0)) {
			cout << "\tenthaelt 0" << endl;
		}

		for (int j = 0; j < 11; j++) {
			if (elem[i]->istTeilmengeVon(*(elem[j]))) {
				cout << "\tist Teilmenge von " << *(elem[j]) << endl;
			}
			if (elem[i]->istEchteTeilmengeVon(*(elem[j]))) {
				cout << "\tist echte Teilmenge von " << *(elem[j]) << endl;
			}
			if (elem[i]->istGleich(*(elem[j]))) {
				cout << "\t= " << *(elem[j]) << endl;
			}
		}
	}

	return 0;
}
