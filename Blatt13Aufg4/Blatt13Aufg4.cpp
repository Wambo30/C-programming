/*
ROT13.
Es gibt bei Ratselzeitschriften die Methode, eine Losung auf dem Kopf zu drucken,
um sie nicht direkt lesbar zu machen. In Internetforen wird zu diesem Zweck der Code
ROT13 verwendet.
ROT13 unterscheidet alle ASCII-Zeichen in drei Kategorien: Kleinbuchstaben, Großbuchstaben
und Sonstige. Letztere werden gar nicht verandert, die beiden Buchstabenarten werden in jeweils
gleicher Weise verandert:
Buchstabe
a   b   c   d   e   f   g   h   i   j    k   l   m
n   o   p   q   r   s   t   u   v   w   x    y    z
ROT13-Code
n   o   p   q   r   s   t   u   v   w   x    y    z
a   b   c   d   e   f   g   h   i   j    k   l   m
Buchstabe
A  B  C  D  E  F  G  H   I    J   K  L  M
N  O  P  Q  R  S  T  U   V    W   X  Y  Z
ROT13-Code
N  O  P  Q  R  S  T  U  V  W  X  Y  Z
A  B  C  D  E  F  G  H   I    J   K  L  M
Das  ganze  Alphabet  wird  in  sich  rotiert,  d.h.  alle  Buchstaben  rucken  zyklisch  
um  13  Platze weiter. Nach ‘z’ beginnt die Zahlung wieder von vorn mit ‘a’. 
Mehr Information unter
http://de.wikipedia.org/wiki/ROT13
Schreiben Sie eine Funktion
char rot13 ( char zeichen )
die ein ASCII-Zeichen als Input bekommt und mit ROT13 transformiert wieder zuruck gibt. 
Sie kann dann sowohl ver- als auch entschlusseln. Ein Satz kann auf der Tastatur 
hintereinander weggeschrieben werden. Erst das Drucken der ENTER-Taste lost das Lesen aus. 
Damit die ganze
Zeile eingelesen wird, konnen Sie in
main()
eine Endlosschleife verwenden:

while ( true )
{
// lies ein Zeichen von der Tastatur ein
char zeichen ;
cin >> noskipws >> zeichen ;  // noskipws beachtet Leerzeichen
// Abbruch, wenn ein Und-Zeichen gefunden wird
if ( zeichen == ’&’ )
break ;
// wandle zeichen durch ROT13 um
cout << rot13( zeichen ) ;
}

*/

char rot13(char zeichen)
{
	char zeichen;
	if (("a" <= zeichen  &&  zeichen <= "m")
		|| ("A" <= zeichen  &&  zeichen <= "M"))
		zeichen += 13;
	if (("n" <= zeichen  &&  zeichen <= "z")
		|| ("N" <= zeichen  &&  zeichen <= "Z"))
		zeichen -= 13;
	return zeichen;
}


#include <iostream>
using namespace std;

int main()
{
	
	while (true)
	{
		// lies ein Zeichen von der Tastatur ein
		char zeichen;
		cin >> noskipws >> zeichen;  // noskipws beachtet Leerzeichen
									 // Abbruch, wenn ein Und-Zeichen gefunden wird
		if (zeichen == "&")
			break;
		// wandle zeichen durch ROT13 um
		cout << rot13(zeichen);
	}


// KEINE ahnung was hier falsch ist --> selim fragen!!!

	return 0;
}
