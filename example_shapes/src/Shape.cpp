#include "Shape.h"
#include "IStorageRead.h"
#include "IStorageWrite.h"

using namespace simpson;

Shape::Shape(const ShapePos2D& centroid)
    : m_centroid(centroid)
{
}

void Shape::setCentroid(const ShapePos2D& newCentroid) { m_centroid = newCentroid; }

void Shape::moveCentroid(const ShapePos2D& offset) { m_centroid += offset; }

void Shape::serialize(IStorageWrite& outStream) const
{
    outStream << m_centroid.x() << m_centroid.y();
}

void Shape::deserialize(IStorageRead& inStream)
{
    shape_t pos[2];
    inStream >> pos[0] >> pos[1];
    m_centroid = ShapePos2D(pos[0], pos[1]);
}

const ShapePos2D& Shape::getCentroid() const { return m_centroid; }
