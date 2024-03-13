
#ifndef Punkt.h
#define PUNKT_H



class Punkt {

public:
	Punkt();
	~Punkt();

	//getter und setter
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	int getEcke() const;

	//andere methoden
	void verschieben(double,double);


private:
	double xKomp;
	double yKomp;


};

#endif // !Punkt.h