#pragma once

#include "VirtualBase.h"

#include <iostream>
#include <memory>
#include <string>

struct IStorageIn;
struct IStorageOut;

//!  Interface for the serializable type.
struct ISerializable : VirtualBase
{
    //! writes object to a stream
    virtual void saveTo(IStorageOut& outStream) const = 0;  // SERIALIZABLE_TYPE generates overriding declaration
    //! reads object from a stream
    virtual void loadFrom(IStorageIn& inStream) = 0;        // SERIALIZABLE_TYPE generates overriding declaration
    //! returns serializable object's class name
    virtual std::string getClassName() const = 0;           // SERIALIZABLE_TYPE generates overriding declaration
                                                            // REGISTER_SERIALIZABLE_TYPE generate implementation
};

using ISerializableUniquePtr = std::unique_ptr<ISerializable>;
using ISerializableSharedPtr = std::shared_ptr<ISerializable>;
