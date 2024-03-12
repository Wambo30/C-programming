

#include <stdexcept> // Ausnahmebehandlung
#include <cstdlib>  // wegen size_t
#include <iostream> // Operator <<
using namespace std;

// Eine Klasse, die ein Element der Stack repraesentiert
template <typename T>
class LKnoten {
public:
	T  data;           // Der Datensatz eines Stacknelements
	LKnoten* next;     // Veweis auf den Nachfolger
};

// Die verkettete Stack
template <typename T> class Stack {
public:
	Stack();            // Standardkonstruktor
	// Kopierkonstruktor, Zuweisungsoperator, Destruktor
	Stack(const Stack<T>& l);
	Stack<T>& operator=(const Stack<T>& l);
	~Stack();

	// Getter fuer Anker
	LKnoten<T>* getAnker() const;

	LKnoten<T>* getNil() const;

	// Die Anzahl der Knoten
	size_t size() const;

	// Ist die Stack leer?
	bool empty() const;

	// Alle Knoten aus der Stack entfernen
	void clear();

	// Knoten mit dem Datensatz <data> am Anfang der Stack hinzufuegen
	void push(const T& data);

	// obersten Eintrag löschen 
	void pop();

	//LKnoten<T>* top() const;
	int top() ;


	// Knoten mit dem Datensatz <data> hinter dem Knoten,
	// auf das <curr> verweist, hinzufuegen
	LKnoten<T>* insert(LKnoten<T>* curr, const T& data);

	// Knoten hinter dem Knoten, auf das <curr> verweist, entfernen
	void erase(LKnoten<T>* curr);

	// Einen Datensatz in der Stack finden
	LKnoten<T>* find(const T& data) const;

	// Die Reihenfolge der Knoten umkehren
	void reverse();

	// Den Verweis (die Adresse) des letzten Knoten ermitteln
	LKnoten<T>* back() const;

private:
	LKnoten<T>* anker;  // Der Anker speichert die Andresse des ersten Knoten
	LKnoten<T>* nil;
};

// Standardmaessig wird eine leere Stack angelegt
template <typename T>
Stack<T>::Stack() : anker(NULL) { }

// Kopierkonstruktor
template <typename T>
Stack<T>::Stack(const Stack<T>& l) {
	anker = NULL;
	// ltemp naviegiert in der Stack l
	LKnoten<T>* ltemp = l.anker;
	// ntemp navigiert in der neuen Stack
	LKnoten<T>* ntemp = anker;
	// Stack l durchgehen und nacheinander Knoten in die neue Stack hinzufuegen
	while (ltemp != NULL) {
		ntemp = insert(ntemp, ltemp->data);    // this->insert()
		// Die Methode insert fuegt einen neuen Knoten hinzu
		// und gibt seine Adresse zurueck
		ltemp = ltemp->next;
	}
}

// Zuweisungsoperator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& l) {
	// Stack auf der linken Seite der Zuweisung loeschen
	clear();   // this->clear();
	// Stack auf der rechten Seite der Zuweisung an anker dranhaengen
	// wie im Kopierkonstruktor
	LKnoten<T>* temp = l.anker;
	LKnoten<T>* neutemp = anker;
	while (temp != NULL) {
		neutemp = insert(neutemp, temp->data);  // this->insert()
		temp = temp->next;
	}
	return *this;
}

// Im Destruktur wird nacheinader das erste Element
// geloescht und anker auf sein Nachfolger verweist
// bis das Ende der Stack erreicht ist
template <typename T>
Stack<T>::~Stack() {
	clear();    // this->clear()
}

// Getter auf anker
template <typename T>
LKnoten<T>* Stack<T>::getAnker() const { return anker; }

// Getter Nil
template<typename T>
LKnoten<T>* Stack<T>::getNil() const { return nullptr; }


// Die Anzahl der Elemente ermitteln
// -> alternativ ein Attribut verwenden und
// -> bei jedem Aufruf von insert, push, erase etc. aktualisieren
template <typename T>
size_t Stack<T>::size() const {
	size_t anzahl = 0;
	for (LKnoten<T>* temp = anker; temp != NULL; temp = temp->next) {
		++anzahl;
	}
	return anzahl;
}

// Ist die Stack leer?
template <typename T>
bool Stack<T>::empty() const {
	return (anker == NULL);
}

// Oberster Eintrag
template <typename T>
//LKnoten<T>* Stack<T>::top() const {
int Stack<T>::top() {
	//return anker;

	LKnoten<T>* temp = anker;
	LKnoten<T>* next = NULL;
	while (temp != NULL && temp->next != NULL) {
		// temp != NULL -> falls anker == NULL
		// wenn temp->next == NULL ist temp der letzte Knoten
		// seine Adresse brauchen wir, diese speichert sein Vorgaenger:
		// <next> der in der letzten Schleifeniteration
		next = temp->next;
		temp = temp->next;
	}
	int ausgabe=int(next);
	return ausgabe; // statt next


}

