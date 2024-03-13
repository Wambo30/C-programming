#include <iostream>
#include <string>
#include "Person.h"
#include "UeberschreibenMethode.h"
#include "KonstruktorVererbung.h"
using namespace std;


int main() {

	/*
	Person person1;
	Angestellte mitarbeiter1;
	mitarbeiter1.setName("gustaf schneider");
	mitarbeiter1.setAdresse("Koenigsallee 14");
	mitarbeiter1.setPersonalnr("Ae1234");
	mitarbeiter1.email = "gustaf_schneider@gmail.com";
	mitarbeiter1.ausgeben();
	/*ausgabe
	name: gustaf schneider
	adresse : Koenigsallee 14
	email : gustaf_schneider@gmail.com
	personalnr : Ae1234
	==> hat also funktioniert! bei attributen die man die public sind OHNE getter und setter
	weist man einfach einen wert zu!
	*/
	/*
	cout << endl;
	Angestellte mitarbeiter2;
	mitarbeiter2.setName("franz mueller");
	mitarbeiter2.setAdresse("luxemburgerstraße 17");
	mitarbeiter2.ausgeben();
	*/

/*

	//überschreiben methode test
	Datum dat;
	Feiertag heute;
	//heute.anlass = "opferfest";
	heute.setAnlass("opferfest");
	dat.ausgeben();
	cout << endl;
	heute.ausgeben();

	cout << endl;

	//test bzgl gleichnamiger methode und ändern von dem rückgabetyp
	cout <<"test aendern von rueckgabetyp" <<endl;
	dat.fkt1(2);
	heute.fkt1(2);
	dat.ausgeben();
	cout << endl;
	heute.ausgeben();
	//ausgeben2 wurde genutzt dh ausgeben()const würde in der eigenen klasse überladen

	// test bzgl überladen von gleichnamigen methoden wenn paramterliste ungleich ist
	cout << endl;
	cout<<"test bzgl ueberladen von gleichnamigen methoden wenn paramterliste ungleich ist "<< endl;
	dat.ausgeben2Ueber(1);
	cout << endl;
	dat.ausgeben2Ueber(2.5);
	heute.ausgeben2Ueber(2.5);
	heute.ausgeben2Ueber(2);
	// ausgabe: alles wie gewohnt! hier ist passiert kein überladen an sich da man ja 
	//durch paramterliste indirekt die konkrete ausgabefkt wählt!

	//test überladen in basisklasse durch gleichnamige methode mit verschiedener paramterlist
	// UND überschreiben einer methode in basisklasse durch eine gleichnamige methode mit 
	//gleicher parameterliste aus abgeleiteter klasse ==> somit sollen alle anderen gleichnamigen
	// methoden verdeckt werden---> aber welche? die aus basisklasse??

	cout << endl;
	cout << "test ueberladen in basisklasse durch gleichnamige methode mit verschiedener paramterlist"
		<< endl;
	dat.ausgeben3Spezial(3.5);
	cout << endl;
	heute.ausgeben3Spezial(3.5);
*/

	/*
	// test bzgl aufgabenblatt 4 probeklausur aufg 2
	Basis* t[] = { new Spezialfall , new Basis };
	Spezialfall* t[] = { new Spezialfall('1'), new Basis('2') };
	Basis t[] = { new Spezialfall , new Basis('1') };
	Spezialfall* t[] = { new Spezialfall , new Spezialfall('1') };
	*/




	system("pause");
	return 0;
}