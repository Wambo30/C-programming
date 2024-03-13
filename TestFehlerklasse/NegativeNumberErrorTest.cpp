#include "NegativeNumberErrorTest.h"
#include <iostream>
using namespace std;



NegativeNumberErrorTest::NegativeNumberErrorTest(double d):  wert(d){}

void NegativeNumberErrorTest::meldeFehler() const {
	cout << "FEHLER: Negative Zahl " << wert << endl;
}