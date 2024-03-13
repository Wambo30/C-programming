
#include <iostream>
using namespace std;


void tuWas(int k) {
	if (k % 2) {
		cout << "Alles Ok!" << endl;
	}
	else {
		throw k;
	}
}



int main() {

	for (int i = 0; i < 5; i++) {
		try {
			switch (i) 
			{
			case(0): throw "Ein Text";
			case(1): tuWas(4);
			case(2): throw 'x';
			case(3): throw 3.1415;
			case(4): throw string("Ein String ");
			case 5: throw "sei leise";
			}
		}
			catch (double wert) { cout << i << " : " << wert << endl; }
			catch (int wert) { cout << i << " : " << wert << endl; }
			catch (...) { cout << i << ": Default" << endl; }
	}



	system("pause");
	return 0;
}