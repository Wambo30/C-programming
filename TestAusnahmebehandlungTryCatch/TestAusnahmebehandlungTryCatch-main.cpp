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
	int i = 1;
	while (i < 5) {
		try {
			cout << i << ". Versuch: " ;
			tuWas(i);
			cout << i << ". Versuch beendet!" << endl;
		}
		catch (int z) {
			cout << " Ich mag " << z << " nicht! " << endl;
		}
		i++;
	}


	system("pause");
	return 0;

}