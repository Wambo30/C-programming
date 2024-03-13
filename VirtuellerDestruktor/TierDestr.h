#ifndef TierDestr_h
#define TierDestr_h
#include <iostream>

class TierDestr
{
public:
	TierDestr();
	virtual ~TierDestr();
};

class Hund2 : public TierDestr {
	Hund2();
	 ~Hund2();
private:
	int* knochen;
	int anzahlKnochen;

};

#endif