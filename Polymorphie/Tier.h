#ifndef Tier_h
#define Tier_h

class Tier
{
public:
	virtual void essen() const;
};

#endif

class Hund: public Tier
{
public:
	void essen() const;
};

class Katze :public Tier
{
public:
	void essen() const;
};

class Tiger:public Katze
{
public:
	void essen() const;
};

class Tierarzt
{
public:
	void diaetAnordnen (Tier t);
};