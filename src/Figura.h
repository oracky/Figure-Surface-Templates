#pragma once
#include <vector>
#include "Point.h"

template<typename T, int N>
class Figure
{
protected:
	std::vector<Point<T>> points;
	void addVertex(Point<T>);
	unsigned int getVerticesNumber() const;
	bool isRepeated(Point<T>);
	Point<T> getVector(Point<T> p1, Point<T> p2);
	T getLenCrossProductR2(Point<T> vec1, Point<T> vec2);
public:
	virtual double area() = 0;
};

template<typename T, int N>
inline void Figure<T, N>::addVertex(Point<T> p)
{
	// Add point if there is at least one free vertex
	if (points.size() < N)
	{
		// Check if vertex is unique
		if (!isRepeated(p))
			points.push_back(p);
		else addVertex(Point<T>(p.x + 1, p.y));	// try to add modified vertex
	}
		
}

template<typename T, int N>
inline unsigned int Figure<T, N>::getVerticesNumber() const
{
	return points.size();
}


template<typename T, int N>
inline bool Figure<T, N>::isRepeated(Point<T> p)
{
	for (auto i : points)
	{
		if (i.x == p.x && i.y == p.y) return true;
	}
	return false;
}

template<typename T, int N>
inline Point<T> Figure<T, N>::getVector(Point<T> p1, Point<T> p2)
{
	return Point<T>(p2.x - p1.x, p2.y - p1.y);
}

template<typename T, int N>
inline T Figure<T, N>::getLenCrossProductR2(Point<T> vec1, Point<T> vec2)
{
	return vec1.x * vec2.y - vec1.y * vec2.x;
}
