#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle( const ShapePos2D& centroid, const shape_t& width, const shape_t& height );
	virtual ~Rectangle() override;

	virtual shape_t getArea() const override;
	void setWidth( const shape_t& width );
	void setHeight( const shape_t& height );
	const shape_t& getWidth() const;
	const shape_t& getHeight() const;

protected:
	shape_t m_width;
	shape_t m_height;
};
