#include "NullDivisorError.h"
#include "NegativNumberError.h"
#include <iostream>
using namespace std;

NullDivisorError::NullDivisorError(double) {


}

//~NegativNumberError();

void NullDivisorError::meldeFehler() const {
	cout << "Fehler: division durch null";

}