/*
konstanten
static
header implementierungsdateien
*/
#include "header_implem.h"  // Headerdatei wird hier reinkopiert

//static fkt
static void staticFktTest()
{
	static int i = 0;
	++i;
	cout << i << endl;
}
/*static fkt == nur in der jeweilig stehenden datei SICHTBAR/NUTZBAR

*/
//--------

//static global == semi global
static int z = 100; 
//globale variable die nur in dieser datei sichtbar/aufrufbar ist wegen static
// globale static variable == semiglobal, da NUR in der datei sichtbar/aufrufbar
//globale variable ohne static == durch jede datei aufrufbar/sichtbar

/*static fkt
static void staticFktTest()
{
..
}
==> static fkt == die fkt ist NUR in dieser datei sichtbar
*/
int main()
{

	//konstanten 

	double const FAKTOR = 3; // ist nicht veränderbar nachträglich(schreibgeschützt aber lesbar), 
	/* wegen const wird wert wird immer benutzt, da FAKTOR im main() also lokal steht, dh bei weiteren
	operationen im main kann const FAKTOR benutzt werden ABER NICHT bei fkten! Da fkten IMMER außerhalb
	also über der main fkt stehen, müsste const FAKTOR auch global also außerhalb von main definiert 
	sein --> sonst fehler
	dh es gilt 
	const KONSTANTE ==> global definiert ==> dadurch von fkten nutzbar
	const KONSTANTE ==> im main definiert ==> NUR in main lokal bei operationen NUR nutzbar 
	*/
	cout << FAKTOR << endl;  // ausgabe: 3, weil lokale FAKTOR überdeckt globale FAKTOR
	// dh man kann eine variable mit gleichen namen lokal UND global definieren. der wert der lokalen
	//variablen überdeckt aber den wert der globalen

	double zahl;
	cin >> zahl;
	double const faktor = zahl ;  // dynamisch, da wert für zahl erst zur Laufzeit bestimmt werden kann
	cout << faktor << endl;
	// dynamisch const KONSTANTE ==> erst zur laufzeit bekannt durch eingabe von user, da const 
	//wert dazu schreibgeschützt macht aber lesbar.
	// statisch const KONSTANTE ==> vor laufzeit bereits wert bekannt, aber schreibgeschützt aber lesbar
	// wegen const
	//==> const KONSTANTE = kann dynamisch ODER statisch sein


	variable = 10; 
	/* warum geht das? 
	1)da in header datei - extern int variable; - deklariert wurde
	2) somit ist variable mit int deklariert und kann normal im main initalisiert werden
	 
	sinn von extern == variable in header datei bereits NUR deklarieren 
						==> somit ist in main die variable nutzbar bzw initialisierbar
	*/
	cout << variable << endl;


	//static
	staticFktTest(); // ausgabe : 1
	staticFktTest();// ausgabe : 2
	staticFktTest();// ausgabe : 3
	// warum wird beim erneuten aufruf von fkt anderer wert bestimmt? 
	//da der zuvor berechnete wert durch die fkt nicht verloren geht. somit wird mit dem 
	//vorherigen wert weiter gearbeitet--> wie bei rekursion
	//static == lässt zuvor bestimmten wert einer fkt überleben


}

