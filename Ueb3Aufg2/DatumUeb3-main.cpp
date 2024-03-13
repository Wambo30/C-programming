/*
*  Datum-Main.cpp
*  Programmieren IIb - Uebung 4, Aufgabe 2
*
*/

#include "DatumFehler.h"
#include "DatumUeb3.h"

#include <iostream>
using namespace std;


ostream& operator<<(ostream& aus, const DatumUeb3& d) {
	aus << d.getTag() << "." << d.getMonat() << "." << d.getJahr();
	return aus;
}



int main(void) {
	try {
		int t, m, j;
		cout << "Tag Monat Jahr: ";
		cin >> t >> m >> j;  // Werte fuer t, m und j nacheinader mit 
							 // Leerzeichen getrennt eingeben

		DatumUeb3 d(t, m, j);

		d.setTag(t + 20);
		cout << d << endl;

		d.setMonat(m + 9);
		cout << d << endl;

		d.setJahr(j - 30);
		cout << d << endl;

		d.setMorgen();
		cout << d << endl;
	}
	catch (DatumFehler& er) {
		er.meldung();
	}

	system("pause");
	return 0;
}















