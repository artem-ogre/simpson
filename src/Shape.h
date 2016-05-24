#pragma once

#include "ShapeHelpers.h"

class Shape
{
public:
	Shape();
	Shape( const Coord2D& centroid );
	virtual ~Shape();

	const Coord2D& getCentroid() const;
	void setCentroid( const Coord2D& newCentroid );

	void moveCentroid( const Coord2D& offset );
	
	virtual shape_t getArea() const = 0;
	
protected:
	Coord2D m_centroid;
};
