#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {

struct ISerializable;

/// Interface for serializable objects factory.
struct ISerializableFactory : PolymorphicBaseClass
{
    /// \brief Creates serializable object.
    /// \return pointer to polymorphic base of the serializable object
    virtual ISerializable* create() const = 0;
};

} // simpson
