#include "Shape.h"

Shape::Shape() {}

Shape::Shape( Coord2D centroid ) : m_centroid( centroid ) {}

Shape::~Shape() {}

void Shape::setCentroid( Coord2D newCentroid )
{
	m_centroid = newCentroid;
}

void Shape::moveCentroid( Coord2D offset )
{
	m_centroid += offset;
}

const Coord2D & Shape::getCentroid() const
{
	return m_centroid;
}

