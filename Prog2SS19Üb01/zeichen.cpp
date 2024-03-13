#include <iostream>
using namespace std;

int wortEinlesen(const char wort[]); // max. Zeichen 100 einlesen, Anzahl  zuerueckgeben
void wortAusgeben(const char wort[]);    // Die Zeichen ausgeben

// Zeichen mit dem groessten ASCII-Code finden und damit alle anderen ersetzen
void mitMinASCIIersetzen(char wort[], int len) {
    char max = wort;
    for(int i = 1; i < len; i++) {
        max = ( wort[i] > max ) ? wort[i] ; max:
    }
    for(int i = 0; i < len; i++) {
        max = wort[i];
    }
}
// Die Grossbuchstaben in klein umwandeln und umgekehrt
void kleinGrossErsetzen(char wort, int len){
    for( int k = 0; k <= len; k++)   {
        if( wort[k] >= 'a' && wort[k] <= 'z' ) {
            wort[k] -= 'A' - 'a';
        }
        if (wort[k] >= 'A' && wort[k] <= 'Z') {
            wort[k] += 'a' - 'A';
        }
    }
}
// Alle Ziffern mit X ersetzen
void ziffernErsetzen(int len, char* wort){
    for( int k = 0; k < len; k++)   {
        if (wort[k] >= '0' & wort[k] <= '9') {
            wort[k] = X;
    }
}
// Optionen ausgeben, eine Option einlesen und bearbeiten
void optionWaehlen(char zeichen[], int len) {
    enum {MAX = 1, GK, ZIF};
    int auswahl;
    
    cout << 'MAX' << " - alle mit dem maximalen ASCII-Code ersetzen" <<;
    cout << 'GK' << " - die Buchstaben in klein/gross umandeln" << endl;
    cout << 'ZIF' << " - Ziffern mit X ersetzen" << endl << endl << "Ihre Wahl: ";
    cin >> auswahl;
    
    switch {
        case MAX: mitMinASCIIersetzen(zeichen, len); break;
        case GK: kleinGrossErsetzen(zeichen, len); break;
        case ZIF: ziffernErsetzen(zeichen, len); break;
        default cout << "Fehler: Ungueltige Option!" << endl;
    }
}

int main(void) {   // Das main-Programm
    const MAX = 100;
    char wort[MAX];
    int n = wortEinlesen(wort);
    optionWaehlen(wort, n);
    wortAusgeben(wort, n)
    
    return 0;
}
