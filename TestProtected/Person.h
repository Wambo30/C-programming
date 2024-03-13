#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person {

public:
	string email;
	void setName(string);
	void setAdresse(string);
	string getName() const;
	string getAdresse() const;

protected:
	string adresse;
private:
	string name;
};

#endif // !PERSON_H

class Angestellte : public Person {
public:
	void setPersonalnr(string);
	void ausgeben() const;
	void ausgeben2() const;
private:
	string personalnr;

};