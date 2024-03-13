#include <iostream>
#include "Aufg2.5_Struct.h"
using namespace std;

/*
struct Test1 {

	int zahl1;
	//int zahl2;
	const int& operator+=(const int&);


};

struct Test2 {

	//int zahl3;
	int zahl4;
	const int& operator+=(const int&);
};
*/

const int& Test1::Fkt1(const Test1& obj) {
	zahl1 = zahl1 + obj.zahl1 ;
	return zahl1;
}

const int Test2::Fkt2(const Test2 obj) {
	zahl4 = zahl4 + obj.zahl4;
	return zahl4;
}