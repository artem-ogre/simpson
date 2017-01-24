#pragma once

#include "VirtualBase.h"

#include <iostream>
#include <memory>
#include <string>

//!  Interface for the serializable type.
/*!
Supports polymorphic serialization and unserialization to the stream and overloads streaming operators.
Serialization is using an abstract factory with named constructor idiom.
Classes implementing the interface need to override writeState and readState methods.
!Caller of IStreamable::unserialize is responsible for deleting it.
!In order for the class to be serializable put SERIALIZABLE_TYPE macro in the declaration
and REGISTER_SERIALIZABLE_TYPE macro in the implementation.
*/
struct ISerializable : VirtualBase
{
    //! writes object to a stream
    virtual void write(std::ostream& outStream) const = 0; // use SERIALIZABLE_TYPE to generate overriding declaration
    //! reads object from a stream
    virtual void read(std::istream& inStream) = 0;         // use SERIALIZABLE_TYPE to generate overriding declaration
    //! returns serializable object's class name
    virtual std::string getClassName() const = 0;          // use SERIALIZABLE_TYPE to generate overriding declaration
                                                           // use REGISTER_SERIALIZABLE_TYPE to generate implementation
};
using ISerializablePtr = std::unique_ptr<ISerializable>;
