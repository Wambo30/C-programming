#include <iostream>
using namespace std;

int const zahl = 5;
/*
________________________________________________________________________________________________________
**regel konstanten/const: - globale konstanten nach typ <datentyp> const <VarName> = <Wert>;
sind in jedem block sichtbar/lesbar aber nicht beschreibbar/ver�nderbar.
- wird die globale konstante mit dem selben namen in einem block/fkt mit anderem wert initialisiert,
so �berschreibt der wert der block konstante den wert der globalen konstante, aber nur in diesem 
block der block konstante!
- konstanten verhindern ein beschreiben des wertes einer variablen/array im nachhinein.dh jener wert
der zuerst initialisiert wurde kann nicht nachtr�glich ver�ndert werden. bei jedem durchlauf der fkt
wird nur mit diesem zur konstanten initialisierten wert gearbeitet!
-----------------------------------------------------------------------------------------------------

 bsp:
 #include <iostream>
 using namespace std;

 int const zahl = 5;	// globale konstante

 void funktion()
 {
 int const zahl = 6;	// blockkonstante, wert 6 �berdeckt in diesem block den wert 5 der gl. konst.
 cout << zahl << endl;
 }

 int main ( int narg , char* argv[] )
 {
 funktion();
 cout << zahl << endl;
 }

_________________________________________________________________________________________________________
*/


void funktion()
{

}

int main(int narg, char* argv[])
{
	return 0;
}