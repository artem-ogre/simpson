/*!
 * \file
 * \brief This header contains functionality needed for implementing your custom serializable types
 * \details Supports polymorphic serialization and unserialization to the stream and overloads streaming operators.
 * Serialization is using an abstract factory with named constructor idiom.
 * Classes implementing the interface need to override serialize method.
 * !In order for the class to be serializable the type needs to be registered with a macro.
 */
#pragma once

#include "ISerializable.h"
#include "IStorage.h"
#include "SerializableTypeMacros.h"
