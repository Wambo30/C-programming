#pragma once

class Punkt {

public:
	Punkt();
	Punkt(double, double);
	~Punkt();

//get und set methoden

	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;

// andere methoden
	void verschieben(double, double);
	void spiegelnAnX();
	void spiegelnAnY();
	void amUrsprungDrehen(double winkel);

private:

	double x; // x-koordinate
	double y; // y-koordinate

};

