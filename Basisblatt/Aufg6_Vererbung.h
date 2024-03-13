# include <iostream>
using namespace std;


class Animal {
public:
	virtual ~Animal() { cout << " die " << endl; }
	virtual void move() = 0;
};

class Fish : public Animal {
public:
	~Fish() { cout << " turn upside down " << endl; }
	virtual void move() { cout << " swimm " << endl; }
};

class Bird : public Animal {
public:
	virtual void move() { cout << " fly " << endl; }
};

class Penguin : public Bird {
public:
	~Penguin() { cout << " freeze " << endl; }
	virtual void move() { cout << " swimm or talk " << endl; }
};



