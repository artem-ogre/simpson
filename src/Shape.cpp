#include "Shape.h"

Shape::Shape()
{}

Shape::Shape( const ShapePos2D& centroid ) 
	: m_centroid( centroid ) 
{}

Shape::~Shape() {}

void Shape::setCentroid( const ShapePos2D& newCentroid )
{
	m_centroid = newCentroid;
}

void Shape::moveCentroid( const ShapePos2D& offset )
{
	m_centroid += offset;
}

void Shape::writeState( std::ostream& outStream ) const
{
	//IStreamable::writeState( outStream );
	outStream << " " << m_centroid.x() << " " << m_centroid.y();
}

void Shape::readState( std::istream& inStream )
{
	shape_t pos[2];
	inStream >> pos[0] >> pos[1];
	m_centroid = ShapePos2D( pos[0], pos[1] );
}

const ShapePos2D& Shape::getCentroid() const
{
	return m_centroid;
}

