#include <iostream>
#include <string>
using namespace std;
size_t pos2 = 0;

int main()
{
	/*************aufgabenblatt 25 prog2a  *********************************************************/

/* BEGINN komplett auskommentiert


	//aufgabe 2a

	string name = "Prog2";
	// gebe name und Lange aus
	cout << "inhalt von name: " << name << endl;
	cout<< "zeichenlaenge von name: " << name.size() << endl;
	//methode size steht IMMER hinter dem namen von variable syntax : <VariableName>.size()


//---------------------------------------------------------------------------------------------------
	//aufgabe 2b - variante 1 beste lösung 

	string wort = "zei chen ket te";
	//lösche alle leerzeichen

	for (size_t i = 0; i < wort.size(); ++i)
	{
		//if (wort[i] == ' ')
		if ( i = wort.find(' '))
		{
			wort.erase(i,1);	
	//verschiebung der indizes um 1 nach unten da sonst die indizes nach leerzeichen überspringt
	//ausgleich daher notwendig
		}
	}
	cout << "inhalt von wort: " << wort << endl;


	//ENDE variante 1

//---------------------------------------------------------------------------------------------------

	// aufg 2b variante 2 -- schlechter stil

	string wort = "zei chen ket te";
	//lösche alle leerzeichen
	for (size_t i = 0; i < wort.size(); ++i)
	{
		if (wort[i] == ' ')
		{
			wort.erase(i, 1);
			--i;	// SCHLECHTER STIL da sie in steuervorgang eingreift!
	//alles unter schleife== hauptvorgang; alles in schleifenkopf == steuervorgang
	//saubere trennung unbedingt notwending da sonst verwirrend!
		}
	}
	cout << "inhalt von wort: " << wort << endl;
	//ENDE variante 2

//---------------------------------------------------------------------------------------------------

	//aufg 2b variante 3 - unübersichtlicher code

	string wort = "zei chen ket te";
	size_t i = 0;	//initialisierung von laufvariable außerhalb von while schleifenkopf immer
	while (i < wort.size())	
		if (wort[i] == ' ')
			wort.erase(i, 1);   // impl. Inkr. durch Indexverschiebung
		else
			++i;                  // explizites Inkrement dh bei while steht das in der schliefe

	cout << "ausgabe variante 3: " << wort << endl;
//---------------------------------------------------------------------------------------------------


/*______________________________________________________________________________________________
//REGEL: umschreibung von for schleife in while schleife

CODE obda:
code als for schleife, steuervorgang ist im for schleifenkopf 

string wort = "zei chen ket te";
//lösche alle leerzeichen
for (size_t i = 0; i < wort.size(); ++i)
{
if (wort[i] == ' ')
{
wort.erase(i,1);
//verschiebung der indizes um 1 nach unten da sonst die indizes nach leerzeichen überspringt
//ausgleich daher notwendig
}
}
cout << "inhalt von wort: " << wort << endl;

//aufg 2b variante 3 - unübersichtlicher code

code von for schleife als while schleife
1)laufvariable beim durcharbeiten der zeichen wird außerhalb des whileschleifen kopf initialisiert
2)bedinung bzgl der laufvariable steht im while schleifen kopf
3)inkrement/dekrement steht in der while schleife selber

string wort = "zei chen ket te";
size_t i = 0;
while (i < wort.size())
	if (wort[i] == ' ')
		wort.erase(i, 1);   // impl. Inkr. durch Indexverschiebung
	else
		++i;                  // explizites Inkremen

cout << "ausgabe variante 3: " << wort << endl;
___________________________________________________________________________________________________*/

//---------------------------------------------------------------------------------------------------

/*
	//aufgabe 2b variante 4 - string methoden direkt nutzen
string wort = "zei chen ket te";
	for (size_t i = wort.find(' ');      // suche erstes Leerzeichen
		i != string::npos;	//gilt solange nicht i letzten eintrag in string erreicht hat
		i = wort.find(' ',i))   // i = ' ' gefunden , dann tue das unter schleife sonst mach ++i
		wort.erase(i, 1);	// an stelle i eintrag löschen und --i machen

	cout << "ausgabe variante 4: " << wort << endl;

*/

//---------------------------------------------------------------------------------------------------

/*__________________________________________________________________________________________________

REGEL: unterschied zwischen erase und find bei paarklammer anweisung

bezug auf aufg 2b variante 4:

wort.erase(i,1) == an der stelle i wird eintrag gelöscht UND i um 1 verringert um die stelle nach i
nicht zu überspringen. warum? da durchs löschen die indize zählung beeinflusst wird

i = wort.find(' ',i) == wenn an stelle i ein ' ' (leerzeichen) existiert, dann tue das ind der for 
schleife ansonsten zähle i um 1 weiter
dh im übertragenen sinne 
i = wort.find(' ',i) ==> wenn i = ' ' existiert, tue befehle in for schleife ansonsten mach ++i

==> dh zusammengefasst

wort.erase(i,1) ==> --i und eintrag in i wird gelöscht
i = wort.find(' ',i) ==> wenn i = ' ' existiert, tue befehle in for schleife ansonsten mach ++i
i = wort.find(' ') ==> wenn i = ' ' existiert, tue befehle in for schleife ansonsten mach ++i

==> dh wort.find() macht per definition immer ++i egal was er noch suchen soll. man muss also nicht
zwei parameter angeben damit er inkrementiert
__________________________________________________________________________________________________

REGEL: bedeutung von string::npos

string::npos == bis zum ende des angegebenen strings

i != string::npos ==> in bedingung von for schleife benutzt, bedeutet = falls i (laufvariable) das
ende des strings nicht erreicht hat tue jenes in der for schleife...

- man kann das aber so nicht einfach benutzen da laufzeitfehler entsteht--> geht nur im zusammenhang
mit variante 4 also for schleife mit
__________________________________________________________________________________________________
*/

//---------------------------------------------------------------------------------------------------
/*
//aufg 2c)

string satz = "Ein Test-Satz Ein";
string wort = "Ein";	//find == unterscheidet zwischen groß und kleinbuchstaben und achtet genau drauf
//dh bei wort= "EIN" oder wort="ein "würde wort in satz nicht gefunden werden
	
// finde und ersetze wort in satz

	size_t pos = satz.find(wort);	// finde inhalt von wort also "Ein"
//find sucht string auf jeden eintrag EINMALIG alleine ab --> NICHT wie for schleife!
//denn sobald er wort einmal gefunden hat, hört er auf mit suchen und bricht ab
//dh falls wort="Ein" mehrmals in satz vorkommt kann es nur EINMAL ersetzt werden

	if (pos != string::npos)	//geh rein wenn nicht ende von string erreicht ist
	
		satz.replace(pos, wort.size(), "der");	//replace hat 3 hinreichende parameter

cout << "ausgabe von satz variante1: " << satz <<endl;


//Ausgabe: wenn compiler "Ein" einmal findet dann ersetzt er es mit "der" ABER wenn "Ein" nochmal
//in satz vorkommt dann passiert garnichts dh danach sucht der compiler nicht weiter wenn er "Ein"
//bereits einmal gefunden hat

*/
//---------------------------------------------------------------------------------------------------

/*___________________________________________________________________________________________________
REGEL: eigenschaften von <variableName>.replace(size_t i, size_t n, string)

- 3 parameter hinreichend

parameter 1)size_t i == laufvariable also eintrags/index stelle im string
parameter 2)size_t n == zeichengröße von jenem string welches diese stelle ersetzt also hier wort.size()
parameter 3)string	== jener string der diese stelle ersetzt

bsp.: siehe code bzgl aufg 2c)
__________________________________________________________________________________________________*/



//---------------------------------------------------------------------------------------------------

/*
// aufg 2c variante 2

//wenn in satz mehrmals "Ein" vorkommt so soll das immer mit "der" ersetzt werden

string satz2 = "Ein Test-Satz Ein";
string wort2 = "Ein";	//find == unterscheidet zwischen groß und kleinbuchstaben und achtet genau drauf
						//dh bei wort= "EIN" oder wort="ein "würde wort in satz nicht gefunden werden
// finde und ersetze wort in satz
//size_t pos2 = 0;
for (size_t pos2 = 0; pos2 < satz2.size(); ++pos2)
									
if (pos2 = satz2.find(wort2,1))
	satz2.replace(pos2, wort2.size(), "der");	//replace hat 3 hinreichende parameter

cout << "ausgabe satz2 also variante2: " << satz2 << endl;

*/
//---------------------------------------------------------------------------------------------------

//aufg 2d)

int zahl = 9876;
// wandle Zahl in Ziffernfolge um
string folge;
for (; zahl > 0; zahl /= 10)
folge = char('0' + zahl % 10 ) + folge;

cout << "ausgabe von folge: " << folge << endl;


//---------------------------------------------------------------------------------------------------




	return 0;
}
