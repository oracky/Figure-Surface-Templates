#include "Figura.h"
#include "Point.h"
#include "RegularPolygon.h"
#include "Square.h"
#include "Triangle.h"
#include "tests.h"
#include <cassert>
#include <iostream>


void test_static_Square_area()
{
	Square<int> s(1, 0, 1, 10);
	assert(s.area() == 100);
	std::cout << "Area test for Square<typename T>: passed\n";
}

void test_static_Point_Square_area()
{
	Square<Point<int>> s(Point<int>(1, 0), Point<int>(1, 10));
	assert(s.area() == 100);
	std::cout << "Area test for Square<Point<typename T>>: passed\n";
}

void test_polymorphism_Square_area()
{
	Figure<double, 4>* f = new Square<double>(1.0, 0.0, 1.0, 10.0);
	assert(f->area() == 100.0);
	Figure<float, 4>* f2 = new Square<Point<float>>(Point<float>(1.0f, 0.0f), Point<float>(1.0f, 10.0f));
	assert(f2->area() == 100.0f);
	std::cout<< "Polymorphism area test for Square: passed\n";
	delete f;
	delete f2;
}

void test_static_Triangle_area()
{
	Triangle<int> t(1, 0, 5, 0, 3, 2);
	assert(t.area() == 4);
	std::cout << "Area test for Triangle<typename T>: passed\n";
}

void test_static_Point_Triangle_area()
{
	Triangle<Point<int>> t(Point<int>(1, 0), Point<int>(5, 0), Point<int>(3, 2));
	assert(t.area() == 4);
	std::cout << "Area test for Triangle<Point<typename T>>: passed\n";
}

void test_polymorphism_Triangle_area()
{
	Figure<double, 3>* f = new Triangle<double>(1, 0, 5, 0, 3, 2);
	assert(f->area() == 4.0);
	Figure<float, 3>* f2 = new Triangle<Point<float>>(Point<float>(1, 0), Point<float>(5, 0), Point<float>(3, 2));
	assert(f2->area() == 4.0f);
	std::cout << "Polymorphism area test for Triangle: passed\n";
	delete f;
	delete f2;
}

void test_static_RegularPolygon_area()
{
	RegularPolygon<int, 5> rp(0, 5, 0, 10);
	double expected = 43.0119;
	double precision = 0.001;
	assert(fabs(rp.area()-expected) < precision);	// inlcude precision loses
	std::cout<< "Area test for RegularPolygon<typename T, int N>: passed\n";
}

void test_static_Point_RegularPolygon_area()
{
	RegularPolygon<Point<int>,5> rp(Point<int>(0,5),Point<int>(0,10));
	double expected = 43.0119;
	double precision = 0.001;
	assert(fabs(rp.area() - expected) < precision);	// inlcude precision loses
	std::cout << "Area test for RegularPolygon<Point<typename T>, int N>: passed\n";
}

void test_polymorphism_RegularPolygon_area()
{
	Figure<float, 5>* f = new RegularPolygon<float, 5>(0.0f, 5.0f, 0.0f, 10.0f);
	Figure<double, 5>* f2 = new RegularPolygon<Point<double>, 5>(Point<double>(0.0, 5.0), Point<double>(0.0, 10.0));
	double expected = 43.0119;
	double precision = 0.001;
	assert(fabs(f->area() - expected) < precision);	// inlcude precision loses
	assert(fabs(f2->area() - expected) < precision);
	std::cout << "Polymorphism area test for RegularPolygon: passed\n";
	delete f;
	delete f2;
}




void RUNALLTESTS()
{
	test_static_Point_Square_area();
	test_static_Square_area();
	test_polymorphism_Square_area();
	test_static_Triangle_area();
	test_static_Point_Triangle_area();
	test_polymorphism_Triangle_area();
	test_static_RegularPolygon_area();
	test_static_Point_RegularPolygon_area();
	test_polymorphism_RegularPolygon_area();
}

