/*
*  Matrix.h
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>  // wegen size_t
#include <iostream>
using namespace std;

/* Die Basisklasse Matrix */

class Matrix {
	/*
	static const int MIN = 0.001;

	const static int MIN2 = 0.001;

	static double MIN3 = 0.001 const;

	int static const MIN4 = 0.001;
	*/

public:
	Matrix(size_t nz, size_t ns);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	~Matrix();

	size_t getNZeilen() const;
	size_t getNSpalten() const;
	double getEintrag(size_t, size_t) const;
	void setEintrag(size_t, size_t, double);

	Matrix& operator+=(const Matrix& m);
	Matrix& operator*=(const Matrix& m);
	Matrix& operator*=(double);

	// -=, +, -, * analog ueberladen wie in der Klasse Rational

private:
	size_t nzeilen;
	size_t nspalten;
	double** eintrag;
};

ostream& operator<<(ostream& aus, const Matrix& m);

#endif // MATRIX_H
