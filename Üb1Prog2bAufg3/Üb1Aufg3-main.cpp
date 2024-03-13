#include <iostream>
using namespace std;
#include "KlasseA.h"

int main() {

	KlasseA a,za;
	KlasseB b,zb;
	za = new KlasseA;
	delete za;
	za = new KlasseB;
	zb = new KlasseB;
	a =  za;
	b = a;
	a =  zb;
	delete za;
	za = &a;
	zb = za;
	za = &b;
	 za = a;
	b =  za;
	b =  zb;
	 zb = b;
	delete zb;
	zb = &a;
	KlasseA f[] = { &a , &b , za , zb };
	f[0] = a;
	delete za;
	delete zb;





	system("pause");
	return 0;
}