// obersten Eintrag löschen
template<typename T>
void Stack<T>::pop() {
	LKnoten<T>* tmp = new LKnoten<T>;
	tmp = anker;
	anker = anker->next;
	delete tmp;
}

// Alle Elemente aus der Stack loeschen
template <typename T>
void Stack<T>::clear() {
	LKnoten<T>* temp;
	// wenn anker gleich NULL ist, ist die Stack leer
	while (anker != NULL) {
		// den Verweis aus anker zum späteren Löschen sichern
		temp = anker;
		// anker auf den Nachfoger verweisen
		anker = anker->next;
		// den Knoten loeschen
		delete temp;
	}
}

// Knoten am Anfang der Stack hinzufuegen
template <typename T>
void Stack<T>::push(const T& d) {
	// einen neuen Stacknknoten anlegen
	LKnoten<T>* temp = new LKnoten<T>;
	// data setzen
	temp->data = d;
	// auf den Nachfolger verweisen
	// auf den zeigt momentan anker
	temp->next = anker;
	// anker verweist jetzt auf den neuen Knoten
	anker = temp;
}

// Knoten hinter dem Knoten, auf das <curr> verweist, hinzufuegen
// Wenn NULL, am anker anhaengen
template <typename T>
LKnoten<T>* Stack<T>::insert(LKnoten<T>* curr, const T& data) {
	if (curr != NULL) {
		// einen neuen Stacknknoten anlegen
		LKnoten<T>* temp = new LKnoten<T>;
		// data setzen
		temp->data = data;
		// der neue Knoten verweist auf den Nachfolger von curr
		temp->next = curr->next;
		// dann verweist curr auf den neuen Knoten
		curr->next = temp;
		return temp;
	}
	else {
		push(data);
		return anker;
	}
}

// Knoten hinter dem Knoten, auf das <curr> verweist, entfernen
template <typename T>
void Stack<T>::erase(LKnoten<T>* curr) {
	// wenn ueberhaupt etwas zu loeschen ist
	if (curr != NULL && curr->next != NULL) {
		// Die Adresse des zu loeschenden Knoten merken
		LKnoten<T>* temp = curr->next;
		// curr soll auf den Nachfolger von curr->next verweisen
		curr->next = temp->next;
		// Jetzt kann der Knoten geloescht werden
		delete temp;
	}
}

// Einen Datensatz in der Stack finden
// Zurueckgegen wird der Verweis auf den zuerst gefundenen Knoten,
// der diesen Datensatz enthaelt, wenn nicht gefunden -> NULL
template <typename T>
LKnoten<T>* Stack<T>::find(const T& d) const {
	for (LKnoten<T>* temp = anker; temp != NULL; temp = temp->next) {
		if (temp->data == d) {
			// Die Objekte vom Typ T muessen den Operator == ueberladen
			return temp;
		}
	}
	return NULL;
}

// Reihenfolge der Elemente in der Stack umdrehen
template <typename T>
void Stack<T>::reverse() {
	// aktuelle Stack kopieren und gleich danach loeschen
	Stack<T> l(*this);
	clear();

	LKnoten<T>* ltemp = l.anker;  // naviegiert durch l
	// Knoten aus Stack nacheinander am anker anhaengen
	while (ltemp != NULL) {
		push(ltemp->data);
		ltemp = ltemp->next;
	}
}

// Der Verweis auf den letzten Knoten
template <typename T>
LKnoten<T>* Stack<T>::back() const {
	LKnoten<T>* temp = anker;
	LKnoten<T>* next = NULL;
	while (temp != NULL && temp->next != NULL) {
		// temp != NULL -> falls anker == NULL
		// wenn temp->next == NULL ist temp der letzte Knoten
		// seine Adresse brauchen wir, diese speichert sein Vorgaenger:
		// <next> der in der letzten Schleifeniteration
		next = temp->next;
		temp = temp->next;
	}
	return next;
}

// Ueberladen von Ausgabe-Operator <<
template<typename T>
ostream& operator<<(ostream& ausgabe, const Stack<T>& l) {
	Stack<T> tmpList = l;
	tmpList.reverse();
	for (LKnoten<T>* temp = tmpList.getAnker(); temp != NULL; temp = temp->next) {
		ausgabe << "<" << temp->data << "> ";
	}
	return ausgabe;
}

template<typename T>
ostream& operator<<(ostream& ausgabe, const LKnoten<T>* l) {
	ausgabe << "<" << l->data << ">";
	return ausgabe;
}


