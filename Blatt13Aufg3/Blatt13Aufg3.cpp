/*
Was passiert, wenn Sie es laufen lassen?
 Haben Sie eine Erklarung dafur?
 Was mussen Sie andern, damit es sich so verhalt wie erwartet?
 Welche allgemeine Lehre ziehen Sie daraus im Umgang mit double-Werten?

begründung: entsteht durch rundungsfehler daher muss man IMMER mit ungleichungen
bei c++ arbeiten damit keine endlosschleifen passieren!




*/



#include <iostream>
using namespace std;

int main()
{
	for (double d = 0. ; d < 1. ; d += 0.1)
		cout << d << endl;
	return 0;
}