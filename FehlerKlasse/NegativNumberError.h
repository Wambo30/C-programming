#pragma once
class NegativNumberError
{
public:
	NegativNumberError(double );
	//~NegativNumberError();

	void meldeFehler() const;

private:
	double wert;


};

