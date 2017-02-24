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
void registerType(const std::string& className, SerializableFactoryFunction factoryFunction);
/// Creates a concrete serializable type by its class name.
/// \param className name of the serializable type class
/// \return serializable base pointer holding a concrete serializable type
ISerializable* create(const std::string& className);

} // SerializationUtilities
} // simpson
