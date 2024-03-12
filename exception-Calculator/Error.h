/* Error.h */
#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <iostream>
using namespace std;

class Error {
public:
	Error(string op);
	virtual void meldeFehler() const;
    virtual ~Error();
protected:
	string ursache;
};

/****************/
class NegativeNumberError : public Error
{
public:
	NegativeNumberError(double);
    virtual ~NegativeNumberError();
};

/****************/
class NullDivisionError : public Error
{
public:
	NullDivisionError();
    virtual ~NullDivisionError();
};

#endif // ERROR_H

