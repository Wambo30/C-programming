/*
*  Matrix.cpp
*/

#include "Matrix.h"
#include <iomanip>

// Konstruktor mit Zufallswerten
Matrix::Matrix(size_t nz, size_t ns) : nzeilen(nz), nspalten(ns) {
	eintrag = new double*[nzeilen];
	for (size_t i = 0; i < nzeilen; i++) {
		eintrag[i] = new double[nspalten];
		for (size_t j = 0; j < nspalten; j++) {
			eintrag[i][j] = (rand() % 2001 - 1000) / 100.;
		}
	}
}

// Kopierkonstruktor
Matrix::Matrix(const Matrix& m) : nzeilen(m.nzeilen), nspalten(m.nspalten) {
	// Speichertplatz anfordern und Werte kopieren
	eintrag = new double*[nzeilen];
	for (size_t i = 0; i < nzeilen; i++) {
		eintrag[i] = new double[nspalten];
		for (size_t j = 0; j < nspalten; j++) {
			eintrag[i][j] = m.eintrag[i][j];
		}
	}
}

// Zuweisungsoperator
Matrix& Matrix::operator=(const Matrix& m) {
	// Speicherplatz freigeben
	for (size_t i = 0; i < nzeilen; i++)
		delete[] eintrag[i];
	delete[] eintrag;

	nzeilen = m.nzeilen;
	nspalten = m.nspalten;

	// Speichertplatz anfordern und Werte kopieren
	eintrag = new double*[nzeilen];
	for (size_t i = 0; i < nzeilen; i++) {
		eintrag[i] = new double[nspalten];
		for (size_t j = 0; j < nspalten; j++)
			eintrag[i][j] = m.eintrag[i][j];
	}
	return *this;
}

Matrix::~Matrix() {
	for (size_t i = 0; i < nzeilen; i++) {
		delete[] eintrag[i];
	}
	delete[] eintrag;
}

size_t Matrix::getNZeilen() const { return nzeilen; }
size_t Matrix::getNSpalten() const { return nspalten; }
double Matrix::getEintrag(size_t i, size_t j) const { return eintrag[i][j]; }
void Matrix::setEintrag(size_t i, size_t j, double wert) { eintrag[i][j] = wert; }


// Operatoren
Matrix& Matrix::operator+=(const Matrix& m) {
	if (nzeilen == m.nzeilen && nspalten == m.nspalten) {
		for (size_t i = 0; i < nzeilen; i++) {
			for (size_t j = 0; j < nspalten; j++)
				eintrag[i][j] += m.eintrag[i][j];
		}
	}
	else {
		cout << "FEHLER! Matrixaddition: falsche Dimension! " << endl;
	}
	return *this;
}

// Hilfsfunktion ffurs Multiplizieren von Matrizen
double skalarProdukt(double* u, double* v, size_t len) {
	double sum = 0;
	for (size_t i = 0; i < len; i++) {
		sum += u[i] * v[i];
	}
	return sum;
}

Matrix& Matrix::operator*=(const Matrix& m) {
	if (nspalten == m.nzeilen) {
		Matrix t(nzeilen, m.nspalten);
		for (size_t i = 0; i < nzeilen; i++) {
			double* zeile = new double[nspalten];
			for (size_t z = 0; z < nspalten; z++) {
				zeile[z] = eintrag[i][z];
			}
			for (size_t j = 0; j < m.nspalten; j++) {
				double* spalte = new double[m.nzeilen];
				for (size_t s = 0; s < m.nzeilen; s++) {
					spalte[s] = m.eintrag[s][j];
				}
				double wert = skalarProdukt(zeile, spalte, nspalten);
				t.setEintrag(i, j, wert);
				delete[] spalte;
			}
			delete[] zeile;
		}
		*this = t;
	}
	else {
		cout << "FEHLER! Matrixmultiplikation: falsche Dimension!" << endl;
	}
	return *this;
}

Matrix& Matrix::operator*=(double wert) {
	for (size_t i = 0; i < nzeilen; i++) {
		for (size_t j = 0; j < nspalten; j++) {
			setEintrag(i, j, wert*getEintrag(i, j));
		}
	}
	return *this;
}

ostream& operator<<(ostream& aus, const Matrix& m) {
	aus << endl << "Matrix " << m.getNZeilen() << "x" << m.getNSpalten() << endl;
	for (size_t i = 0; i < m.getNZeilen(); i++) {
		for (size_t j = 0; j < m.getNSpalten(); j++) {
			aus << setw(2) << m.getEintrag(i, j) << " ";
		}
		aus << endl;
	}
	return aus;
}

