#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.h"

#include <exception>
#include <iostream>
#include <string>

const std::exception negativeRadius( "The radius should be non-negative" );

REGISTER_TYPE( Circle )

Circle::Circle( const ShapePos2D& centroid, const shape_t& radius ) 
	: Shape( centroid )
{
	setRadius( radius );
}

Circle::Circle() : Circle( ShapePos2D(), 0 ) 
{}

shape_t Circle::getArea() const
{
	return M_PI * m_radius * m_radius;
}

void Circle::writeState( std::ostream& outStream ) const
{
	Shape::writeState( outStream );
	outStream << " " << m_radius;
}

void Circle::readState( std::istream& inStream )
{
	Shape::readState( inStream );
	inStream >> m_radius;
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
