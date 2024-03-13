
class Vektor2d
{
	/*private attribute, das macht der unterstrich automatisch*/

	//komponenten des objekts
	//konvention: private variablen beginnen mit 
	double _x, _y;

public: // alles ab hier macht es sichtbar also nicht mehr privat!somit kann
		//man x und y auslesen

	/* get methoden = auslesen dh geben info über zustand von objekt */
	


	//als anwender in main kann man das x lesen aber die fkt nicht verändern!
	//gib x-komponente aus
	double x()
	{

		return _x;
	}

	//gib y-komponente aus
	double y()
	{

		return _x;
	}

	//berechne euklidische norm des objekts
	double norm()
	{


		return sqrt(_x * _x + _y * _y);
	}

	/* set methoden */

	//weise objekt von koordinaten zu

	void setze(double x, double y)
	{
		_x = x;
		_y = y;


	}

	/* ausgabemethoden */

	//gib objekt formatiert auf datenstrom aus

	void gibAus( ostream& ostr)	// datenstrom wird immer per referenz festgelegt !!
	{

		ostr << " ( " << _x << " , " << _y << " ) ";

	}


	/* interaktionsmethoden*/

		//vergleiche objekt mit argument lexikografisch
		//ergebnis: -1 wenn objekt < vek
		//			0 wenn ibjekt = vek
		//			1 wenn objekt > vek ist

	int vergleiche(Vektor2d const& vek);	// immer const& wenn es nur gelesen wird!!!
	// diese fkt wurde in die cpp datei ausgelagert

	//vertausche inhalte von objekt und vek
	void vertausche(Vektor2d& vek);
		




};//class Vektor2d