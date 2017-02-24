/// \file
/// \brief Contains serialization utility functions.

#pragma once

#include <string>

namespace simpson {

struct ISerializable;

namespace SerializationUtilities {

template <typename T>
ISerializable* createSerializable() { return new T; }

using SerializableFactoryFunction = ISerializable* (*)();

/// Registers a new serializable type with its class name and a factory.
/// \param className name of the serializable type class
/// \param factory serializable type factory
void addType(const std::string& typeName, SerializableFactoryFunction factoryFunction);
/// Creates a concrete serializable type by its class name.
/// \param className name of the serializable type class
/// \return serializable base pointer holding a concrete serializable type
ISerializable* createByTypeName(const std::string& typeName);

} // SerializationUtilities
} // simpson
