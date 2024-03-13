# include <cassert>
#include <iostream>
using namespace std;


class vector
{
public:
	//standardkonstr.
	
	vector(int s) : s(1) {
		data = new double[1];
		data[0] = s;
	} // statt new double [s]
	

	
	//kopierkonstruktor
	vector(const vector& that) : s(that.s) {
		// statt data(new double[s])
		data = new double[s]; // speicher reservieren
		for (int i = 0; i <= s; i++)
			data[i] = that.data[i];
	}
	
	
	//destruktor
	~vector() { 
		if (data != 0) {
			delete[] data;
			data = 0;
		}
	} // statt delete data
	

	//zuweisungsoperator
	vector& operator= (const vector& that) {
		//assert(s == that.s); //==> nicht nötig da vektor zueinander zugewiesen werden
		//können die verschiedene längen haben
		if (data) { delete[] data; }
		data = new double[that.s];
		

		for (int i = 0; i < that.s; i++) {
		data[i] = that.data[i];
		}

		//s= that.s; // muss nicht sein
		return *this; // statt this
	}
	

	//indexoperator
	/*
	const double& operator[] (unsigned i) const
	{
		return data[i]; // statt data(i)
	}
	*/

	double& operator[] (const unsigned i) 
	{
		return data[i]; // statt data(i)
	}

	//fkt um länge von data auszugeben
	unsigned size(const vector& v) { return v.s; } // statt v->s

private:
	 int s; // statt const , und s == länge
	double*  data; // statt const und double data[]
	
};

