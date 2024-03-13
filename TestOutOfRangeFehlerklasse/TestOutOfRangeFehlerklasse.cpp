#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string text = "Programmieren";
	try {
		
		cout << "text[0] = " << text.at(0) << endl;
		cout<< " text[20] = " << text.at(20) << endl;
		cout << " text[10] = " << text.at(10) << endl;
		}

	catch(out_of_range& e) {
		cout << e.what() << endl;
		}



		system("pause");
		return 0;


	



}