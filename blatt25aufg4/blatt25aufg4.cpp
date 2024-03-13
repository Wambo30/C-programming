#include <iostream>
#include <string>
#include <fstream> // für lesen und schreiben in datenströmen/dateien

using namespace std;

bool schreibeNeu(string const& inputName)
{
	string nachname;
	string vorname;
	ifstream inputDatei(inputName);	// ifstream == input f stream == lesen
	ofstream outputDatei("neu_" + inputName );	// ofstream == output stream == schreiben
	// "neu" + inputName --> da wenn man "neu" am ende von input name schreeibt, dann denkt compiler
	// das neu ein datei typ ist ==> dh alles nach punkt von dateiname --> typ von datei

	if ( !outputDatei )	// guckt ob datei was enthält und öffnet sie
	{
		cerr << "kann datei" << inputName << "nicht öffnen" << endl;
	}

	while (inputDatei >> nachname >> vorname)	// guckt ob datei was enthält und öffnet sie
	{
	
		
		//datei >> nachname ;	//compiler sieht den string bis zum ersten leerzeichen als nachname
		//datei >> vorname;
		/***************************************************************************************
		--> bei folgender schreibweise wird letzter eintrag aus datei zweimal ausgegeben
		while(datei)
		{
		datei >> nachname;
		datei >> vorname;
		.... usw.

		}

		ABER bei folgender schreibweise wird alles nur EINMAL ausgegeben:
		while( datei >> nachname >> vorname )
		{
			int laengeNachname = nachname.size();
			nachname.erase( laengeNachname - 1);

		cout << nachname + vorname << endl;
		}
		==> dh bei einlesen der dateien im while kopf ==> bestes ergebnis

		********************************************************************************************/

		int laengeNachname = nachname.size();
		nachname.erase( laengeNachname - 1);

		outputDatei << nachname <<char(9) << char(9) << vorname << endl;	
		//char(9) == tabulator nach ascii 
	}
	

	
	
	

	//9 = horizontal tab
	//10 = enter/zeilenumbruch
	
	// datei << endl;

	inputDatei.close();
	outputDatei.close();

	/*

	ofstream datei(inputName);	// ofstream == output stream == schreiben

	if (datei)	// guckt ob datei was enthält und öffnet sie
	{
		datei << vorname;
		datei << nachname;


	}
	else
		cerr << "kann datei" << inputName << "nicht schreiben" << endl;



	datei << endl;

	datei.close();

*/
	return true;
}



int main()
{
	string name2 = "namen.txt"; // dateiname nochmal seperat mit variable initialisieren!!
	schreibeNeu(name2);



	return 0;
}