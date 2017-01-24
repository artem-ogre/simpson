#define _USE_MATH_DEFINES
#include <cmath>

#include "RegularPolygon.h"

#include <assert.h>
#include <stdexcept>

const std::runtime_error notEnoughSidesException("Number of sides for regular polygon should be at least 3");

RegularPolygon::RegularPolygon(
    const ShapePos2D& centroid,
    const shape_t& radius,
    const unsigned long& numberOfSides)
    : Circle(centroid, radius)
    , m_nSides(numberOfSides)
{
    if(m_nSides < 3)
        throw notEnoughSidesException;
}

shape_t RegularPolygon::getArea() const
{
    return 0.5 * m_nSides * (m_radius * m_radius) * std::sin(2 * M_PI / m_nSides);
}

unsigned long RegularPolygon::getNSides() const { return m_nSides; }

shape_t RegularPolygon::getSideLength() const { return 2 * m_radius * sin(M_PI / m_nSides); }
