/*
 *  DateError.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 2
 */
 
 /* Es gibt mehrere Möglichkeiten die Fehlerklassen
  * für die Klasse Datum zu implementieren
  * dies ist nur ein Beispiel 
  */

#include "DateError.h"
#include <iostream>
using namespace std;

// DateError
DateError::DateError(int t, int m, int j) : tag(t), monat(m), jahr(j) {}

void DateError::meldung() const {
    cout << "FEHLER: Ungueltiges Datum (" << tag << "." << monat << "." << jahr << ")";
    if( monat == 2 && tag == 29 ) {
        cout << " " << jahr << " ist kein Schaltjahr!" << endl;
    }
}

// InvalidDayError    
InvalidDayError::InvalidDayError(int t, int m, int j) 
    : DateError(t,m,j) {}

void InvalidDayError::meldung() const {
    DateError::meldung();
    cout << " Der Tag ist ungueltig!" << endl;
}

// InvalidMonthError    
InvalidMonthError::InvalidMonthError(int t,int m, int j) : DateError(t,m,j) {} 

void InvalidMonthError::meldung() const {
    DateError::meldung();
    cout << " Der Monat ist ungueltig!" << endl;
}

// InvalidYearError    
InvalidYearError::InvalidYearError(int t,int m, int j) : DateError(t,m,j) {} 

void InvalidYearError::meldung() const {
    DateError::meldung();
    cout << " Das Jahr ist ungueltig!" << endl;
}
