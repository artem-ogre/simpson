#pragma once

typedef double shape_t;
class Coord2D
{
public:
	Coord2D( const shape_t& x, const shape_t& y ) : m_x( x ), m_y( y ) {}
	Coord2D() : Coord2D( 0, 0 ) {}
	Coord2D& operator+= (const Coord2D& v)
	{
		m_x += v.x();
		m_y += v.y();
		return *this;
	}
	const shape_t& x() const { return m_x; }
	const shape_t& y() const { return m_y; }

protected:
	shape_t m_x, m_y;
};

