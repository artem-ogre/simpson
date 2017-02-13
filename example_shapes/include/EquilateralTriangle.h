#pragma once

#include "RegularPolygon.h"

class EquilateralTriangle : public RegularPolygon
{
    IS_A_SERIALIZABLE_TYPE
public:
    EquilateralTriangle();
    EquilateralTriangle(const ShapePos2D& centroid, const shape_t& radius);
};
