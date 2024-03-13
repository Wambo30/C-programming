/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

/* Person */
class Person {
public:
	Person();
	//Person(string);
	//string email;
	void setName(string s);
	void setAdresse(string s);
	void setEmail(string s);
	string getName() const;
	string getAdresse() const;
	string getEmail() const;

private:
	string name;
	string adresse;
	string email;
};

/* Student */
class Student : public Person {
public:
	Student();
	void setMatrikelnummer(int);
	int getMatrikelnummer() const;
private:
	int matrikelnummer;
};

/* Online-Student */
class OnlineStudent : public Student {
public:
	void setOnlineZugang(string);
	string getOnlineZugang() const;
private:
	string onlineZugang;
};

/* Angestellte */
class Angestellte : public Person {
public:
	void setPersonalnummer(string s);
	string getPersonalnummer() const;
	void ausgeben() const;
private:
	string personalnummer;
};

/* Dozent */
class Dozent : public Angestellte {
public:
	void setFachbereich(int i);
	int getFachbereich() const;
	void ausgeben() const;
private:
	int fachbereich;
};

/* Verwaltung */
class Verwaltung : public Angestellte {
public:
	void setAbteilung(string s);
	string getAbteilung() const;
private:
	string abteilung;
};
#endif // PERSON_H
