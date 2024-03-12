#include "Tokenizer.h"
#include <iostream>
#include <string>
#include "Stack.h"
using namespace Tokenizer;
using namespace std;
#include <istream>
//using leda::stack;
	//using leda::set_error_handler;
	//using leda::leda_exception;


int main() {
//#include <LEDA/stack.h>
//#include <LEDA/error.h>
//#include "Tokenizer.h"
//#include <iostream>



	
		//set_error_handler(leda::exception_error_handler);

	Stack<char> S; //= new Stack <char>;
		//S->push(8);
		//S->push(1);
		//S->push(2);

		//cout << "ausgabe top:" << S->top() << endl;

		//S.push(4);

		get_next_token();

		while (current_token != END_OF_INPUT) {
			if (current_token == NUMBER)
				S.push(current_number);
			else
			{ 
				//try {
				int num1 = S.top();
				S.pop();
				int num2 = S.top();
				S.pop();

				switch (current_token) {
				case ADD:
					S.push(num2 + num1);
					break;
				case SUB:
					S.push(num2 - num1);
					break;
				case MUL:
					S.push(num2 * num1);
					break;
				case DIV:
					S.push(num2 / num1);
					break;
				}
			}
			/*
			catch (leda_exception e) {
				std::cerr << e.get_msg() << std::endl;
				std::cerr << e.get_num() << std::endl;
				std::cerr << "Too few numbers in expression." << std::endl;
				exit(1);
			}
			*/
			
			get_next_token();
		}

		if (S.size() != 1) {
			std::cout << "Too few operators in expression." << std::endl;
			exit(1);
		}
		//else std::cout << S.pop() << std::endl;
	








	return 0;
	system("pause");
}