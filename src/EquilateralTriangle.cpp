#include "EquilateralTriangle.h"

REGISTER_SERIALIZABLE_TYPE(EquilateralTriangle)

EquilateralTriangle::EquilateralTriangle(const ShapePos2D& centroid, const shape_t& radius)
    : RegularPolygon(centroid, radius, 3)
{
}

EquilateralTriangle::EquilateralTriangle()
    : EquilateralTriangle(ShapePos2D(0, 0), 1)
{
}

void EquilateralTriangle::write(std::ostream& outStream) const { RegularPolygon::write(outStream); }

void EquilateralTriangle::read(std::istream& inStream) { RegularPolygon::read(inStream); }
