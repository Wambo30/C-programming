/*
SKRIPT aus 1b bzgl array
zeiger steht in extra datei


*/
#include "ArrayZeigerFkt.h"

void gibAus(char const nameArray[], double const vec[], int LAENGEvec)
{
	cout << nameArray << "[] = [ " ;
	for (int i = 0; i < LAENGEvec; ++i)
		cout << vec[i] << " ";
	cout << "]" << endl;
}

// weise von[] der L�ange nvec zu an nach[]
void weiseZu(double nach[], double von[], int nvec)
{
	for (int i = 0; i < nvec; ++i)
		nach[i] = von[i];
}

// rechne vec = matrix * vec
void multipliziere(double* const matrix[], double vec[], int dim)
{
	// tempor�ares Array f�ur Ergebnis
	double* produkt = new double[dim];
	// rechne produkt = matrix * vec
	for (int i = 0; i < dim; ++i)
	{
		produkt[i] = 0;
		for (int j = 0; j < dim; ++j)
			produkt[i] += matrix[i][j] * vec[j];
	}
	// kopiere produkt[] nach vec[] zur�uck
	for (int i = 0; i < dim; ++i)
		vec[i] = produkt[i];
	// gebe Array wieder frei
	delete[] produkt;
} // multipliziere()



int main()
{
/*************************************************************************************************************
REGEL: sinn von array 

- viele gleichartige variablen zusammenfassen
- den raum R3 wollen wir in einem speicherbereich zusammen fassen also r=[x,y,z]
dh wir wollen die variablen nicht einzelnd betrachten sondern in einem zusammengeh�rigen speicherbereich MIT
i) einem index, um jede variable einzelnd abzufragen
ii) und einen namen f�r die zusammenfassung also f�r das array

syntax array: <Datentyp> <NameArray> [<L�nge>];

- datentyp == ist gemeinsamer datentyp aller variablen/eintr�ge in diesem array
- NameArray == gemeinsamer name des arrays aller variablen/eintr�ge in diesem array
- L�nge == wird durch ganzahligen wert festgelegt, dh wieviele eintr�ge das array haben soll/darf

bsp obda:

double vec [3];

was passiert hier?
1) es wird im speicher drei pl�tze f�r das array reserviert
2) alle jeder dieser reservierten 3 pl�tze ist 32 bit gro� da double 32 bit gro� dh jeder platz ist f�r
ein double reserviert
==> man teilt also auf in

deklaration von array == w�hrend compilzeit wird gesagt das jeder eintrag im array double datentyp hat
definition von array == zur laufzeit wird die l�nge des arrays im speicher reserviert

==> ABER eine initialisierung existiert noch nicht da die gespeicherten pl�tze noch leer sind. sie werden
vom compiler mit zuf�lligen werten ERSTMAL gef�llt


****************************************************************************************************************/

/***************************************************************************************************************
REGEL: definition von array

- l�nge von array ist ein ganzzahliger const wert
syntax: <Datentyp> <NameArray> [<L�nge>] ---> mit l�nge == const ganzzahlig

bsp obda:

1)
int const DIM1 = 3;
double Array1 [DIM];
--> ist korrekt, da l�nge als const definiert wurde!

2)
int dim2 = 4;
double Array2 [dim2]
-->syntax fehler 
da dim2 nicht als const deklariert wurde--> dadurch syntax fehler
UND: konstanten an sich IMMER mit gro�buchstaben geschrieben werden

==> dh korrekt w�re dann: int const DIM2 = 4;

3)
int dim;
int const DIM3 = dim ;      // dyn. Konstante
double vec3[ DIM3 ];    // Syntaxfehler!

--> warum syntaxfehler? da DIM3 IMMER einen konstanten ganzzahligen wert haben muss!!
dh sie darf keine dynamische konstante sein


****************************************************************************************************************/

/**************************************************************************************************************
REGEL: rechnen/kombinieren mit l�ngen von array

- man kann mit den konstanten von einer l�nge eines arrays arbeiten/rechnen usw

bsp obda:
1)

int DIM = 3;
int const LEN1 = DIM + 2 ;
int  array1  [ LEN1 ] ;
--> syntax fehler! warum?
Obwohl DIM einen konstanten wert hat also int DIM = 3 , MUSS es zus�tzlich noch als const definiert werden also
korrekt w�re es

int const DIM = 3;
int const LEN1 = DIM + 2 ;
int  array1  [ LEN1 ] ;
--> korrekt!

==> dh wenn man mit der l�nge von arrays rechnet M�SSEN beide komponenten als const deklariert sein ODER es ist
selber eine konstante zahl

2)
int const DIM;
int const LEN2 = 2 * DIM - 1 ;
int  array2  [ LEN2] ;

--> syntax fehler! warum? da DIM keinen konstanten ganzzahligen wert besitzt und es somit dynamisch ist
dh man muss DIM mit einem konstanten wert initialisieren

korrekt w�re es also so:

int const DIM = 5;
int const LEN2 = 2 * DIM - 1 ;
int  array2  [ LEN2] ;
--> korrekt!


3)
int const DIM =5;
int const LEN3 = DIM * DIM ;
int  array3  [LEN3] ;
--> korrekt!
i)da DIM als const deklariert wurde
ii) DIM wurde einem konstanten zahlenwert zugewiesen und somit initialisiert
iii)LEN3 also die tats�chliche l�nge ist auch mit const deklariert


4)

int const NABC = �z� - �a� + 1 ;
char alphabet[ NABC] ;
--> korrekt!warum?
- die variable f�r die l�nge wurde mit const deklariert ABER auch wenn ich f�r NABC es mit
char statt int deklariere---> trotzdem richtig obwohl das array char ist!!


===> sp�ter mal schauen womit das zu tun hat!!
==> merke:
1)wenn const kommt --> dann muss ein konstanter wert mit initialisiert werden
2)in l�nge d�rfen nur konstante werte stehen dh die variable die drin steht muss auch einem konstanten wert
zugewiesen worden sein
3) L�nge = l�nge -1 , da man die 0. stelle noch mitz�hlt!!!

************************************************************************************************************/

/************************************************************************************************************
REGEL: direkte initialisierung eines arrays

syntax: 
<DatenTyp> const <VariableL�ngeArray> = <konstGanzzahligerWert>;
<Datentyp> <NameArray> [<VariableL�ngeArray>] = {<Eintrag1>,<Eintrag2>,... }

bsp obda:

int const DIM = 5;	// datentyp von l�nge des arrays IMMER verschieden zum datentyp des arrays selber!
double vec [DIM] = {1,-1,2};
Merke:
1)DIREKTE initialisierung eines arrays erfolgt IMMER mit geschweiften klammern
2) datentyp von DIM also der l�nge MUSS IMMER verschieden zum datentyp des arrays sein---> sonst syntaxfehler!

datentyp array !== datentyp von l�nge des arrays !!!

**************************************************************************************************************/

/************************************************************************************************************
REGEL:ausgabe eines arrays

- ausgabe von array ==> gibt zuf�llige speicheradresse des arrays aus

bsp obda:
int const DIM = 5;	// datentyp bei DIM MUSS IMMER anders sein als das von array selber -->sonst syntaxfehler!
double vec [DIM] = {1,-1,2}; //  DIREKTE initialisierung eines arrays erfolgt IMMER mit geschweiften klammern
cout << "ausgabe vec array: "<< vec << endl;

ausgabe: 321324B	
//nach neu kompilieren �ndert sich immer die speicheradresse da sie immer zuf�llig gew�hlt wird
//dh 

==>
merke:
1)egal was ich in geschweiften klammern einfach eintrage, es kommt IMMER die speicheradresse von dem 
array bei ausgabe heraus WENN ich in der ausgabe NUR den array name eintrage!! 

2) implizite typumwandlung von int zu double--> warum? da man alle eintr�ge des arrays als double definiert hat 
ABER man int zahlen eingetragen hat daher implizite typumwandlung!

eintragen von arrayname in cout ==> ausgabe von speicheradresse des arrays EGAL was direkt zum array initialisert wurde

***************************************************************************************************************/

/**************************************************************************************************************
REGEL: ausgabe von eintr�gen aus array

- um elemente von array ausgeben zu k�nnen==> direktes ansprechen von eintr�gen in array
+ geschweifte klammern hinter array setzen + for schleife nutzen damit die eintr�ge alle hintereinander 
weg ausgegeben werden
- wenn direkte initialisierung NICHT gesamte l�nge von array ausnutzt ==> restliche eintr�ge mit 0 aufgef�llt

grundsyntax ausgabe von eintr�ge aus array:

<datenTyp1> const <L�ngenName> = <Zahlenwert>;
<datenTyp2> <ArrayName> [<L�ngenName>] = {}
ODER
<datenTyp2> <ArrayName> [<L�ngenName>] = {<Eintrag1>,<Eintrag2>,...}

==> die geschweiften KLAMMERN M�SSEN aufjedenfall hinter dem array stehen, denn sonst ist keine ausgabe der
eintr�ge aus array m�glich AUCH wenn man diese direkt ansprechen sollte!

-----------------------------------------------------------------------------------------------------------

bsp obda:
1)
int const DIM = 5;	//l�nge - 1 wegen der 0. stelle
double vec[DIM] = {1,2,3,4};	//geschweifte klammern sind hinreichend um eintr�ge beim ansprechen auszugeben
int i=3;

	if (i >= 0 && i < DIM)
		cout << vec[i] << endl;	//direktes ansprechen von array eintrag--> somit eintrag ausgebbar
	else
		cerr << "Indexbereich �uberschritten!" << endl;

//um eine operation f�r alle eintr�ge in array auszuf�hren ==> nutzung von for schleife hinreichend!!

for (int i = 0; i < DIM; ++i)
// da i=3 wird in schleife reingegangen da bed erf�llt ist! danach wird nur mit i=0 gearbeitet
//dh i=3 DIENT NUR als eintritt in die for schleife

	cout << vec[i] << endl;

ausgabe:
4
1
2
3
4
0	// 0 wurde aufgef�llt da nur 4 eintr�ge in array initialisiert wurden---> eine stelle blieb �brig!

-------------------------------------------------------------------------------------------------------
bsp obda 2):

int const DIM = 5;
double vec[DIM] = {1,2};	//geschweifte klammern hinreichend zur ausgabe von eintr�ge aus array

if (i >= 0 && i < DIM)	//syntaxfehler!! es ex keine variable i au�erhalb der for schleife!!
	cout << vec[i] << endl;	//direktes ansprechen von array eintrag--> somit eintrag ausgebbar
else
	cerr << "Indexbereich �uberschritten!" << endl;

//um eine operation f�r alle eintr�ge in array auszuf�hren ==> nutzung von for schleife hinreichend!!

for (int i = 0; i < DIM; ++i)
// wir haben KEIN globales i womit man eintritt in die for schleife bekommt!! dh nun nutzt die for schleife
// das i in seiner schleife selber UM die bedingung zu �berpr�fen! wenn sie gilt wird for schleife
//ausgef�hrt!!

cout << vec[i] << endl;

ausgabe: keine da es syntaxfehler bei if bedingung gibt da wir kein "globales" i mehr haben!

-------------------------------------------------------------------------------------------------------------
bsp obda 3):

int const DIM = 5;
double vec[DIM] = {1,2};	//geschweifte klammern hinreichend zur ausgabe von eintr�gen aus array
int z = 2; 
// wenn z unter if bedingung stehen w�rde --> fehler da compiler von oben runter liest und z noch nicht kennt

if (z >= 0 && z < DIM)	//syntaxfehler!! es ex keine variable i au�erhalb der for schleife!!
	cout << vec[z] << endl;	//direktes ansprechen von array eintrag--> somit eintrag ausgebbar
else
	cerr << "Indexbereich �uberschritten!" << endl;


for (int i = 0; i < DIM; ++i)
//keine globale variable bzgl der forschleife dh man nutzt das i aus for schleife selber um die
//bed. in for schleife zu �berpr�fen
	cout << vec[i] << endl;	


ausgabe:
0	//z = 2 , da aber an der zweiten stelle nix initialisert wurde, wird 0 ausgegeben da rest immmer mit 0 aufgef�llt!
1
2
0
0
0	//es gibts nur zwei initialisierte werte im array--> der rest wurde mit 0 aufgef�llt

****************************************************************************************************************/



/***************************************************************************************************************
REGEL: ausf�hrung von operation bzgl aller eintr�ge von array

- damit man operation auf alle eintr�ge im array ausf�hren kann
1)array muss zumindest mit {} initialisiert sein--> sonst wird nur speicheradresse ausgegeben 
2)for schleife nutzen
3) direktes ansprechen des eintrags im array an der stelle i
==> DH OHNE FOR SCHLEIFE kann man eintr�ge aus array NIE ausgeben lassen!!
---------------------------------------------------------------------------------------------------------------
bsp obda 1):

vec = 1; // Syntaxfehler! da man weder l�nge von array vec noch das array selber definiert hat!
for (int i = 0; i < DIM; ++i)
{
	vec[i] = 1;
	cout << vec << endl;	
	//fehler!hier wird nur die adresse des arrays ausgegeben da man die eintr�ge direkt ansprechen muss
	//damit sie ausgegeben werden!
}

--> so ist es korrekt:

int const DIM9 = 5;	//festlegen der l�nge von array mit konstanten wert
double vec[DIM9] = {2}; // direktes initialisieren des arrays mit 2--> der rest wird in regel mit 0 aufgef�llt
int i = 0;	// ist �berfl�ssig da sonst for schleife mit i aus eigener schleife die bedung. pr�ft
for (int i = 0; i < DIM9; ++i)
{
vec[i] = 1;
cout << "ausgabe vec array: " << vec[i] << endl;
}

ausgabe:
1	// sogar der initialiserte erste eintrag mit 2 wird �berschrieben
1
1
1
1

merke:
- wenn eine operation �ber for schleife f�r alle eintr�ge im array ausgef�hrt wird--> dann gilt das 
auch f�r vorher initialiserte werte im array
dh diese k�nnten wie hier einfach �berschrieben werden!!

------------------------------------------------------------------------------------------------------------------

bsp obda 2):

int const DIM9 = 5;	//festlegen der l�nge von array mit konstanten wert
double vec[DIM9] = {2}; // direktes initialisieren des arrays mit 2--> der rest wird in regel mit 0 aufgef�llt

for (int i = 0; i < DIM9; ++i)
{
cout << "ausgabe vec array: " << vec[i] = 1<< endl;	
// SYNTAXFEHLER!! man darf in cout nix initialiseren mit operator!

}

----------------------------------------------------------------------------------------------------------------
bsp obda 3):

int const DIM9 = 5;	//festlegen der l�nge von array mit konstanten wert
double vec[DIM9] = {}; // geschweifte klammern hinreichend damit �BERHAUPT eintr�ge aus array ausgegeben werden!

for (int i = 0; i < DIM9; ++i)
{
 vec[i] = 7;	
 cout << "ausgabe vec array: " << vec[i] << endl;

}

ausgabe:
0
7
7
7
7
7

//warum? im array steht kein initialiserter wert dh der compiler f�llt die l�nge des arrays einfach mit 0 
//komplett auf--> in der for schleife wird jetzt f�r alle eintr�ge im array folgendes ausgef�hrt also mit
//7 initialisiert bzw �berschrieben

----------------------------------------------------------------------------------------------------------------
bsp obda 4):

int const DIM9 = 5;	//festlegen der l�nge von arrays mit konstanten wert
double vec1[DIM9] = {}; // geschweifte klammern hinreichend damit �BERHAUPT eintr�ge aus array ausgegeben werden!
int i;
cout << "ausgabe array vec1: " << vec1[i] << endl;

ausgabe: 324A4324
--> dh es wurde die speicheradresse also der zeiger des arrays ausgegeben!warum? da man NUR die eintr�ge eines 
array mit einer for schleife ausgeben lassen kann und NIE einzelnd!!

***************************************************************************************************************/



/*************************************************************************************************************
REGEL: zuweisen von eintr�gen aus einem array zu einem anderen

- jenes array was werte zuweist MUSS geschweiften klammern haben und nat�rlich ner array l�nge definiert werden
- jenes array welches werte vom anderen array zugewiesen bekommt --> KANN mit geschweiften klammern definiert 
  werden
==> wenn beide arrays mit geschweifte klammern definiert--> problemloses zwuweisen von werten untereinander

-------------------------------------------------------------------------------------------------------
bsp obda 1:

int const DIM = 5;
int const DIM2 = 5;
double vec2[DIM2] = {3,4,6,18};	// geschweifte klammern MUSS da sonst NUR speicherpl�tze zugewiesen werden

double vec[DIM];	// hat keine geschweifte klammer da das nicht hinreichend ist da vec werte zugewiesen werden
for (int i = 0; i < DIM; ++i)
{
vec[i] = vec2[i];
cout << "ausgabe der eintr�ge von array vec: " << vec[i] << endl;
}

ausgabe:
3
4
6
18
0	// da array l�nge 5 hat und der rest des arrays mit 0 aufgef�llt wird!

Merke:
==>jenes array welches werte zugewiesen bekommt MUSS NICHT mit geschweiften klammern definiert werden!

-------------------------------------------------------------------------------------------------------
bsp obda 2):

int const DIM = 5;
int const DIM2 = 5;
double vec2[DIM2] = {3,4,6,18};	// geschweifte klammern MUSS da sonst NUR speicherpl�tze zugewiesen werden

double vec[DIM];	// hat keine geschweifte klammer da das nicht hinreichend ist wenn zu vec werte zugewiesen werden
for (int i = 0; i < DIM; ++i)
{
vec2[i] = vec[i];
cout << "ausgabe der eintr�ge von array vec: " << vec[i] << endl;
}

ausgabe:
324324b
3243244345b 
.
.
.
--> da vec NICHT mit geschweiften klammern definiert wurde, wurden KEINE werte initialisiert ---> somit werden
nur die speicherpl�tze der leeren eintr�ge vom array dem vec2 array zugewiesen!!

-------------------------------------------------------------------------------------------------------

bsp obda 3):

int const DIM = 5;
int const DIM2 = 5;
double vec2[DIM2] = {3,4,6,18};	// geschweifte klammern MUSS da sonst NUR speicherpl�tze zugewiesen werden

double vec[DIM] = {};	// hat geschweifte klammer und nur 0 als eintr�ge 
for (int i = 0; i < DIM; ++i)
{
vec2[i] = vec[i];	//ansprechen der eintr�ge im array damit zuweisung �berhaupt klappt
cout << "ausgabe der eintr�ge von array vec: " << vec[i] << endl;
}

ausgabe:
0
0
0
0
0

==> vec array wurde mit geschweifte klammern definiert--> somit kann man die eintr�ge von vec ausgeben lassen
ABER da kein wert dem array initialisiert wurde, wird das vom compiler einfach das array in voller l�nge mit 0
aufgef�llt ==> diese nullen werden dann zu vec2 zugewiesen

**************************************************************************************************************/


/*************************************************************************************************************
REGEL: zugriffschutz bei arrays	(AKTUALISIEREN!!!)

- das wird gemacht falls es mehr eintr�ge gibt als das array von seiner l�nge es her zul�sst
==>kein plan wp du ein problem sein soll! bei den schleifen die ich probierte ging alles
	s.108 im skript prozedural


--------------------------------------------------------------------------------------------------------------
bsp obda 1):

int const LEN = 3;
double a[LEN] = {};	// muss keine geschweiften klammern haben da es a[n] werte zugewiesen wird!!
a[0] = 1;
for (int n = 0; n <= LEN ; ++n)
{
a[n + 1] = a[n] + 1;
cout << "ausgabe array a: " << a[n] << endl;
}



//nebenrechnung:

//bei n=0	: a[1] = 1+1 --> a[1]=2
//bei n=1	: a[2] = 2 + 1 --> a[2] =3
//bei n=2	: a[3] = 3 + 1 --> a[3] = 4
//bei n=3 : a[4] = 4 + 1 --> a[4] = 5

==> ausgabe:
1
2
3
4
=====> ABER in der berechnung m�sste noch die 5 ausgegeben werden!!das passiert aber nicht

--------------------------------------------------------------------------------------------------------------
bsp obda 2): aus skript direkt

int const LEN = 4;
double a[LEN] = {};	// muss keine geschweiften klammern haben da es a[n] werte zugewiesen wird!!
a[0] = 1;
for (int n = 0; n < LEN-1; ++n)
{
a[n + 1] = 1 / (a[n] + 1);
cout << "ausgabe array a: " << a[n] << endl;
}


nebenrechnung zum verhalten von dieser fkt:
bei n= 0: a[1] = 1/1+1 -->
bei n= 1: a[2] = 1/ 1/2 +1	--> 3
bei n=2 : a[3] = 1/ 3+1 ---> 1/4
bei n=3 : a[4] = 1 / 1/4 + 1 --> 4/5

--------------------------------------------------------------------------------------------------------------

*************************************************************************************************************/

/***********************************************************************************************************
REGEL: char array 

-steht auf s.109 skript
- hab ich mir noch nicht angeguckt da anderes wichtiger ist
- man muss keine l�nge angeben--> compiler z�ht zeichen selber

syntax char array:

char <ArrayName> [] = "<BuchstabenOderZahlen>";


bsp obda 1):

char gruss[] = "hallo!" ;	// compiler h�ngt nach dem ! ein '\0' ins array dran
cout << "ausgabe von gruss: " << gruss << endl;

ausgabe: hallo!

==> dh bei char arrays gilt:
1)man braucht weder eine l�nge f�r das array anzugeben
2)wenn man die eintr�ge ausgeben lassen m�chte--> eintragen von array name in cout dh KEIN direktes
ansprechen der char array eintr�ge n�tig

--------------------------------------------------------------------------------------------------------------
bsp obda 2):

char gruss[] = "hallo!" ;	// compiler h�ngt nach dem ! ein '\0' ins array dran
int i = 0;
while ( gruss[i] != '\0')	// mit gruss[i] greift man auf eintrag in dem char array zu
{
	++i;
}
//wenn der eintrag im char array das zeichen \0 hat--> dann aufh�ren von schleife da bei char array das letzte
//zeichen im array mit \0 immer aufgef�llt wird!!!!

cout << "ausgabe von laenge char array: " << i << endl;

ausgabe: 6
==> dh um l�nge von char array zu erfahren--> nutzen von while schleife!!

--------------------------------------------------------------------------------------------------------------

bsp obda3):


char gruss[] = 'hallo!';	
//syntaxfehler!! man darf nur mit " " eintr�ge von char array umschlie�en

cout << "ausgabe von 0 stelle von char array: " << gruss[0] << endl;
cout << "ausgabe von 5 stelle von char array: " << gruss[5] << endl;

---->korrekt w�re es:

char gruss[] = "hallo!"; // l�nge von char array wird von compiler selber bestimmt

cout << "ausgabe von 0 stelle von char array: " << gruss[0] << endl;	// ansprechen von 0 ten eintrag im array
cout << "ausgabe von 5 stelle von char array: " << gruss[5] << endl;

ausgabe: h 
ausgabe: !

==> man kann trotz allem die eintr�ge eines arrays direkt ansprechen! sei es char oder anderes array!


***********************************************************************************************************/

/*********************************************************************************************************
REGEL: char fkt mit mehreren parametern

- hier sieht man die facetten einer fkt mit verschiedenen parametern

bsp obda 1):

parameterliste fordert:
1) char array , 2) double array , 3) int wert LAENGEvec was l�nge von vec[] array darstellt
==> diese forderungen sind hinreichend!! da f�r ein double array brauch ich eine festgelegte l�nge!
diesbzgl muss nat�rlcih dann ein array definiert werden, welches diese l�nge beinhaltet!
--> das char array hier in der fkt wird als name des neu erstellten arrays benutzt


void gibAus(char nameArray[], double vec[], int LAENGEvec)	// muss �ber main stehen sonst macht compiler �rger
{
	cout << nameArray << "[] = [ " ;	
// ausgabe von eintr�gen aus char array!wir erinnern uns: um eintr�ge von char array ausgeben zu lassen
//--> reicht aus NUR den array namen in cout zu schreiben!! dann werden alle eintr�ge aus diesem char array
//ausgegeben--> wert bei diesem char ist okitoki
	
	for (int i = 0; i < LAENGEvec; ++i) // ausgabe von eintr�gen aus vec array--> nutzen IMMER for schleife
//bed in for schleife erf�llt da man das i=0 in der for schleife zum pr�fen der bedingung nutzt!!

		cout << vec[i] << " ";	//ausgabe von eintr�gen aus array-->IMMER ansprechen der array eintr�ge
								//die " " lassen leerzeichen im array entstehen--> sieht besser aus
	cout << "]" << endl;
}

int main()
{
	char besteArray[] = "okitoki";
	int const LAENGEvec = 2;
	double vec[LAENGEvec] = {};
//die drei komponenten hier wurden von parameterliste der fkt gefodert! wenn eins davon fehlt kann die
//fkt NICHT aufgerufen werden!!sind also hinreichend die dinge

	gibAus(besteArray, vec, LAENGEvec);	
//MUSS mich an die REIHENFOLGE wie ich die 


	return 0;
}

ausgabe: okitoki[] = [ 0 0 ] --> warum? da array vec leer ist und keine eintr�ge hat!!

merke:
1) parameterliste einer fkt fordern immmer komponenten die man definieren MUSS 
2)jene arrays oder variablen die ich in main definiert habe -->k�nnen so hei�en
==> HAUPTSACHE die reihenfolge in der parameterliste bzgl der geforderten parameter
wird eingehalten 
dh kann jetzt zuerst die l�nge vom array eingeben und dann erst den char array name

bsp: 

gibAus(vec, LAENGEvec, besteArray);	// FEHLER! da ich mich nicht an die reihenfolge hielt!
korrekt w�re-->
gibAus(besteArray, vec, LAENGEvec);	//Reihenfolge der geforderten parameter eingehalten!!

3)fkt selber steht IMMER �ber der main fkt
4) aufruf der fkt erfolgt im main

**********************************************************************************************************/

/*******************************************************************************************************
REGEL: arrays zueinander zuweisen

- arrays werden IMMER �ber 
i) das direkte ansprechen des eintrags im array also �ber dessen index ausgegegebnn
ii) das zuweisen von eintr�gen aus einem array zum anderen array erfolgt IMMER GLEICHZEITIG 
mit der erfassung der einzel eintr�ge eines arrays
==> man wei�t die einzeleintr�ge mit benutzung der for schleife einander zu!!

-------------------------------------------------------------------------------------------------------
bsp obda 1):


// weise von[] der L�ange nvec zu an nach[]
void weiseZu ( double nach[], double von[], int nvec )
{
	for ( int i = 0 ; i < nvec ; ++i )	// ausgabe von eintr�ge aus zahlen array
	nach[ i ] = von[ i ] ;
//zugriff der eintr�ge aus den arrays �ber indizes --> dann direkt zuweisen! 
//wobei jenes array was zugewiesen wird KEINE {} ben�tigt! bei zuweisung wird einfach gleichgesetzt!

}

int main ()
{
	int const LAENGE1 = 5;
	int const LAENGE2 = 5;
	double zuGewiesen[LAENGE1];
	double weistZu[LAENGE1] = { 4,8,90,3 };

	weiseZu(zuGewiesen, weistZu, LAENGE1);
	gibAus("zuGewiesen", weistZu, LAENGE1);	
	//erste parameter muss eigentlich char array sein!aber man kann wohl auch direkt ein char da einf�gen! 
	
	// jene parameter die ich main definiert haben M�SSEN NICHT denselben tragen wie in der parameterliste
	//==> HAUPTSACHE die reihenfolge der geforderten parameter in der parameterliste wird eingehalten!

	return 0 ;
}

ausgabe: zuGewiesen [] = [4 8 90 3 0] --> warum? da array l�nge 5 hat.letzte stelle einfach mit 0 aufgef�llt!
-----------------------------------------------------------------------------------------------------------

merke:
1) zuweisung von eintr�gen eines arrays zum anderen --> for schleife nutzn und eintr�ge direkt ansprechen
mit index wie zb nach[i] = vor[i];

**********************************************************************************************************/

/***********************************************************************************************************
REGEL: nutzung von const bei parameter liste

- bei manchen parameter ist sinnvoll sie const zuu machen--> damit werden sie nur gelesen! keine �nderung mehr
nachtr�glich m�glich

bsp obda:

int textLaenge ( char const text[] )
// die eintr�ge des char arrays text[] sollen nicht mehr ver�ndert werden

void gibAus ( char const name[], double const vec[], int nvec )
// eintr�ge von char array name und array vec sollen unver�nderbar bleiben!! die l�nge will man ja ggf �ndern

void weiseZu ( double nach[],  double const von[], int nvec )
// NUR von[] array wird const weil das ja zu nach[] zugewiesen wird! welche eintr�ge nach[] hat ist dann egal!
//nvec ist die l�nge der arrays und sollte ver�nderbar bleiben!!

*************************************************************************************************************/

/***********************************************************************************************************
REGEL: unterschied zwischen initialisierung mit {} und ohne bei char arrays

- compiler z�hlt die l�nge bei char arrays automatisch--> somit l�ngen angabe f�r char arrays nicht notwendig
- ABER man kann char array AUCH mit {} initialisieren---> hierbei kann es zu laufzeitfehler kommen!

------------------------------------------------------------------------------------------------------------
bsp obda 1):

char BuchstabenArray [] ="halloWasGeht?";
cout << "ausgabe BuchstabenArray: " << BuchstabenArray << endl;

ausgabe: ausgabe BuchstabenArray: halloWasGeht?
==> ausgabe von char array durch einsetzen von array name in cout!

------------------------------------------------------------------------------------------------------------

bsp obda2):

char geschweiftesArray [] = {'h', 'a' ,'l', 'l', 'l', 'o' , '\0'};
cout <<"ausgabe geschweiftesArray: " <<geschweiftesArray<< endl;

ausgabe: 
ausgabe geschweiftesArray: hallo

==> NUR durch das '\0' am ende ==> problemlose ausgabe des char arrays!
------------------------------------------------------------------------------------------------------------

bsp obda 3):

char geschweiftesArray[] = { "h" , "i"}; // syntax fehler da man NUR einmal "" bei char array benutzen darf!
cout << "ausgabe geschweiftesArray: " << geschweiftesArray << endl;

==> dh char array [] = { " " } --> NUR EINMAL nutzung von "" in char array initialisierung m�glich

char array [] = {" ", ' '} --> SYNTAXFEHLER! entweder NUR "" oder NUR ''! beides gleichzeitig geht nicht

korrekt w�re es also:

char geschweiftesArray[] = { 'h' , 'i'}; // besser aber immernoch nicht korrekt!!
cout << "ausgabe geschweiftesArray: " << geschweiftesArray << endl;

ausgabe:
ausgabe geschweiftesArray: himuText 
--> die endung muText wird automatisch rangemacht da wohl der compiler nicht weiss wann das char array direkt
aufh�rt! DH das '\0' wird bei schreibweise {} nicht direkt erfasst!!

noch besser w�re es also: 

char geschweiftesArray[] = { 'h' , 'i', '\0'}; // perfekt!!
cout << "ausgabe geschweiftesArray: " << geschweiftesArray << endl;

==>ausgabe:
ausgabe geschweiftesArray: hi

--> nun funktioniert die ausgabe perfekt da am ende ein '\0' an das char array angeh�ngt wurde!

------------------------------------------------------------------------------------------------------------
MERKE:
1) initialisierung von char array[] mit {} also char array[] = {} --> NUR mit '\0' als letzter eintrag im array
---> dh man MUSS IMMER '\0' als letzten eintrag bei einem char [] ={} hinzuf�gen ---> dann korrekte ausgabe
von char array m�glich!!!

**************************************************************************************************************/

/*************************************************************************************************************
REGEL: zus�tzliche l�ngen angabe bei char array

- man kann zus�tzlich die l�nge bei einem char array mit festlegen --> hier bei muss diese dann mit der l�nge
des arrays �bereinstimmen

bsp obda 1):

char geschweiftesArray[5] = { 'h', 'a' ,'l', 'l', 'o', '\0' }; 
// syntax fehler! da wir 6 eintr�ge im {} array haben--> es kompiliert nicht ABER es wird trotzdem das 
//array ausgegeben

--> korrekt w�re also

char geschweiftesArray[6] = { 'h', 'a' ,'l', 'l', 'o', '\0' };
// kein fehler mehr!da es genau 6 zeichen sind und das array genau l�nge 6 hat! passt also


bsp obda 2):

char BuchstabenArray[5] = "halloWasGeht?";
// syntaxfehler!! es sind mehr als 5 zeichen im array enthalten--> daher keine kompilierung ABER
// es wird am ende ausgegeben!

--> besser also w�re:

char BuchstabenArray[13] = "halloWasGeht?";
// IMMERNOCH syntaxfehler!! warum? da IMMER beim array noch das zus�tzliche zeichen '\0' angef�gt wird!!
//dh obwohl das array 13 zeichen hat MUSS man es als array mit 14 zeichen sehen wegen '\0' am ende!!

char BuchstabenArray[14] = "halloWasGeht?"; // perfekt!
// kein fehler mehr! wir haben das 14.zeichen im array mit beachtet! somit kompiliert es reibungslos!


MERKE: 
1) beachten das char array [] = "" definition ==> IMMER '\0' als zus�tzliches zeichen enth�lt
==> muss in l�ngenangabe von array mitgez�hlt werden!!

***************************************************************************************************************/

/**************************************************************************************************************
REGEL: zweidimensionale matrix mit array erstellen

- man nutzt dazu ein array mit zwei l�ngen angaben

syntax zweidimensionale matrix:
<DatenTyp> <NameArray> [<L�ngeZeilen>] [<L�ngeSpalten>] = { {<Zeile1>}, {<Zeile2>}, ... }
==> anzahl der zahlen in zeilen == anzahl der spalten in matrix!!

--------------------------------------------------------------------------------------------------
bsp obda 1):

int const NZEILEN = 3;
int const NSPALTEN = 4;
int matrix[NZEILEN][NSPALTEN] = { {3,4,4,7},	//zeile 0
								  {1,5,6,9},	//zeile 1
								  {4,1,1,0} };	//zeile 2
// haben hier 3 zeilen wobei jede zeile �ber 4 eintr�ge verf�gt ==> es ex. 4 spalten!

cout <<"ausgabe von matrix: " << matrix << endl;

ausgabe: 32445324b
==> es wird die speicheradresse des arrays ausgegeben!! warum? weil wir die einzelnen eintr�ge DIREKT 
ansprechen m�ssen damit sie ausgegeben werden! das passiert mit for schleife...anders gehts nicht!

--------------------------------------------------------------------------------------------------

bsp obda 2):

int const NZEILEN = 3;
int const NSPALTEN = 4;
int matrix[NZEILEN][NSPALTEN] = { {3,4,4,7},	//zeile 0
								  {1,5,6,9},	//zeile 1
								  {4,1,1,0} };	//zeile 2
// haben hier 3 zeilen wobei jede zeile �ber 4 eintr�ge verf�gt ==> es ex. 4 spalten!

for (int i = 0; i < NZEILEN ; ++i )
	for (int j = 0; j < NSPALTEN ; ++j)	
		cout <<"ausgabe matrix: " << matrix[i][j]<< endl;

==> erste for schleife ist f�r zeilen und zweite f�r spalten gedacht!
DH wenn man in der 0.zeile ist dann werden dort ALLE eintr�ge aus den jeweils spalten in der 0.zeile 
ausgegeben! --> die werden also f�rmlich abgearbeitet bis die bed. in der j for schleife nicht mehr gilt
DANN geht man zur 1. zeile �ber und beginnt mit der i for schleife

==>AUFPASSEN: beide for schleifen m�ssen bei 0 beginnen damit wirklich alles ausgegeben wird UND die reihenfolge
der indizes bzgl der matrix muss eingehalten werden! dh zuerst zeile dann spalte!

ausgabe:
ausgabe von matrix: 3
ausgabe von matrix: 4
ausgabe von matrix: 4
ausgabe von matrix: 7
ausgabe von matrix: 1
ausgabe von matrix: 5
ausgabe von matrix: 6
ausgabe von matrix: 9
ausgabe von matrix: 4
ausgabe von matrix: 1
ausgabe von matrix: 1
ausgabe von matrix: 0

--------------------------------------------------------------------------------------------------

bsp obda 3):

int const NZEILEN = 3;
int const NSPALTEN = 4;
int matrix[NZEILEN][NSPALTEN] = { {3,4,4,7},	//zeile 0
								  {1,5,6,9},	//zeile 1
								  {4,1,1,0} };	//zeile 2
// haben hier 3 zeilen wobei jede zeile �ber 4 eintr�ge verf�gt ==> es ex. 4 spalten!

for (int i = 0; i < NZEILEN; ++i)
{
	for (int j = 0; j < NSPALTEN; ++j)
		cout << matrix[i][j] << " ";	//leerzeichen zwischen jedem eintrag in matrix-->�bersichtlicher
	cout << endl;	// wenn alle spalten in einer zeile durch sind wird zeilenumbruch gemacht wegen endl!!
}
cout << endl;// zeilenumbruch unter der gesamten matrix--> ist nicht notwendig aber

==> dh erste for schleife ist f�r die zeilen gedacht und zweite for f�r spalten
--> wenn erste for schleife in 0.zeile ist dann werden die eintr�ge in der 0.zeile spaltenweise
ausgegeben 
dh ausgabe :eintrag 0 (spalte0)aus zeile 0 mit leerzeichen wegen "" in cout << matrix[i][j] << " ";
   ausgabe: eintrag 1 (spalte1)aus zeile 0 mit leerzeichen wegen "" in cout << matrix[i][j] << " ";
   ausgabe: eintrag 2 (spalte2)aus zeile 0 mit leerzeichen wegen "" in cout << matrix[i][j] << " ";
   ausgabe: eintrag 3 (spalte3)aus zeile 0 mit leerzeichen wegen "" in cout << matrix[i][j] << " ";
   --> NUN gesamte zeile 0 ausgegeben!
jetzt gehts zur zeile 1 usw ...
   
==> wenn man das "" in der ausgabe weglassen w�rde DANN werden alle eintr�ge hintereinander weg OHNE
leerzeichen ausgegeben!

ausgabe:
3 4 4 7
1 5 6 9
4 1 1 0

-->so sieht es �bersichtlicher aus!

--------------------------------------------------------------------------------------------------
bsp obda 4):

int const NZEILEN = 3;
int const NSPALTEN = 4;
int matrix[NZEILEN][NSPALTEN] = { {3,4,4,7},	//zeile 0
								  {1,5,6,9},	//zeile 1
								  {4,1,1,0} };	//zeile 2
// haben hier 3 zeilen wobei jede zeile �ber 4 eintr�ge verf�gt ==> es ex. 4 spalten!

for (int i = 0; i < NZEILEN; ++i)
{
	for (int j = 0; j < NSPALTEN; ++j)
		cout << matrix[i][j] ; 	//KEIN leerzeichen durch "" dort--> dh alle eintr�ge hintereinander ausgegeben
	cout << endl;	// wenn alle spalten in einer zeile durch sind wird zeilenumbruch gemacht wegen endl!!
}
cout << endl;// zeilenumbruch unter der gesamten matrix--> ist nicht notwendig aber

ausgabe:
3447
1569
4110


***************************************************************************************************************/

/**************************************************************************************************************
REGEL: selbst initialisierung einer matrix mit for schleife

- wenn man eine matrix hat UND die eintr�ge in dieser matrix mit einer formel ermittel werden k�nnen
--> dann selbst initialiiserung hilfreich!! dh man initialisiert die matrix NICHT vorher!


bsp obda 1):

int const NZEILEN = 3;
int const NSPALTEN = 4;
int matrix[NZEILEN][NSPALTEN] = {};	// leere matrix OHNE eintr�ge

for (int i = 0; i < NZEILEN; ++i)	//durchgehen von zeilen in matrix
{
	for (int j = 0; j < NSPALTEN; ++j)	//abarbeiten der spalten in einer zeile
	{
		matrix[i][j] = i + 3 * j;	
		//rechenvorschrift wie eintr�ge in matrix erstellt werden UND mit matrix initialisiert werden

		cout << matrix[i][j]<< " ";	
		// jeweils nach jeder spalte in einer zeile kommt ein LEERZEICHEN daher " " und nicht ""
		// --> GANZ wichtig drauf zu achten da es sonst keinen effekt hat!
	}
	cout << endl; 
	// zeilenumbruch nach jeder zeile SONST werden alle eintr�ge der zeilen auf NUR EINER ZEILE ausgegeben
}

ausgabe:
0 3 6 9
1 4 7 10
2 5 8 11

==> eintr�ge wurden mit der vorschrift selbst erstellt und mit matrix initialisiert!

***************************************************************************************************************/

/*************************************************************************************************************
REGEL: dynamisches array

- statisches array == l�nge vor laufzeit schon bereit       -->array wurde alloziert
allokation == statisches array mit l�nge definiert!
- dynamisches array == l�nge steht ERST zur laufzeit bereit --> array ist aber vorab da

- um dynamisches array zu definieren braucht man einen zeiger!

---------------------------------------------------------------
syntax dynamisches array wenn l�nge da ist:

<datenTyp>* <ArrayName> = new <datenTyp> [<L�NGE>];	
--> zweiter datentyp ist total wichtig !

==> jedes array hat selber ein zeiger wodurch er auf die erste speicheradresse des ersten eintrags im array zeigt!

statisches array == hat per def. des arrays einen zeiger ==> dieser zeigt auf erste speicher adresse von array
dynamisches array == braucht zus�tzlichen zeiger noch um auf array zu zeigen da l�nge w�hrend laufzeit bestimmt
					 wird ==> hat somit zwei zeiger, eins von array selber und eins was es so noch braucht!!

----------------------------------------------------------------------------------------------------------
bsp obda 1):

int n;
cout << "n = ";
cin >> n;	//eingabe der l�nge per laufzeit

// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
int* fkt = new int[n + 1];	// 

// berechne rekursive fkt
	fkt[0] = 1;
	fkt[1] = 1;
	for (int k = 1; k < n; ++k)	// davor war k=0 und k<=0 f�r bed.
	{
		fkt[k] = fkt[k-1] * (n + 1) / k;
		cout << "ausgabe fkt: " << fkt[k] << endl;
	}

ausgabe:als bsp hab ich n=3 genommen
somit kommt raus:
4
8
==> es ist eigentlich nichts besonderes!unterschied zu normalen array ist NUR das die l�nge
in der laufzeit also vom user bestimmt wird---> mehr nicht

MERKE:
1) l�nge darf auch ein RECHENAUSDRUCK sein!wie wir oben sehen

----------------------------------------------------------------------------------------------------------
bsp obda 2):
-wollen eintr�ge von dynamischen array ausgegegeben bekommen

int n;
cout << "n = ";
cin >> n;
// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
int* fkt20 = new int[n + 1];	// n=3
cout << "ausgabe dyn array: " << fkt20[n] << endl;

ausgabe:2132445 
--> dh es wird die speicheradresse zur�ck gegeben. warum? da wir nicht mal ein dynamisches
array initialisiert haben UND das NICHT mal mit einer geschweiften klammer! somit ist KLAR das man nur
die speicher adresse zur�ck bekommt!!

----------------------------------------------------------------------------------------------------------
bsp obda 3):
- dyn array ohne {} definiert aber was trotzdem eintr�ge ausgeben soll--> tut es nat. nicht

int n;
cout << "n = ";
cin >> n;
// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
int* fkt20 = new int[n];	// n=3

for (int i = 0; i < n; i++)
{
	cout << "ausgabe dyn array: " << fkt20[i] << endl;
}

ausgabe:
ausgabe dyn array:3243434
ausgabe dyn array:43453534
.
.
==> speicheradressen bzw eher der zeiger wird ausgegeebn!sind nur reine zahlen daher bissel verwunderlich!
habe auch kein array so mit {} mit definiert

----------------------------------------------------------------------------------------------------------
bsp obda 4):

int n;
cout << "n = ";
cin >> n;
// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
int* fkt20 = new int[n];	// n=3
fkt20 ={}

for (int i = 0; i < n; i++)
{
cout << "ausgabe dyn array: " << fkt20[i] << endl;
}

ausgabe: NIX!! weiss nicht warum das so ist! dh die regeln f�r normale arrays gelten f�r dynamische arrays
nicht wirklich

----------------------------------------------------------------------------------------------------------
bsp obda 5):

int n;
cout << "n = ";
cin >> n;
// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
int* fkt20 = new int[n];	// n=3
fkt20 ={5}; // diesmal wert eingetragen ABER Synataxfehler!!

for (int i = 0; i < n; i++)
{
cout << "ausgabe dyn array: " << fkt20[i] << endl;
}

ausgabe: FEHLER weil ich in dynamisches array eintrag initialisiert habe! zwar kompiliert es wenn die 
geschweiften klammern leer sind ABER es passiert nix
==> hab keine ahnung warum das so ist! kommt vlcht sp�ter!

----------------------------------------------------------------------------------------------------------

==> merke:
1)auch wenn man dynamisches array mit {} definiert---> bei ausgabe der eintr�ge passiert nix

****************************************************************************************************************/


/**************************************************************************************************************
REGEL: l�schen von zeiger bei dynam array 

- wenn man bei dyn array die l�nge w�hrend der laufzeit festlegt --> so wird diese l�nge im speicher als
speicherplatz reserviert!
==> zwar wird der speicher nach der laufzeit ans betriebssystem zur�ck gegegeben ABER es ist guter stil 
dass der programmierer selber daran denkt und dieses f�r das betriebssystem  freigibt!

syntax l�schen von zeiger vom dyn array:

delete [] <ArrayName>;

==> da das array SELBER einen zeiger hat, kann man auch umgangssprachlich auch sagen
delete[] <ZeigerName>;	//--> ist dasselbe

-------------------------------------------------------------------
KERNREGEL: Zu jedem new[] geh�ort genau ein delete[],
sobald der Speicher zur Laufzeit nicht mehr gebraucht wird.
-------------------------------------------------------------------
==> dh wenn man delete[] <ArrayName> mind. 2 mal f�r ein array nutzt dann kommt es zum laufzeit fehler!


----------------------------------------------------------------------------------------------------------------
bsp obda 1):
- schlie�en von zwei dim dynam array mit doppelten delete[]

// gib Array der Zeilenzeiger frei
delete[] matrix ;

// gib alle Matrixzeilen frei
for ( int i = 0 ; i < m ; ++i )
	delete[] matrix[ i ] ;	// FEHLER! 

==> es entsteht hierbei ein absturz da wir mit delete[] matrix bereits die speicheradresse des gesamten
arrays freigegeben haben--> SOMIT haben wir dann kein zugriff um die einzelnen eintr�ge des speichers 
l�schen zu k�nnnen
--> muss also andere m�glichkeit geben!!
----------------------------------------------------------------------------------------------------------------
bsp obda 2):
- um ein zweidimen. array komplett zu l�schen also SO das KEIN laufzeutfehler entsteht, kann man AUCH 
muss man das delete [] folgenderma�en nutzen ABER nur so:

// gib Array der Zeilenzeiger frei
delete[] matrix[i] ; // hier erstmal eintr�ge im array freigegegen

// gib alle Matrixzeilen frei
for ( int i = 0 ; i < m ; ++i )
	delete[] matrix;	// DANN ERST komplettes array freigegeben

==> hier l�uft alles super! die reihenfolge passt

MERKE: 
==> bei zweidim. dyn. arrays muss man beim freigeben des speichers 
1) ERST die eintr�ge von array l�schen: delete [i] matrix
2) DANN erst die speicheradresse vom array l�schen : delete[] matrix

***************************************************************************************************************/



//array mit const l�nge
	int const laenge = 10;	//geht nur mit const variable bzw wenn man zahl in potenz[<zahl>] eintr�gt
	int potenz[laenge] = { 1 }; 
//kompilierbar da compiler beim ersten durchlauf des codes, alle const werte in den speicher 
// bereits speichert--> dann macht compiler zweiten durchlauf und f�hrt ERST DANN die anweisungen aus

// CHAR ARRAY --> gilt dasselbe dh const l�nge muss initialisiert werden zuvor ABER die l�nge vom
//kann man sp�ter so erfahren OHNE for schleifen berechnung dh bei int array geht l�nge verloren!

	int array[] = { 6,7 };
	//stellt array mit l�nge zwei her--> anpassung der l�nge des arrays an die mit gegebenen werte 
	//in {6,7} --> somit weiss compiler wie gro� l�nge von array sein muss
	// ABER : bei int array[]; --> FEHLER da compiler nicht weiss wie lang array sein soll!
	// BESSER -->int const laenge --> da sonst laenge verloren geht 
	
	
//---------------------------------------------------------------------------------------	
	
	// ausgabe von objekten aus zahlen array
	int const laenge2 = 2;
	int array2[laenge2] = { 4,5 };// NICHT '\0' ans ende gesetzt
	for (int i = 0; i < laenge2 ; i++) 
		cout << array2[i] << endl; //ausgabe : 4 5
	// ausgabe aller elementen aus zahlen array NUR mit for schleife m�glich dh wenn man 
	//cout<< array<< endl; == also ausgabe der eintr�ge von array will ==> ausgabe von speicher-
	//adresse die sich bei jedem neuen aufruf �ndert!
	//mit EINER AUSNAHME : char arrays

	// ausgabe von objekten aus char array
	char zeichenkette[] = "Text";	// bei initialisierung automatisch '\0' ans ende gesetzt
	//aber wenn l�nge von char array nicht ausrecht--> dann '\0' wird in anderen speicher 
	//�berschrieben
	cout << zeichenkette << endl; // ausgabe: text
	// char array == ausgabe von elemente OHNE for schleife m�glich
//-------------------------------------------------------------------------------------------

/*
zeiger
*/	
	char  textArray[] = "Hallo!"; //statisches array mit l�ngenanpassung an objekte MIT '\0'
	/* char* const zeiger [] <==> char textArray[] --> dh array ist ein konstanter zeiger auf 
	variablentyp also das const bezieht sich auf variablentyp links
	=> somit sobald [] oder int* bzw char* steht --> haben automatisch zeiger
	
	 int* oder char* == adresse f�r array gebildet
	 int* const oder char* const == adresse bleibt gleich durch also nicht mehr �nderbar
	 array == zeiger wenn man adresse meint
		
		char* array [] == haben zwei zeiger 1) durch * und 2) durch []
		--> wenn ich nun auf die adresse bzw. den zeiger dieses array zeigen will dann
		--> char** array [] dh ich zeige mit nem zeiger auf den zeiger des arrays also 
			auf die adresse des arrays

	*/

	char* textZeiger = textArray; // zeiger zeigt auf array
	///int*  iZeiger = textArray;	// datentyp von zeiger == datentyp von array SONST fehler
	//char* hZeiger = textArray[0] - �A� + �a�;   // Buchstabe �h�
	char* cZeiger[] = { "text" };//textZeiger;

								 
/***************************************************************************************************************/
//TESTBEREICH CODE

	
	// normale ausgabe von zahlen array
/*
	int const DIM9 = 5;	//festlegen der l�nge von arrays mit konstanten wert
	double vec1[DIM9] = {}; // geschweifte klammern hinreichend damit �BERHAUPT eintr�ge aus array ausgegeben werden!

	for (int i = 0; i < DIM9; ++i)
	{
		//vec1[i];
		cout << "ausgabe vec1 array: " << vec1[i] << endl;
	}


	int n;
	cout << "n = ";
	cin >> n;
	// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
	int* fkt = new int[n + 1];	// n=3
	// berechne Binomialkoeffzienten
	fkt[0] = 1;
	fkt[1] = 1;
	for (int k = 1; k < n; ++k)	// davor war k=0 und k<=0 f�r bed.
	{
		//binom[k] = binom[k - 1] * (n - k + 1) / k;
		fkt[k] = fkt[k-1] * (n + 1) / k;
		cout << "ausgabe fkt: " << fkt[k] << endl;
	}




	int n;
	cout << "n = ";
	cin >> n;
	// alloziere Array dynamisch--> dh man gibt dynamischen array zur laufzeit eine l�nge!!
	double* fkt20 = new double[n];	// n=3
	 fkt20 = {3};
	 for (int i = 0; i < n; i++)
	 {
		 cout << "ausgabe dyn array: " << fkt20[i] << endl;
	 }

	int m, n;

	cout << "gebe m ein: " << endl;
	cin >> m;
	cout << "gebe n ein: " << endl;
	cin >> n;
	//double* new double matrix[m];
	// alloziere Array der Zeilenzeiger
	 double** matrix = new double*[m];
	 // alloziere alle Matrixzeilen
	 for (int i = 0; i < m; ++i)
	 {
		// matrix[i] = new double[n];
		 cout << "ausgabe matrix: " << matrix[i] << endl;
	 }
	*/
/*
	// rechne vec = matrix * vec
	void multipliziere(double* const matrix[], double vec[], int dim)
	{
		// tempor�ares Array f�ur Ergebnis
		double* produkt = new double[dim];
		// rechne produkt = matrix * vec
		for (int i = 0; i < dim; ++i)
		{
			produkt[i] = 0;
			for (int j = 0; j < dim; ++j)
				produkt[i] += matrix[i][j] * vec[j];
		}
		// kopiere produkt[] nach vec[] zur�uck
		for (int i = 0; i < dim; ++i)
			vec[i] = produkt[i];
		// gebe Array wieder frei
		delete[] produkt;
	} // multipliziere()
*/
	int const DIM = 10;
	double array3[DIM] = { 1,2,3,4 };
	double** DynArray = new double*[20];
	multipliziere(DynArray, array3, 20 );

/***************************************************************************************************************/






	return 0;
}