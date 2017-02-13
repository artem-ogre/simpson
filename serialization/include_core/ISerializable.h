#pragma once

#include "PolymorphicBaseClass.h"

#include <iostream>
#include <memory>
#include <string>

namespace simpson {
struct IStorageRead;
struct IStorageWrite;

///  Interface for the serializable type.
struct ISerializable : PolymorphicBaseClass
{
    /// Writes itself to a write storage
    virtual void serialize(IStorageWrite& outStream) const = 0; // SERIALIZABLE_TYPE generates overriding declaration
    /// Reads itself from a read storage
    virtual void deserialize(IStorageRead& inStream) = 0;        // SERIALIZABLE_TYPE generates overriding declaration

    /// Gets a string containing class name which is used as a unique identifier for the polymorphic serialization
    /// \return serializable object's class name
    virtual std::string getClassName() const = 0;           // SERIALIZABLE_TYPE generates overriding declaration
                                                            // REGISTER_SERIALIZABLE_TYPE generate implementation
};

/// unique_ptr to ISerializable
using ISerializableUniquePtr = std::unique_ptr<ISerializable>;
/// shared_ptr to ISerializable
using ISerializableSharedPtr = std::shared_ptr<ISerializable>;

} // simpson
