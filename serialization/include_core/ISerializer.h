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
    /// Polymorphically deserialize a serializable object
    /// \return  A raw pointer to the newly created deserialized object
    virtual ISerializable* deserialize() = 0;
};

} // simpson
