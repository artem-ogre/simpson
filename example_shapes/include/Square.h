#pragma once

#include "RegularPolygon.h"

class Square : public RegularPolygon
{
    SIMPSON_IS_A_SERIALIZABLE_TYPE
public:
    Square();
    Square(const ShapePos2D& centroid, const shape_t& radius);
};
