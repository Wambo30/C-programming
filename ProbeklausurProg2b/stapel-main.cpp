
/* Stapel-main.cpp */
#include "Stapel.h"


int main() {
	Stapel<double> s;

	try{
		for (int i = 0; i < 3; i++) {
			s.fuegeHinzu(i*0.01 - 1);
		}
		cout << s.getVonOben() << endl;

		s.entferne();
		s.fuegeHinzu(s.getVonOben() );
		cout << s << endl;

		for (int i = 0; i < 3; i++) {
			s.entferne();
		}

		if (s.istLeer())
			cout << " Stack ist leer!" << endl;
		cout << s.getVonOben() << endl;
	}

	catch (exception& er) {
		cout <<	er.what() << endl;
	}






	return 0;
}
