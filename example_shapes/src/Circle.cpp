#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.h"
#include "IStorageRead.h"
#include "IStorageWrite.h"

#include <iostream>
#include <stdexcept>
#include <string>

const std::runtime_error negativeRadius("The radius should be non-negative");

REGISTER_A_SERIALIZABLE_TYPE(Circle)

Circle::Circle(const ShapePos2D& centroid, const shape_t& radius)
    : Shape(centroid)
{
    setRadius(radius);
}

Circle::Circle()
    : Circle(ShapePos2D(), 0)
{
}

shape_t Circle::getArea() const { return M_PI * m_radius * m_radius; }

void Circle::serialize(IStorageWrite& outStream) const
{
    Shape::serialize(outStream);
    outStream << m_radius;
}

void Circle::deserialize(IStorageRead& inStream)
{
    Shape::deserialize(inStream);
    inStream >> m_radius;
}

const shape_t& Circle::getRadius() { return m_radius; }

void Circle::setRadius(const shape_t& radius)
{
    if(radius < shape_t(0))
        throw negativeRadius;
    m_radius = radius;
}
