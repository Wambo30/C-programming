#include "Natuerlich.h"
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

//Ersetze den strandard Konstruktor
Natuerlich::Natuerlich() 
{
    _laenge = 1;
    _ziffer = new int[_laenge];
    _ziffer[0] = 0;
}

//Ersttele ein Array mit lenght Nullen
Natuerlich::Natuerlich(size_t laenge) 
{
    _laenge = laenge;
    _ziffer = new int[_laenge];
}

//Kopierkonstruktor
Natuerlich::Natuerlich(Natuerlich const& nat) 
{
    _laenge = nat._laenge;
    _ziffer = new int[_laenge];
    for(size_t i = 0; i < _laenge; i++)
        _ziffer[i] = nat._ziffer[i];
}

//lese aus dem String eine Zahl heraus bis zur ersten nicht Zahl
Natuerlich::Natuerlich(string const &str) 
{
    size_t stelle = 0;
	// Geht durch str bis komplett durch oder erste nicht ziffer
    while (stelle < str.length() && str.at(stelle) >= '0' && str.at(stelle) <= '9') 
		stelle++;

	//sonderfall falls keine zahl enhalten
    if (stelle == 0) 
	{
		_laenge=1;
		_ziffer=new int[1];
		_ziffer[0]=0;
	}
	else
	{
		_laenge = stelle;
		_ziffer = new int[_laenge];
		//umwandel von char in int
		for (size_t i = 0; i < _laenge; i++) 
			_ziffer[i] = str[stelle - i - 1] - '0';
		//vordere Nullen weg streichen
		while (_ziffer[_laenge-1] == 0 && _laenge > 1) 
			--_laenge;
	}
}

// initialisiere Objekt mit dem Betrag des Zahlenwerts seines Arguments
Natuerlich::Natuerlich(long long zahl) 
{
	size_t stellen=0;
	long long zahl1=zahl;
	//länge der zahl
    while (zahl1 > 0) 
	{
        int letzteZiffer = zahl1 % 10;
        zahl1 = (zahl1) / 10;
		++stellen;
    }

    _laenge = stellen;
    _ziffer = new int[_laenge];

	//dezimalstellen werden übertragen
    for (size_t i = 0; i < _laenge; i++)
	{
		int letzteZiffer = zahl % 10;
        zahl = (zahl) / 10;
        _ziffer[i] = letzteZiffer;
    }
}

// Zuweisungoperator
void Natuerlich::operator=(Natuerlich const& nat) 
{
	//elemet löschen falls vorhanden
	if (this != NULL) 
		delete[] _ziffer;
	
    _laenge = nat._laenge;
    _ziffer = new int[_laenge];
	//alle werte werden zu gewiesen
    for(size_t i = 0; i <_laenge; i++)
        _ziffer[i] = nat._ziffer[i];
}


// addiere zahl1 + zahl2 zu einer neuen natuerlich-Zahl
// Ermittlung der Maximallänge der Zahlen
// die Länge des Ergebnisses wird um 1 Platz der Maximallänge erhöht
// Die Summe der beiden Zahlen werden gespeichert
// Wenn die Summe der beiden Zahlen größer 10 ist,
// dann wird das Zwischenergebnis mit 10 subtrahiert und das Endergebnis wird gespeichert.
Natuerlich Natuerlich::operator+(Natuerlich const &nat) const
{
    size_t maxLaenge = max(_laenge, nat._laenge);
    Natuerlich summe(maxLaenge + 1);
    size_t sum, ueberschlag = 0;
    
	for (size_t i = 0; i < maxLaenge + 1; i++) 
	{
        sum = ueberschlag;
        ueberschlag = 0;
        if (i < _laenge) 
            sum += _ziffer[i];
        if (i < nat._laenge) 
            sum += nat._ziffer[i];
        if (sum >= 10) 
		{
            ueberschlag = 1;
            sum -= 10;
        }
        summe._ziffer[i] = sum;
    }
    // ignoriere vordere Nullen
    while (summe._ziffer[summe._laenge-1] == 0 && summe._laenge > 1) 
        --summe._laenge;
    return summe;
}

//Multiplikation
Natuerlich Natuerlich::operator*(Natuerlich const &nat)const 
{
    size_t maxLaenge = _laenge + nat._laenge;
    Natuerlich produkt(maxLaenge);
	//array mit nullen füllen
	for( size_t i = 0; i < maxLaenge ; ++i)
		produkt._ziffer[i]=0;
	//alle zahlem mal nehmen   
    for( size_t i = 0; i < _laenge ; ++i)
		for( size_t j = 0; j < nat._laenge; ++j)
			produkt._ziffer[i+j] += _ziffer[i]*nat._ziffer[j];
		
	//überlauf variable
	int ueberlauf = 0;
	//überlauf verwalten
	for ( size_t i = 0; i < maxLaenge + 1; ++i)
	{	
		produkt._ziffer[i] += ueberlauf;
		//überlauf
		if ( produkt._ziffer[i] > 9)
		{	
			ueberlauf = produkt._ziffer[i] / 10;
			produkt._ziffer[i] %= 10;
		}
		else
			ueberlauf = 0;
	}
	//nullen wegstreichen
	while (produkt._ziffer[produkt._laenge - 1] == 0 && produkt._laenge > 1) 
        produkt._laenge--;

    return produkt;
}
 
//gebe String aus
ostream &operator<<(ostream &ostr, Natuerlich const &nat) 
{
	//ausgabe
	for (size_t i = 0; i < nat._laenge; i++) 
	{
        ostr << nat._ziffer[nat._laenge - 1 - i] ;
    }
    return ostr;
}

// gebe zurück, ob das Objekt einen geraden Zahlenwert hat
bool Natuerlich::istGerade() 
{
    if (_ziffer[0] % 2 == 0)
        return true;
    return false;
}

//Destruktor
Natuerlich::~Natuerlich() 
{
    delete[] _ziffer;
}

// gib die n. Fibonacci-Zahl als neue natuerlich-Zahl zurück
Natuerlich fibonacci(size_t n) 
{
    if( n == 0 || n == 1)
	{
        return Natuerlich((long long) n);
    }

    Natuerlich fi =long long(0);
    Natuerlich temp1 = long long (0);
    Natuerlich temp2= long long (1);

    for(size_t i = 1; i < n ; i++)
	{
        fi = temp1 + temp2;
        temp1 = temp2;
        temp2 = fi;
    }
    return fi;
}

// berechne Potenz x hoch n
Natuerlich potenz(Natuerlich const &nat, size_t n) 
{
    if(n <= 0)
	{
        return Natuerlich(long long(1));
    }
	else
	{
        Natuerlich temp(nat);
        return temp * potenz( nat, n-1);
    }
}

// berechne Fakultät n!
Natuerlich fakultaet(size_t n) 
{
    Natuerlich temp (long long(1));

    for(size_t i=2; i <= n; i++)
	{
        temp = temp* Natuerlich(long long(i));
    }

    return temp;
}

