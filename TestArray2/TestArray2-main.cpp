#include <iostream>
using namespace std;


int main() {

	///*
	// test 1 : angabe der größe und zuweisung der array stellen durch werte
	int vec[3]; // stellen beginnen bei 0 dh es gibt 0,1,2 stellen--> die 3. ex NICHT!
	// wenn man aber vec[3] initialiisert == fehler !

	vec[0] = 9;
	vec[1] = 4;
	vec[2] = 6;
	//vec[3] = 99;
	//vec[4] = 100;

	for (int i = 0; i < 10; i++) {
	cout << vec[i] << endl;

	}
	//*/

	// test 2 - eingabe von wert in die stellen des arrays durch user
	/*
	cout << endl;
	float vec2[10]; // für vec2 array werden 10 stellen reserviert
	for (int i = 0; i < 10; i++) {
		cout << "Bitte einen Wert eingeben : ";
		cin >> vec2[i];
	}

	*/

	//test 3 - direkte initialisierung von stat array OHNE angabe von größe
	cout << endl;
	char buchstaben[] = {'d','b','c' };

	for (int i = 0; i < 3; i++) {
		cout << buchstaben[i] << endl;
	}
	// ausgabe: d b c


	// test 4 - direkte initial. von array MIT angabe von größe
	cout << endl;

	char buchstaben2[5] = { 'd','b','c' };
	for (int i = 0; i < 5; i++) {
		cout << buchstaben2[i] << endl;
	}


	system("pause");
	return 0;
}