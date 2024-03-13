#ifndef IndexFehler_h
#define IndexFehler_h
#include <iostream>
using namespace std;
#include <stdexcept>

class IndexFehler : public out_of_range
{
	IndexFehler();
};

#endif