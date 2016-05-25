#include "Rectangle.h"
#include <exception>

const std::exception negativeDimension( "The rectangle dimensions should be non-negative" );

Rectangle::Rectangle( const ShapePos2D& centroid, const shape_t& width, const shape_t& height ) : Shape( centroid ), m_width( width ), m_height( height )
{
	registerClass( "Rectangle" );
	setWidth( width );
	setHeight( height );
}

Rectangle::Rectangle() :Rectangle( ShapePos2D( 0.0, 0.0 ), 1.0, 1.0 ) {}

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

void Rectangle::serialize( std::ostream& outStream ) const
{
	Shape::serialize( outStream );
	outStream << " " << m_width << " " << m_height;
}

IStreamable* Rectangle::create( std::istream& inStream ) const
{
	shape_t posx, posy;
	shape_t width, height;
	inStream >> posx >> posy >> width >> height;
	return new Rectangle( ShapePos2D( posx, posy ), width, height );
}

IStreamable* Rectangle::createDummy() const
{
	return new Rectangle;
}
