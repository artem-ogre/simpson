#include "Circle.h"

#define _USE_MATH_DEFINES // for C++
#include <cmath>

Circle::Circle(Coord2D centroid, shape_t radius) : Shape(centroid), m_radius(radius) {}
Circle::Circle() : Circle( Coord2D(), 0 ) {}
Circle::~Circle() {}

shape_t Circle::getArea() const
{
	return M_PI * m_radius * m_radius;
}
