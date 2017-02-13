#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {

struct ISerializable;

/// Interface for serializable object serializer.
struct ISerializer : PolymorphicBaseClass
{
    /// \brief Serializes a provided serializable object.
    /// \param obj an object to be serialized
    virtual void serialize(ISerializable* obj) = 0;
};

} // simpson
