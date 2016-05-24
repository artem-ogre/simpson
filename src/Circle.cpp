#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle( const Coord2D& centroid, const shape_t& radius ) : Shape( centroid ), m_radius( radius ) {}
Circle::Circle() : Circle( Coord2D(), 0 ) {}
Circle::~Circle() {}

shape_t Circle::getArea() const
{
	return M_PI * m_radius * m_radius;
}

const shape_t& Circle::getRadius()
{
	return m_radius;
}

void Circle::setRadius( const shape_t& radius )
{
	m_radius = radius;
}
