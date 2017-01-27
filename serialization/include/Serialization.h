//! This header contains functionality needed for implementing your custom serializable types
/*!
Supports polymorphic serialization and unserialization to the stream and overloads streaming operators.
Serialization is using an abstract factory with named constructor idiom.
Classes implementing the interface need to override writeState and readState methods.
!In order for the class to be serializable use SERIALIZABLE_TYPE macro in declaration
and REGISTER_SERIALIZABLE_TYPE macro in implementation.
*/
#pragma once

#include "ISerializable.h"
#include "ISerializableFactory.h"
#include "SerializableTypeMacros.h"
#include "SerializableTypes.h"
