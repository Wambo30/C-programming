
#include <iostream>
using namespace std;

class Ampel
{

	bool _rot, _gelb, _gruen;

public:
	/*** konstruktoren ****/

	//standardkonstuktor

	Ampel()
	{
		setzeRot();
	}

	/***** get methoden = auslesen dh geben info über zustand von objekt ****/

	//als anwender in main kann man das x lesen aber die fkt nicht verändern!
	//gib x-komponente aus
	bool hatRot() const
	{
		return _rot;
	}

	bool hatGelb() const
	{
		return _gelb;
	}

	bool hatGruen() const
	{
		return _gruen;
	}



	bool istRot()	const
	{
		if (_rot == true)
			return true;
		else
			return false;

	}

	bool istRotGelb() const
	{
		if (_rot == true && _gelb == true)
			return true;
		else
			return false;
	}

	bool istGelb() const
	{
		if (_gelb == true)
			return true;
		else
			return false;
	}

	bool istGruen() const
	{
		if (_gruen == true)
			return true;
		else
			return false;
	}

	/**** set methoden ****/
	//weise objekt von koordinaten zu

	void setzeRot()	// setzt auf rot
	{
		if (_gelb == true)
			 _gelb = false;
		_rot = true;
			_gruen = false;
	
	}

	/***interaktionsmethode ****/
	void operator ++();


	


};//klasse ende


/***globale fkt: ausgabefkt ****/

	void operator <<(ostream& ostr, Ampel const& ampel); const

