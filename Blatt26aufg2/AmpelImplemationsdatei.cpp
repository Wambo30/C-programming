#include "Ampel.h"

void Ampel::operator ++()
{
	if (istGruen())
		//schalte auf gelb
	{
		_gruen = false;
		_gelb = true;
		_rot = false;
	}

	if (istGelb())
		//schalte auf rotgelb
	{
		_gruen = false;
		_rot = true;
		_gelb = true;
	}
	if (istRotGelb())
		//schalte auf rot
	{
		_gruen = false;
		_rot = true;
		_gelb = false;

	}


	if (istRot())
		//schalte auf grün
	{
		_rot = false;
		_gruen = true;
		_gelb = false;

	}
		

		
}
void operator <<(ostream& ostr, Ampel const& ampel)
{
	char ausgabe[] = "[   ]";
	if (hatRot())
		ausgabe[1] = '*';
	if (hatGelb())
		ausgabe[2] = '*';
	if (hatGruen())
		ausgabe[3] = '*';
	return ostr << ausgabe;

}



/*
void operator <<(ostream& ostr, Ampel const& ampel) 
{
	if (istGruen())
	{
		ostr << "GRUEN" << endl;
	}

	else if (istGelb())
	{
		ostr << "GELB" << endl;
	}

	else if (istRot())
	{
		ostr << "ROT" << endl;
	}

	else if (istRotGelb())
	{
		ostr << "ROTGELB" << endl;
	}

	else
		cerr << "?" << endl;
}


*/