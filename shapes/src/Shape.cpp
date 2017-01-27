#include "Shape.h"

Shape::Shape(const ShapePos2D& centroid)
    : m_centroid(centroid)
{
}

void Shape::setCentroid(const ShapePos2D& newCentroid) { m_centroid = newCentroid; }

void Shape::moveCentroid(const ShapePos2D& offset) { m_centroid += offset; }

void Shape::saveTo(std::ostream& outStream) const
{
    outStream << " " << m_centroid.x() << " " << m_centroid.y();
}

void Shape::loadFrom(std::istream& inStream)
{
    shape_t pos[2];
    inStream >> pos[0] >> pos[1];
    m_centroid = ShapePos2D(pos[0], pos[1]);
}

const ShapePos2D& Shape::getCentroid() const { return m_centroid; }
