#include "TestMod.h"
#include <iostream>
using namespace std;


TestMod::TestMod()
{
}


TestMod::~TestMod()
{
}

void TestMod::ausgeben() const {
	
}

void TestMod::tuWas(int k) {
	if (k % 3) {
		cout << "rest ist ungerade bzw groeßer 0" << endl;
	}
	else {
		cout << "rest ist gerade bzw gleich 0" << endl;
	}
}