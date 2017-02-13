#pragma once

#include "PolymorphicBaseClass.h"

#include <iostream>
#include <memory>
#include <string>

struct IStorageRead;
struct IStorageWrite;

//!  Interface for the serializable type.
struct ISerializable : PolymorphicBaseClass
{
    //! writes object to a stream
    virtual void serialize(IStorageWrite& outStream) const = 0; // SERIALIZABLE_TYPE generates overriding declaration
    //! reads object from a stream
    virtual void deserialize(IStorageRead& inStream) = 0;        // SERIALIZABLE_TYPE generates overriding declaration
    //! returns serializable object's class name
    virtual std::string getClassName() const = 0;           // SERIALIZABLE_TYPE generates overriding declaration
                                                            // REGISTER_SERIALIZABLE_TYPE generate implementation
};

using ISerializableUniquePtr = std::unique_ptr<ISerializable>;
using ISerializableSharedPtr = std::shared_ptr<ISerializable>;
