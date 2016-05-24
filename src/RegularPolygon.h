#pragma once

#include "Circle.h"

class RegularPolygon : public Circle
{
public:
	RegularPolygon( const Coord2D& centroid, const shape_t& radius, const unsigned long& numberOfSides );
	virtual shape_t getArea() const override;

	const unsigned long& getNSides() const;
	void setNSides( const unsigned long& nSides );

protected:
	unsigned long m_nSides;
};