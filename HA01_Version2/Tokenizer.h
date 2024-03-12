
using namespace std;
#include <iostream>

namespace Tokenizer {

	enum token_kind {
		NUMBER,
		ADD = '+', SUB = '-', MUL = '*', DIV = '/',
		END_OF_INPUT
	};

	extern token_kind current_token;
	extern double current_number;

	void get_next_token();

}


///*
namespace Tokenizer {

	token_kind current_token;
	double current_number;

	void get_next_token() {
		char c = 0;
		std::cin >> c;

		switch (c) {

		case 0:
			current_token = END_OF_INPUT;
			return;

		case '+': case '-': case '*': case '/':
			current_token = token_kind(c);
			return;

		case '0':  case '1':  case '2':  case '3':
		case '4':  case '5':  case '6':  case '7':
		case '8':  case '9':
		case '.':
			std::cin.putback(c);
			std::cin >> current_number;
			current_token = NUMBER;
			return;
		}
	}

}
//*/