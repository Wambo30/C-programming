#ifndef StapelIstLeerFehler_h
#define StapelIstLeerFehler_h
#include <exception>
using namespace std;


class StapelIstLeerFehler : public exception {
	virtual const char* what() const throw();
};

#endif