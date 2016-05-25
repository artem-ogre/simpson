#include "Rectangle.h"
#include <exception>

const std::exception negativeDimension( "The rectangle dimensions should be non-negative" );

Rectangle::Rectangle( const ShapePos2D& centroid, const shape_t& width, const shape_t& height ) : Shape( centroid ), m_width( width ), m_height( height )
{
	setWidth( width );
	setHeight( height );
}

Rectangle::~Rectangle() {}

shape_t Rectangle::getArea() const
{
	return m_height * m_width;
}

void Rectangle::setWidth( const shape_t& width )
{
	if ( width < shape_t( 0 ) )
		throw negativeDimension;
	m_width = width;
}

void Rectangle::setHeight( const shape_t& height )
{
	if ( height < shape_t( 0 ) )
		throw negativeDimension;
	m_height = height;
}

const shape_t& Rectangle::getWidth() const
{
	return m_width;
}

const shape_t& Rectangle::getHeight() const
{
	return m_height;
}
