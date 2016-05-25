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

	//ISerializable
	virtual void serialize( std::ostream& outStream ) const override;
	virtual void readState( std::istream& inStream ) override;
	virtual IStreamable* createDummy() const override;

protected:
	shape_t m_radius;
};
