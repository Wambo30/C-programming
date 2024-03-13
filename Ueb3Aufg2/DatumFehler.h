/*
*  DatumFehler .h
*  Programmieren IIb - Uebung 3, Aufgabe 2
*
*/

#ifndef DatumFehler _H
#define DatumFehler _H

class DatumFehler {
public:
	DatumFehler (int t, int m, int j);
	virtual	void meldung() const;

protected:
	int tag, monat, jahr;
};

class InvalidDayError : public DatumFehler  {
public:
	InvalidDayError(int t, int m, int j);
	virtual	void meldung() const;
};

class InvalidMonthError : public DatumFehler  {
public:
	InvalidMonthError(int t, int m, int j);
	virtual	void meldung() const;
};

class InvalidYearError : public DatumFehler  {
public:
	InvalidYearError(int t, int m, int j);
	virtual	void meldung() const;
};


#endif //DatumFehler _H
