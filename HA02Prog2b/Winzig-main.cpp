/*
Autoren:
Wahid Far, Okhtay 870485
Bieber, Okan 874666

*  Winzig-Main.cpp
*/

#include "Fehler.h"
#include "Winzig.h"

const int Winzig::OBERGRENZE = 100;
const int Winzig::UNTERGRENZE = -100;
///*
int main() {
	
	// mindestens 5 Versuche um alle Fehler zu pruefen
	for (int i = 1; i <= 5; i++) {
		cout << i << ". Versuch" << endl;
		try {
			Winzig a, b, d(11);
			cin >> a;
			cin >> b;

			cout << a << " + " << b << " = " << (a + b) << endl;
			cout << a << " - " << b << " = " << (a - b) << endl;
			cout << a << " * " << d << " = " << (a*d) << endl;
			cout << a << " / " << b << " = " << (a / b) << endl; // Achtung: Ganzzahldivision
		}
		catch (const Fehler& f) {
			f.melden();
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
//*/