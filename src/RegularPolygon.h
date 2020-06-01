#pragma once
#define _USE_MATH_DEFINES
#include "Figura.h"
#include <math.h>
#include <cstdarg>

template<typename T, int N>
class RegularPolygon : public Figure<T, N>
{
public:
	RegularPolygon();
	RegularPolygon(T x1, T y1, T x2, T y2);
	virtual double area();
};

template<typename T, int N>
class RegularPolygon<Point<T>, N> : public Figure<T, N>
{
public:
	RegularPolygon();
	RegularPolygon(Point<T>, Point<T>);
	virtual double area();
};


template<typename T, int N>
inline RegularPolygon<T, N>::RegularPolygon(){}

template<typename T, int N>
inline RegularPolygon<T, N>::RegularPolygon(T x1, T y1, T x2, T y2)
{
	this->addVertex(Point<T>(x1, y1));
	this->addVertex(Point<T>(x2, y2));
}

template<typename T, int N>
inline double RegularPolygon<T, N>::area()
{
	T xPowLen = (this->points[0].x - this->points[1].x) * (this->points[0].x - this->points[1].x);
	T yPowLen = (this->points[0].y - this->points[1].y) * (this->points[0].y - this->points[1].y);
	double side = sqrt(xPowLen + yPowLen);
	return 0.25 * N * side * side * (1.0 / tan(M_PI / N));
}


template<typename T, int N>
inline RegularPolygon<Point<T>,N>::RegularPolygon(){}

template<typename T, int N>
inline RegularPolygon<Point<T>, N>::RegularPolygon(Point<T> p1, Point<T> p2)
{
	this->addVertex(p1);
	this->addVertex(p2);
}

template<typename T, int N>
inline double RegularPolygon<Point<T>, N>::area()
{
	T xPowLen = (this->points[0].x - this->points[1].x) * (this->points[0].x - this->points[1].x);
	T yPowLen = (this->points[0].y - this->points[1].y) * (this->points[0].y - this->points[1].y);
	double side = sqrt(xPowLen + yPowLen);
	return 0.25 * N * side * side * (1.0 / tan(M_PI / N));
}
