#pragma once

#include "RegularPolygon.h"

class EquilateralTriangle : public RegularPolygon
{
public:
	EquilateralTriangle(const Coord2D& centroid, const shape_t& radius);
};