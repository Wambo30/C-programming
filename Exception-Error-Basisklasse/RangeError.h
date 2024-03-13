#pragma once

#include <stdexcept>
using namespace std;


class RangeError : public out_of_range
{
public:
	RangeError();
	~RangeError();
};

