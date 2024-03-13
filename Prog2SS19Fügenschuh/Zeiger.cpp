/*
zeiger.cpp: hiermit will ich mir zeiger und dessen sinn erklären
es fehlt noch:
i) zeigerathmetik
ii) this zeiger
iii) null zeiger
iv) zeiger bzgl array


*/


#include <iostream>
using namespace std;

int main() {

	int zahl = 100;
	int* zeiger = &zahl;
	cout <<"ausgabe speicheradresse von zahl: " <<zeiger << endl;

	*zeiger = 5;
	//int zeiger = 5;
	cout << "ausgabe *zeiger: " << *zeiger << endl; // ausgabe: 5
	cout << " ausgabe zahl was durch *zeiger veraendert wurde: " << zahl << endl; //ausgabe: 5
	cout << "ausgabe zeiger: " << zeiger << endl; // ausgabe: 0x939284 (adresse)
	//*zeiger = *this;
	//cout << *this << endl;




	system("pause");
	return 0;
}