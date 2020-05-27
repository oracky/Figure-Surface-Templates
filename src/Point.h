#pragma once
#include <type_traits>

template<typename NumericType>
class Point
{
public:
	NumericType x;
	NumericType y;
	Point();
	Point(NumericType x, NumericType y);
};

template<typename NumericType>
inline Point<NumericType>::Point(): x(0), y(0){}

template<typename NumericType>
inline Point<NumericType>::Point(NumericType x, NumericType y)
{
	static_assert(std::is_arithmetic<NumericType>::value, "Point must have members of numeric type (int, double, etc.)");
	this->x = x;
	this->y = y;
}
