/*
array
zeiger

*/
#include "ArrayZeigerFkt.h"

}

int main()
{
	/*
	EIGENTLICH m�sste ich hier zeiger skript durchgegangen sein ABER hab das in prog2a projekt geschrieben!
	
	
	*/



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
	// ausgabe aller elementen aus zahlen array NUR mit for schleife m�glich
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

	





	return 0;
}