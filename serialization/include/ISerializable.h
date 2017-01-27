#pragma once

#include "VirtualBase.h"

#include <iostream>
#include <memory>
#include <string>

//!  Interface for the serializable type.
struct ISerializable : VirtualBase
{
    //! writes object to a stream
    virtual void saveTo(std::ostream& outStream) const = 0; // use SERIALIZABLE_TYPE to generate overriding declaration
    //! reads object from a stream
    virtual void loadFrom(std::istream& inStream) = 0;      // use SERIALIZABLE_TYPE to generate overriding declaration
    //! returns serializable object's class name
    virtual std::string getClassName() const = 0;           // use SERIALIZABLE_TYPE to generate overriding declaration
                                                            // use REGISTER_SERIALIZABLE_TYPE to generate implementation
};

using ISerializableUniquePtr = std::unique_ptr<ISerializable>;
using ISerializableSharedPtr = std::shared_ptr<ISerializable>;
