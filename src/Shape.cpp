#include "Shape.h"

Shape::Shape() {}

Shape::Shape( const ShapePos2D& centroid ) : m_centroid( centroid ) {}

Shape::~Shape() {}

void Shape::setCentroid( const ShapePos2D& newCentroid )
{
	m_centroid = newCentroid;
}

void Shape::moveCentroid( const ShapePos2D& offset )
{
	m_centroid += offset;
}

const ShapePos2D& Shape::getCentroid() const
{
	return m_centroid;
}

