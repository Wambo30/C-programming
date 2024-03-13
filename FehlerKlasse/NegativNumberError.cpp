#include "NegativNumberError.h"
#include <iostream>
using namespace std;


NegativNumberError::NegativNumberError( double w): wert(w)
{
}

/*
NegativNumberError::~NegativNumberError()
{
}
*/

void NegativNumberError::meldeFehler() const {
	cout << "Fehler: " << wert << "ist negativ" << endl;

}