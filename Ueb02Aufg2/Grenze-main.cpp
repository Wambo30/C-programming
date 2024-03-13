#include <iostream>
#include "Grenze.h"
#include "Intervall.h"
using namespace std;

int main() {

	Grenze g1(2 ,')', false );

	cout << g1.istIn() << endl;
	cout << g1.getKlammer() << endl;
	cout << g1.getWert() << endl;

	Grenze g2(4,')',false);
	Grenze g3(3, ')', false );
	cout << g2.getWert() << endl;




	system("pause");
	return 0;
}