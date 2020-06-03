#include <iostream>
#include "tests.h"

#define TESTS

int main()
{
	// tests for area method
	#ifdef TESTS
	RUNALLTESTS();

	// tests for instantination
	Point<int> p(1, 2);	// OK
	std::cout << p.x;
	//Point<std::string>("dsa", "DSA");	// ERROR - must be numeric
	//Figure<int, 5> figure;	// ERROR - cannot instantinate abstract class
	Figure<int, 4>* f_sq = new Square<Point<int>>(Point<int>(1, 2), Point<int>(3, 5));	//OK
	Figure<int, 3>* f_tr = new Triangle<Point<int>>(Point<int>(1, 2), Point<int>(3, 5), Point<int>(2, 1));	//OK
	Figure<int, 5>* f_rp = new RegularPolygon<Point<int>, 5>(Point<int>(1, 2), Point<int>(3, 5));	//OK
	delete f_sq;
	delete f_tr;
	delete f_rp;
	#endif // TESTS

	return 0;
}
