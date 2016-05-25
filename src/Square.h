#pragma once

#include "RegularPolygon.h"

class Square : public RegularPolygon
{
public:
	Square( const Coord2D& centroid, const shape_t& radius );
};