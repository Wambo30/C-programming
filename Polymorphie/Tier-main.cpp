#include "Tier.h"
#include <iostream>
using namespace std;


int main() {

	Tierarzt arzt;
	Hund hund;
	Katze katze;
	Tiger tiger;
	
	//statisches array 
	Tier tiere[] = { hund , katze , tiger };

	//hier zeigt zeiger auf adressen der objekte hund,katze,tiger
	 Tier* ztiere[] = { &hund , &katze , &tiger };
	
	 hund.essen(); 
	 //hund::essen() ==>Ausgabe: Hund:Knochen
	 //Warum? da die gleichnamige methode mit gleicher parameterliste jene identische 
	 //methode in der basisklasse überschrieben hat!

	 arzt.diaetAnordnen(katze);
	// t.essen() ==> Ausgabe: Katze:Milch

	 cout << "bei tiere array" << endl;
	 for (int i = 0; i < 3; i++) {
		 tiere[i].essen();
	 }
	 

	 /*
	 Ausgabe:
	 Tier:Futter
	 Tier:Futter
	 Tier:Futter
	 
	 ==>Warum? da das objekt tiere von der Basisklasse Tier erzeugt wurde!
	 --> somit nutzt man also die methode Tier::essen() und NICHT jende der einzelnen
	 objekte!!

	 */
	

	 cout << "bei *ztiere array" << endl;
	 for (int i = 0; i < 3; i++) {
		 ztiere[i]->essen();
	 }
	 

	 /*
	 Ausgabe:
	 Tier:Futter
	 Tier:Futter
	 Tier:Futter
	 
	 ==>Warum? da das objekt tiere von der Basisklasse Tier erzeugt wurde!
	 --> somit nutzt man also die methode Tier::essen() und NICHT jende der einzelnen
	 objekte!!

	 */

	 //eigene tests bzgl überschreiben

	 cout << endl;
	 cout << "hier mach ich eigene tests wegen ueberschreiben" << endl;
	 Tier tier1;
	 Hund hund1;
	 Katze katze1;
	 tier1.essen();
	 hund1.essen();
	 cout << endl;

	 tier1 = hund1;
	 hund1.essen();

	 cout << endl;
	 Tiger tiger1;
	 katze1 = tiger1;
	 katze1.essen();
	 cout << endl;

	 //tests wo ich guck ob virtual auch ohne zeiger funktioniert
	 cout << "tests wo ich gucke ob virtual auch OHNE zeiger geht" << endl;
	 
	 Tier tier2;
	 Hund hund2;
	 Katze katze2;
	 Tiger tiger2;
	 
	 tier2.essen();
	 hund2.essen();
	 katze2.essen();
	 tiger2.essen();
	 
	 cout << endl;
	 cout << "eigenes array mit zeiger" << endl;
	 Tier *ztiere2[] = { &hund2,&katze2,&tier2,&tiger2 };

	 for (int i = 0; i < 4; i++) {
		 ztiere2[i]->essen();
	 }
	 cout << endl;
	 //test bzgl statischer bindung wegen array
	 cout << "test bzgl statischer bindung wegen array" << endl;
	 
	 Tier tier3;
	 Hund hund3;
	 Katze katze3;
	 Tiger tiger3;
	 
	 Tier tiere3[] = { tier3,hund3,katze3,tiger3 };

	 for (int i = 0; i < 4; i++)
		 tiere3[i].essen();

	 /*
	 Ausgabe:
	 Tier:Futter
	 Tier:Futter
	 Tier:Futter
	 Tier:Futter

	 ==>warum? obwohl virtual bei der überschriebene methode in der basisklasse steht,
	 wird hier IMMER die methode der basisklasse benutzt  und nicht jene der einzelnen
	 objekte aus den abgeleiteten klassen---> DA sie in einem statischen array aufgelistet
	 wurden!
	 ==> OHNE dem statischen array würden sie ihre eigenen methoden aufrufen!!
	 */


	system("pause");
	return 0;
}