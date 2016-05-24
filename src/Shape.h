#pragma once

typedef double shape_t;

class Coord2D
{
public:
	Coord2D( const shape_t& xVal, const shape_t& yVal ) : x( xVal ), y( yVal ) {}
	Coord2D() : Coord2D( 0, 0 ) {}
	Coord2D& operator+= (const Coord2D& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

public:
	shape_t x, y;
};

class Shape
{
public:
	Shape();
	Shape( const Coord2D& centroid );
	virtual ~Shape();

	const Coord2D& getCentroid() const;
	void setCentroid( const Coord2D&  newCentroid );

	void moveCentroid( const Coord2D& offset );
	
	virtual shape_t getArea() const = 0;
	
protected:
	Coord2D m_centroid;
};
