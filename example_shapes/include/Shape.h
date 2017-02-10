#pragma once

#include "Position2D.h"

#include <Serialization.h>

using shape_t = double;
using ShapePos2D = Position2D<shape_t>;

//!  Interface for the shape type. Supports serialization via IStreamable
class Shape : public ISerializable
{
public:
    Shape(const ShapePos2D& centroid);
    const ShapePos2D& getCentroid() const;
    void setCentroid(const ShapePos2D& newCentroid);
    void moveCentroid(const ShapePos2D& offset);
    virtual shape_t getArea() const = 0;
    // IStreamable
    virtual void saveTo(IStorageWrite& outStream) const override;
    virtual void loadFrom(IStorageRead& inStream) override;

protected:
    ShapePos2D m_centroid;
};
