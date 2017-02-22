#pragma once

#include "PolymorphicBaseClass.h"
#include "SerializationUtilities.h"

namespace simpson {

struct ISerializable;

/// Interface for serializable objects factory.
struct ISerializableFactory : PolymorphicBaseClass
{
    /// \brief Creates serializable object.
    /// \return pointer to polymorphic base of the serializable object
    virtual ISerializable* create() const = 0;
};

template <typename Type>
struct SerializableFactory : ISerializableFactory
{
    SerializableFactory(const char* type_name)
    {
        SerializationUtilities::registerType(type_name, this);
    }
    virtual ISerializable* create() const override { return new Type; }
};

} // simpson
