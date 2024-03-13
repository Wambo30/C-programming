#pragma once
class TierAbstrakt
{
public:
	//rein virtuelle methode die nicht 
	//implementiert wird
	virtual void essen() const = 0;
	virtual void ausgeben()const=0;
	void ausgeben2()const;
};
//TierAbstrakt ist nun abstrakte klasse.wozu aber?
//man nutzt das um ein bestimmtes konzept vorzubereiten und
//in den abgeleiteten klassen weiter zu spezifizieren!!

class Hund3 : public TierAbstrakt {
public:
	virtual void essen() const;
	virtual void ausgeben()const;
};

class Katze3 : public TierAbstrakt {
public:
	virtual void essen() const;
	virtual void ausgeben()const;
};





class Tiger3 : public Katze3 {
public:
	virtual void essen() const;
	virtual void ausgeben()const;

};

class Tierarzt3 {
	void diaetAnordnen3(TierAbstrakt& t);
	virtual void ausgeben()const;
};