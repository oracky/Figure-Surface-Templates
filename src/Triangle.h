#pragma once
#include "Figura.h"
#include <math.h>

constexpr auto TRIANGLE_POINTS = 3;

template<typename T>
class Triangle : public Figure<T, TRIANGLE_POINTS>
{
public:
	Triangle();
	Triangle(T x1, T y1, T x2, T y2, T x3, T y3);
	virtual double area() override;
};

template<typename T>
class Triangle<Point<T>> : public Figure<T, TRIANGLE_POINTS>
{
public:
	Triangle();
	Triangle(Point<T>, Point<T>, Point<T>);
	virtual double area() override;
};


template<typename T>
inline Triangle<T>::Triangle(){}

template<typename T>
inline Triangle<T>::Triangle(T x1, T y1, T x2, T y2, T x3, T y3)
{
	this->addVertex(Point<T>(x1, y1));
	this->addVertex(Point<T>(x2, y2));
	this->addVertex(Point<T>(x3, y3));
}

template<typename T>
inline double Triangle<T>::area()
{
	// compute only if all 3 vertices are set up
	if (this->getVerticesNumber() == 3)
	{
		return 0.5 * abs(this->getLenCrossProductR2(this->getVector(this->points[0], this->points[1]),
			this->getVector(this->points[0], this->points[2])));
	}
	return 0;
}


template<typename T>
inline Triangle<Point<T>>::Triangle(){}

template<typename T>
inline Triangle<Point<T>>::Triangle(Point<T> p1, Point<T> p2, Point<T> p3)
{
	this->addVertex(p1);
	this->addVertex(p2);
	this->addVertex(p3);
}

template<typename T>
inline double Triangle<Point<T>>::area()
{
	// compute only if all 3 vertices are set up
	if (this->getVerticesNumber() == 3)
	{
		return 0.5 * abs(this->getLenCrossProductR2(this->getVector(this->points[0], this->points[1]),
			this->getVector(this->points[0], this->points[2])));
	}
	return 0;
}