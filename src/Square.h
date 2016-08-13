#pragma once

#include "RegularPolygon.h"

class Square : public RegularPolygon
{
	SERIALIZABLE_TYPE
public:
	Square();
	Square( const ShapePos2D& centroid, const shape_t& radius );
};