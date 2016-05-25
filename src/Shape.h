#pragma once

#include "Position2D.h"
#include "IStreamable.h"

typedef double shape_t;
typedef Position2D<shape_t> ShapePos2D;

class Shape : public IStreamable
{
public:
	Shape();
	Shape( const ShapePos2D& centroid );
	virtual ~Shape();

	const ShapePos2D& getCentroid() const;
	void setCentroid( const ShapePos2D& newCentroid );
	void moveCentroid( const ShapePos2D& offset );	
	virtual shape_t getArea() const = 0;

	//IStreamable
	virtual void serialize( std::ostream& outStream ) const override;
	virtual void readState( std::istream& inStream ) override;

protected:
	ShapePos2D m_centroid;
};
