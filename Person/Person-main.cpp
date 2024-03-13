/* Person-Main.cpp */
#include "Person.h"

int main(void) {
	Angestellte mitarbeiter;

	mitarbeiter.setName("Eric Ditlind");
	mitarbeiter.setPersonalnummer("E078");

	/* Zuweisungskompatibilität */
	Person person;
	person = mitarbeiter;
	//mitarbeiter = person;

	Student st;
	Dozent dz;
	dz.setAdresse("Berlin");
	dz.setName("John");

	dz.Angestellte::ausgeben();

	/*
	wenn 
	Student();
	Person();
	dann wird zuerst
	Person und dann Student zerstört--> von außen nach innen
	*/


	system("pause");
	return 0;
}
