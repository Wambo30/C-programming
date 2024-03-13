#include <iostream>
using namespace std;


// Ende-Zeichen für Ziffernfolge im natuerlich-Format
extern int const ENDE;


// max. Anzahl Ziffern in der Textausgabe (Annahme!)
extern int const MAX_TEXT;


// gib die Anzahl signifikanter Ziffern von zahl zurück
static int laenge ( int const zahl[] );

// wandle Text in eine dynamische neue natuerlich-Zahl um
int* zuZahl ( char const text[] );

// wandle Zahl in einen statischen Text um
// Achtung: der Wert ist nur stabil bis zum nächsten Aufruf
char const* zuText ( int const zahl[] );

// addiere zahl1 + zahl2 zu einer dynamischen neuen natuerlich-Zahl
int* addiere ( int const zahl1[], int const zahl2[] );


// berechne die n. Fibonacci-Zahl als dynamische neue natuerlich-Zahl
int* fibonacci ( int n );

