#include "KonstruktorVererbung.h"
#include <iostream>
#include <string>


Basis::Basis(char i){}
//Basis::Basis(double i, int z){}
Basis::Basis() {}
/*
abgeleitete klasse nutzt IMMER den konstruktor der basisklasse egal
ob er im header drinsteht oder NICHT!
ABER wenn der standardkonstruktor durch einen selbstdefinierten kostruktor
(der mindestens einen paramater in der parameterliste enthält), ersetzt wird
==> so muss dieser selbstdefinierte standardkonstrutor weiter genutzt werden!
dh man MUSS die paramaterliste dieses standardkonstruktors der basisklasse
AUCH beim standardkonstruktor der abgeleit. klasse einhalten
====> SONST FEHLER!!!
UND
wenn die abgeleitete klasse einen selbst definierten standardkonstrkutor besitzt,
und im header der basisklasse NUR der selbstdef. standardkonstruktor da steht,
aber der selbstdef. standardkonstriuktor NICHT identisch mit dem selbstdefinierten
standardkonstr. der basisklasse ist
==> so entsteht auch ein FEHLER!!

dh es geht hier nur darum
*/
Spezialfall::Spezialfall(): Basis('chsf'){}
Spezialfall::Spezialfall(double i, double z):Basis('5') {}
Spezialfall::Spezialfall(char i) { }

/*
Spezialfall::Spezialfall(){}
Spezialfall::Spezialfall(double i, double z) {}

Spezialfall::Spezialfall(int i){}
*/

//Spezialfall::Spezialfall(){}