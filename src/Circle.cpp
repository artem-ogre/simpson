#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.h"

#include <exception>
#include <iostream>
#include <string>

const std::exception negativeRadius( "The radius should be non-negative" );

Circle::Circle( const ShapePos2D& centroid, const shape_t& radius ) 
	: Shape( centroid )
{
	registerClass();
	setRadius( radius );
}
Circle::Circle() : Circle( ShapePos2D(), 0 ) {}
Circle::~Circle() {}

shape_t Circle::getArea() const
{
	return M_PI * m_radius * m_radius;
}

void Circle::serialize( std::ostream& outStream ) const
{
	Shape::serialize( outStream );
	outStream << " " << m_radius;
}

void Circle::readState( std::istream& inStream )
{
	Shape::readState( inStream );
	inStream >> m_radius;
}

IStreamable* Circle::createDummy() const
{
	return new Circle;
}

std::string Circle::getClassName() const
{
	return "Circle";
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
