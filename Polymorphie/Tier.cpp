#include "Tier.h"
#include <iostream>
using namespace std;


void Tier::essen() const {
	cout << "Tier: Futter" << endl;
}

void Hund::essen() const {
	cout << "Hund: Knochen" << endl;
}
void Katze::essen() const {
	cout << "Katze: Milch" << endl;
}

void Tiger::essen() const {
	cout << "Tiger: Fleisch" << endl;
}

void Tierarzt::diaetAnordnen(Tier t)  {
	t.essen();
}