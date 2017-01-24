#include "Rectangle.h"
#include <stdexcept>

const std::runtime_error negativeDimension("The rectangle dimensions should be non-negative");

REGISTER_SERIALIZABLE_TYPE(Rectangle)

Rectangle::Rectangle(const ShapePos2D& centroid, const shape_t& width, const shape_t& height)
    : Shape(centroid)
{
    setWidth(width);
    setHeight(height);
}

Rectangle::Rectangle()
    : Rectangle(ShapePos2D(0.0, 0.0), 1.0, 1.0)
{
}

shape_t Rectangle::getArea() const { return m_height * m_width; }

void Rectangle::setWidth(const shape_t& width)
{
    if(width < shape_t(0))
        throw negativeDimension;
    m_width = width;
}

void Rectangle::setHeight(const shape_t& height)
{
    if(height < shape_t(0))
        throw negativeDimension;
    m_height = height;
}

const shape_t& Rectangle::getWidth() const { return m_width; }

const shape_t& Rectangle::getHeight() const { return m_height; }

void Rectangle::write(std::ostream& outStream) const
{
    Shape::write(outStream);
    outStream << " " << m_width << " " << m_height;
}

void Rectangle::read(std::istream& inStream)
{
    Shape::read(inStream);
    inStream >> m_width >> m_height;
}
