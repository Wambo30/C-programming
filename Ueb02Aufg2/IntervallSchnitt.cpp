//
//  IntervallSchnitt.cpp
//  Intervall


class Intervall {
public:
	virtual ~Intervall();

	Grenze getLinks() const;
	Grenze getRechts() const;
	void setLinks(const Grenze&);
	void setRechts(const Grenze&);
	bool istLeer() const;
	void setLeer(bool);

	virtual bool istGleich(const Intervall&) const;
	virtual bool istTeilmengeVon(const Intervall&) const;

	virtual bool enthaelt(const double&) const = 0;
	virtual bool istEchteTeilmengeVon(const Intervall&) const = 0;
	virtual void durchschnitt(const Intervall&);

protected:
	Grenze links, rechts;
	bool leer;
};

void Intervall::durchschnitt(const Intervall& b) {
	Intervall* a = this;
	Intervall* c;
	Grenze alinks = a->getLinks();
	Grenze arechts = a->getRechts();
	Grenze blinks = b.getLinks();
	Grenze brechts = b.getRechts();
	if (arechts < blinks || brechts < alinks) {
		c = new OIntervall(1, -1); // leer
	}
	else {
		Grenze links = max(alinks, blinks);
		Grenze rechts = min(arechts, brechts);
		switch (links.getKlammer()) {
		case '(': if (rechts.getKlammer() == ')') {
			c = new OIntervall(links.getWert(), rechts.getWert());
		}
				  else {
					  c = new LOIntervall(links.getWert(), rechts.getWert());
				  }
				  break;
		case '[':  if (rechts.getKlammer() == ')') {
			c = new ROIntervall(links.getWert(), rechts.getWert());
		}
				   else {
					   c = new AIntervall(links.getWert(), rechts.getWert());
				   }
				   break;
		case '{': c = new AIntervall(links.getWert());
			break;
		}
	}
	*this = *c;
	delete c;
}

