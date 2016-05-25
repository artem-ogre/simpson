#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle( const ShapePos2D& centroid, const shape_t& radius );
	virtual ~Circle() override;

	const shape_t& getRadius();
	void setRadius( const shape_t& radius );
	virtual shape_t getArea() const override;

protected:
	shape_t m_radius;
};
