#include "RegularPolygon.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <assert.h>
#include <exception>

const std::exception zeroSidesException( "Number of sides for regular polygon should be more than zero" );

RegularPolygon::RegularPolygon( const Coord2D& centroid, const shape_t& radius, const unsigned long& numberOfSides )
	: Circle( centroid, radius ),
	m_nSides( numberOfSides )
{
	if ( !(m_nSides > 0) )
		throw zeroSidesException;
}

shape_t RegularPolygon::getArea() const
{
	return 0.5 * m_nSides * (m_radius*m_radius) * std::sin( 2 * M_PI / m_nSides );
}

const unsigned long& RegularPolygon::getNSides() const
{
	return m_nSides;
}

void RegularPolygon::setNSides( const unsigned long& nSides )
{
	if ( !(nSides > 0) )
		throw zeroSidesException;
	m_nSides = nSides;
}
