

# include<iostream>
namespace math {
	double inline foo(double x) { return 2 * x; }
	double inline foo2(double x) { return foo(x); }
}

namespace math1 {
	double inline foo(double x) { return 3 * x; }

	struct dd { double d; };

	double inline foo(dd x) { return 4 * x.d; }

	namespace ns {
		double inline foo2(double x) { return foo(x); }
	}

	namespace ns2 {
		double inline foo2(double x) { using math::foo; return foo(x); }
	}
}

void uebung8_1() {
	using math::foo; using math1::ns::foo2;

	std::cout << foo(6.0) << "\n";
	std::cout << foo2(6.0) << "\n";
	std::cout << math1::foo(6.0) << "\n";

	math1::dd x; x.d = 6.0;
	std::cout << foo(x) << "\n";
	{
		using namespace math;
		std::cout << foo(6.0) << "\n";
		std::cout << foo2(6.0) << "\n";
	}

	{
		using  math1::foo; using math::foo2;
		std::cout << foo(6.0) << "\n";
		std::cout << foo2(6.0) << "\n";
	}

	std::cout << foo(6.0) << "\n";
	std::cout << foo2(6.0) << "\n";
	std::cout << math1::ns2::foo2(6.0) << "\n";
}
