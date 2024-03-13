

class Kreis : public Bezugspunkt {
public:
	Kreis(Kreis&);

	double getRadius()const;
	void setRadius(double);
	double flaecheBerechnen(Kreis&);
private:
	double radius;

};