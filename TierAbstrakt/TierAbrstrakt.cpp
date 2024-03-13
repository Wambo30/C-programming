#include "TierAbrstrakt.h"
#include <iostream>
using namespace std;

/*
void TierAbstrakt::essen() const {
	cout << "Tier:futter" << endl;

}
*/

void TierAbstrakt::ausgeben2()const {
	ausgeben();
}

void Hund3::essen() const {
	cout << "Hund:Knochen" << endl;

}

void Hund3::ausgeben()const {
	cout << "hund ausgabe" << endl;
}

/*********************************/

void Katze3::essen() const {
	cout << "Katze:Milch" << endl;

}

void Katze3::ausgeben()const {
	cout << "katze ausgabe" << endl;
}

/*********************************/
void Tiger3::essen() const {
	cout << "Tiger:Fleisch" << endl;

}

void Tiger3::ausgeben()const {
	cout << "tiger ausgabe" << endl;
}

/*********************************/
void Tierarzt3::diaetAnordnen3(TierAbstrakt& t) {
	t.essen();
}

void Tierarzt3::ausgeben()const {
	cout << "tierarzt ausgabe" << endl;
}