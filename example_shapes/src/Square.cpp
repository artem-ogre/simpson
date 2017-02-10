#include "Square.h"

REGISTER_SERIALIZABLE_TYPE(Square)

Square::Square(const ShapePos2D& centroid, const shape_t& radius)
    : RegularPolygon(centroid, radius, 4)
{
}

Square::Square()
    : Square(ShapePos2D(0, 0), 1)
{
}

void Square::saveTo(IStorageWrite& outStream) const { RegularPolygon::saveTo(outStream); }

void Square::loadFrom(IStorageRead& inStream) { RegularPolygon::loadFrom(inStream); }
