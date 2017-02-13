#include "Square.h"

using namespace simpson;

SIMPSON_REGISTER_A_SERIALIZABLE_TYPE(Square)

Square::Square(const ShapePos2D& centroid, const shape_t& radius)
    : RegularPolygon(centroid, radius, 4)
{
}

Square::Square()
    : Square(ShapePos2D(0, 0), 1)
{
}

void Square::serialize(IStorageWrite& outStream) const { RegularPolygon::serialize(outStream); }

void Square::deserialize(IStorageRead& inStream) { RegularPolygon::deserialize(inStream); }
