#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>

const std::exception negativeRadius( "The radius should be non-negative" );

Circle::Circle( const ShapePos2D& centroid, const shape_t& radius ) : Shape( centroid )
{
	setRadius( radius );
}
Circle::Circle() : Circle( ShapePos2D(), 0 ) {}
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
	if ( radius < shape_t( 0 ) )
		throw negativeRadius;
	m_radius = radius;
}
