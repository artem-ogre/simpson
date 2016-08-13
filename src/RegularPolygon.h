#pragma once

#include "Circle.h"

class RegularPolygon : public Circle
{
public:
	RegularPolygon( const ShapePos2D& centroid, const shape_t& radius, const unsigned long& numberOfSides );

	virtual shape_t getArea() const override;
	unsigned long getNSides() const;
	shape_t getSideLength() const;

protected:
	const unsigned long m_nSides;
};