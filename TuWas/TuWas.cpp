/* tuwas.cpp */
#include <iostream>
using namespace std;

void tuWas(int k) {
	if (k % 2 == 1) { cout << "Alles OK!" << endl; }
	else { throw k; }
}

int main(void) {
	for (int i = 1; i < 5; i++) {
		try {
			cout << i << ". Versuch : ";
			tuWas(i);
			cout << i << ". Versuch beendet!" << endl;
		}
		catch (int z) { cout << "Ich mag " << z << " nicht! " << endl; }
	}

	system("pause");
	return 0;
}






