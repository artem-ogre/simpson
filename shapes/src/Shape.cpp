#include "Shape.h"
#include "IStorageIn.h"
#include "IStorageOut.h"

Shape::Shape(const ShapePos2D& centroid)
    : m_centroid(centroid)
{
}

void Shape::setCentroid(const ShapePos2D& newCentroid) { m_centroid = newCentroid; }

void Shape::moveCentroid(const ShapePos2D& offset) { m_centroid += offset; }

void Shape::saveTo(IStorageOut& outStream) const
{
    std::string space(" ");
    outStream << " " << m_centroid.x() << " " << m_centroid.y();
}

void Shape::loadFrom(IStorageIn& inStream)
{
    shape_t pos[2];
    inStream >> pos[0] >> pos[1];
    m_centroid = ShapePos2D(pos[0], pos[1]);
}

const ShapePos2D& Shape::getCentroid() const { return m_centroid; }
