#pragma once
#include "Figura.h"
#include <vector>
#include <iostream>
#include <math.h>

template<typename T>
class Square : public Figure<T, 4>
{
public:
	Square();
	Square(T x1, T y1, T x2, T y2);
	Square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4);
	virtual double area() override;
};

template<typename T> 
class Square<Point<T>> : public Figure<T, 4>
{
public:
	Square();
	Square(Point<T>, Point<T>);
	Square(Point<T>, Point<T>, Point<T>, Point<T>);
	virtual double area() override;
};



template<typename T>
inline Square<T>::Square(){}

template<typename T>
inline Square<T>::Square(T x1, T y1, T x2, T y2)
{
	this->addVertex(Point<T>(x1, y1));
	this->addVertex(Point<T>(x2, y2));
}

template<typename T>
inline Square<T>::Square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4)
{
	this->addVertex(Point<T>(x1, y1));
	this->addVertex(Point<T>(x2, y2));
	this->addVertex(Point<T>(x3, y3));
	this->addVertex(Point<T>(x4, y4));
}

template<typename T>
inline double Square<T>::area()
{
	// only compute area if there are at least two vertices
	if (this->getVerticesNumber() >= 2)
	{
		T xPowLen = (this->points[0].x - this->points[1].x) * (this->points[0].x - this->points[1].x);
		T yPowLen = (this->points[0].y - this->points[1].y) * (this->points[0].y - this->points[1].y);
		return xPowLen + yPowLen;
	}
	return 0;
}



template<typename T>
inline Square<Point<T>>::Square(Point<T> p1, Point<T> p2)
{
	this->addVertex(p1);
	this->addVertex(p2);
}

template<typename T>
inline Square<Point<T>>::Square(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4)
{
	this->addVertex(p1);
	this->addVertex(p2);
	this->addVertex(p3);
	this->addVertex(p4);
}

template<typename T>
inline Square<Point<T>>::Square(){}


template<typename T>
inline double Square<Point<T>>::area()
{
	if (this->getVerticesNumber() >= 2)
	{
		T xPowLen = (this->points[0].x - this->points[1].x) * (this->points[0].x - this->points[1].x);
		T yPowLen = (this->points[0].y - this->points[1].y) * (this->points[0].y - this->points[1].y);
		return xPowLen + yPowLen;
	}
	return 0;
}