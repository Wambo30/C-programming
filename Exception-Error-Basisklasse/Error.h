/* Error.h */
#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <iostream>
#include <exception>

using namespace std;


/******************************************************************************************/
class NegativeNumberError : public exception
{
public:
	NegativeNumberError(double);
	virtual ~NegativeNumberError();
	virtual const char* what() const throw();

private:
	double zahl;
	char meldung[100];

};

/*******************************************************************************************/
class NullDivisionError : public exception
{
public:
	NullDivisionError();
	virtual ~NullDivisionError();
	virtual const char* what() const throw();
};

#endif // ERROR_H

