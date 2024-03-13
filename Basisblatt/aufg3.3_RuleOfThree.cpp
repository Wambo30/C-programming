// Basiswissen C++
// Copy-Ctor, Dtor und assignment operator
// Aufg3.3
#include "aufg3.3_RuleOfThree.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;



//globale methoden-konstanten
// mCounter == rein stat. attribut was auﬂerhalb von klasse initialisiert wurde
int Point2d::mCounter = 0;

Point2d Point2d::tuwas1(Point2d pnt)
{
	cout << "\ttuwas1" << endl;
	return pnt;
}

Point2d& Point2d::tuwas2(Point2d & pnt)
{
	cout << "\ttuwas2" << endl;
	return pnt;
}


void Point2d::uebung3_3()
{
	cout << "=== Start ===" << endl;
	Point2d pnt1(1, 2);

	cout << "=== 1 ===" << endl;
	Point2d pnt2 = pnt1;

	cout << "=== 2 ===" << endl;
	Point2d pnt3(pnt1);

	cout << "=== 3 ===" << endl;
	Point2d pnt4(3, 4);

	cout << "=== 4 ===" << endl;
	pnt1 = pnt4;

	cout << "=== 5 ===" << endl;
	pnt3 = tuwas1(pnt1);

	cout << "=== 6 ===" << endl;
	pnt3 = tuwas2(pnt4);

	cout << "=== End ===" << endl;
}
