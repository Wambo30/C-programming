
#include <iostream>
using namespace std;
#include "Polynom2.h"



int main(void) {
	Polynom2 p1(3, 1.), p2(1, -0.2);
	Polynom2 p3 = p2; // == p3(2) ==> ist dasselbe, hier wird kopierkonstruktor genutzt
	//kopierkonstruktor== er kopiert die adressen

	cout <<"p1: " <<p1.toString() << endl;
	cout <<"p2: " <<p2.toString() << endl;

	cout <<"p3: " <<p3.toString() << endl;
	p2 = p1;
	
	cout <<"p2=p1: " <<p2.toString() << endl;

	p3.setKoeffizienten(7, 0);

	//cout << "ausgabe p3: " << p3.setKoeffizienten() << endl;
	cout << <<p3.wertBerechnen(1.) << endl;
	//cout << p3.wertBerechnen(1.) << endl;

	p1.multipliziere(p2);
	//p1 = p1*p2 und p1 *=p2 --> dh p2 wird nicht verändert

	system("pause");
	return 0;
}
