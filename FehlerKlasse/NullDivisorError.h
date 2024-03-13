#pragma once

class NullDivisorError
{
public:
	NullDivisorError(double);
	//~NegativNumberError();

	void meldeFehler() const;

private:
	double wert;


};