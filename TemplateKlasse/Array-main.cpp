// Array-main.cpp

#include "Array.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

	vector<int> zahlen(5);
	for (int i = 0; i < zahlen.size(); i++) {
		zahlen[i] = i * 6;
	}

	for (int i = 0; i < zahlen.size(); i++) {
		cout << zahlen[i] << endl;
	}

	zahlen.push_back(100);

	for (int i = 0; i < zahlen.size(); i++) {
		cout << zahlen[i] << endl;
	}


	///*
	Array<int> a(3, -2);

	cout << a[2] << endl;
	a[2] = 4;
	

	Array<double> b(3, -2.5);

	cout << b[2] << endl;
	b[2] = 4;
	


	Array<> c(3, -2); //weil int defaulttyp ist

	cout << c[2] << endl;
	c[2] = 4;
	
//*/
	system("pause");
	return 0;
}
