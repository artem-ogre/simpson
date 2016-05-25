#pragma once

#include "RegularPolygon.h"

class Square : public RegularPolygon
{
public:
	Square( const ShapePos2D& centroid, const shape_t& radius );
	virtual ~Square() override {};
};