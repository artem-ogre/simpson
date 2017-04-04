#pragma once

#include "PolymorphicBaseClass.h"

#include <iostream>
#include <memory>
#include <string>

namespace simpson
{

struct IStorage;

///  Interface for the serializable type.
struct ISerializable : PolymorphicBaseClass
{
    /// Writes itself to a write storage
    virtual void serialize(IStorage& outStream) = 0;

    /// Gets a string containing class name which is used
    /// as a unique identifier for the polymorphic serialization
    /// \return serializable object's class name
    virtual std::string typeName() const = 0;
};
}
