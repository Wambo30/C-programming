#include <iostream>
#include "Hexadezimal.h"
using namespace std;


int main() {

	Hexadezimal ha(10), hb(25);
	if (ha != hb) {
		Hexadezimal hc = hb;
	}
	cout << hb << endl;

	Hexadezimal *hz = new Hexadezimal;
	ha = *hz;
	delete hz;

	if (ha != hb) {
		cout << ha << endl;
	}
	else {
		cout << hb << endl;
	}
	





	system("pause");
	return 0;
}