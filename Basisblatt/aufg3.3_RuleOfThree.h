// Basiswissen C++
// Copy-Ctor, Dtor und assignment operator
// Aufg3.3

#include <iostream>
using namespace std;
using std::cout;
using std::endl;


class Point2d
{
public:
	// Standard Ctor
	Point2d() : mId(mCounter++) {
		cout << "\tPoint2d::Ctor - Point2d_" << mId << endl;
	}

	// Ctor( double, double )
	Point2d(double u, double v) : mId(mCounter++), mX(u), mY(v) {
		cout << "\tPoint2d::Ctor(double, double) - Point2d_" << mId << endl;
	}

	// Cpy Ctor
	Point2d(const Point2d & crOrig) : mId(mCounter++), mX(crOrig.mX), mY(crOrig.mY) {
		cout << "\tPoint2d::CpyCtor - Point2d_" << mId << endl;
	}

	// Dtor
	~Point2d() {
		cout << "\tPoint2d::Dtor - Point2d_" << mId << endl;
	}

	// Assignment operator
	Point2d & operator= (const Point2d & crRhs)
	{
		cout << "\tPoint2d::operator=  - Point2d_" << this->mId
			<< " = Point2d_ " << crRhs.mId << endl;

		if (this == &crRhs) return *this; // --------- 1

		mX = crRhs.mX;
		mY = crRhs.mY;
		return *this;
	}

	void uebung3_3();
	Point2d tuwas1(Point2d pnt);
	Point2d& tuwas2(Point2d& pnt);

private:
	static int mCounter;
	int mId;
	double mX;
	double mY;
};
// Ende Point2d
