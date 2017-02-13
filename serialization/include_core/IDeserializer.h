#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {

struct ISerializable;

/// Interface for serializable object deserializer.
struct IDeserializer : PolymorphicBaseClass
{
    /// Polymorphically deserialize a serializable object
    /// \return  A raw pointer to the newly created deserialized object
    virtual ISerializable* deserialize() = 0;
};

} // simpson
