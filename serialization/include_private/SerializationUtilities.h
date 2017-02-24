/// \file
/// \brief Contains serialization utility functions.

#pragma once

#include <string>

namespace simpson {

struct ISerializable;

namespace SerializationUtilities {

using SerializableFactoryFunction = ISerializable* (*)();

/// Creates a concrete serializable type provided as a template parameter
template <typename T>
ISerializable* createSerializable() { return new T; }
/// Registers a new serializable type with its type name and a factory function.
/// \param typeName name of the serializable type class
/// \param factory serializable type factory
void addTypeFactoryFunction(const std::string& typeName, SerializableFactoryFunction factoryFunction);
/// Creates a concrete serializable type by its class name.
/// \param typeName name of the serializable type class
/// \return serializable base pointer holding a concrete serializable type
ISerializable* createByTypeName(const std::string& typeName);

} // SerializationUtilities
} // simpson
