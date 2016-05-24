#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle( Coord2D centroid, shape_t radius );
	~Circle();

	virtual shape_t getArea() const override;

protected:
	shape_t m_radius;
};
