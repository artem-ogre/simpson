#pragma once

#include "RegularPolygon.h"

class EquilateralTriangle : public RegularPolygon
{
public:
	EquilateralTriangle( const ShapePos2D& centroid, const shape_t& radius );
	virtual ~EquilateralTriangle() override {};
};