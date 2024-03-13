#ifndef DatumStaticConst_h
#define DatumStaticConst_h

#include <iostream>
using namespace std;

class DatumStaticConst
{
public:
	static const int STARTJAHR = 1990;
	DatumStaticConst();
	DatumStaticConst(int,int,int);
	~DatumStaticConst();
	//setter und getter
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	int getTag() const;
	int getMonat() const;
	int getJahr() const;

private:
	int tag, monat, jahr;// wären sonst private mit getter/setter 


};
//kann man auch hier nutzen
//static const int STARTJAHR = 1990;
#endif

