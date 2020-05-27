#include <iostream>
#include "Point.h"
#include "Figura.h"
#include "Square.h"
#include "Triangle.h"
#include "RegularPolygon.h"

int main()
{
	Square<double> kwadrat;
	Square<double> kw(0.0, 0.1, 0.2, 0.3);
	Square<Point<int>> a(Point<int>(0,3),Point<int>(0,6));
	Square<Point<int>> b(Point<int>(0, 3), Point<int>(0, 6), Point<int>(1, 3), Point<int>(2, 6));
	std::cout << b.area();
	Figure<int, 4>* f = new Square<Point<int>>(Point<int>(0, 3), Point<int>(0, 6), Point<int>(1, 3), Point<int>(2, 6));
	std::cout << "\n" << f->area();
	Figure<int, 3>* f2 = new Triangle<Point<int>>(Point<int>(0, 3), Point<int>(0, 6), Point<int>(2, 5));
	Triangle<Point<int>> trojkat(Point<int>(0, 3), Point<int>(0, 6), Point<int>(2, 5));
	std::cout << "\n" << trojkat.area();
	std::cout << "\n" << f2->area();
	Figure<int, 5>* f3 = new RegularPolygon<Point<int>, 5>(Point<int>(0, 5), Point<int>(0, 10));
	std::cout << "\n" << f3->area();
	RegularPolygon<Point<int>, 5> foremna(Point<int>(0, 5), Point<int>(0, 10));
	std::cout << "\n" << foremna.area();
	delete f;
	delete f2;
	delete f3;
	return 0;
}