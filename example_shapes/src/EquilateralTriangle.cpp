#include "EquilateralTriangle.h"

using namespace simpson;

REGISTER_A_SERIALIZABLE_TYPE(EquilateralTriangle)

EquilateralTriangle::EquilateralTriangle(const ShapePos2D& centroid, const shape_t& radius)
    : RegularPolygon(centroid, radius, 3)
{
}

EquilateralTriangle::EquilateralTriangle()
    : EquilateralTriangle(ShapePos2D(0, 0), 1)
{
}

void EquilateralTriangle::serialize(IStorageWrite& outStream) const { RegularPolygon::serialize(outStream); }
void EquilateralTriangle::deserialize(IStorageRead& inStream) { RegularPolygon::deserialize(inStream); }
