/// \file
/// \brief Contains serialization utility functions.

#pragma once

#include <string>

namespace simpson
{
struct ISerializable;
}

namespace simpson
{
namespace utilities
{

/// Factory function creating serializable
using SerializableFactoryFunction = ISerializable* (*)();

/// Creates a concrete serializable type provided as a template parameter
template <typename T>
ISerializable* createSerializable()
{
    return new T;
}

/// Registers a new serializable type with its type name and a factory function.
/// \param typeName name of the serializable type class
/// \param factory serializable type factory
void registerSerializableType(const std::string& typeName, SerializableFactoryFunction factoryFunction);

/// Creates a concrete serializable type by its class name.
/// \param typeName name of the serializable type class
/// \return serializable base pointer holding a concrete serializable type
ISerializable* createByTypeName(const std::string& typeName);

/// Static instance is created for each serializable type.
/// Constructor registers the type.
template <typename T>
struct SerializableRegistrar
{
    /*!
     * \brief Constructor that registers a serializable type
     * \param type_name name of the serializable type to be regiestered
     */
    SerializableRegistrar(const char* typeName)
    {
        // registerType adds a type_name->factory_function entry to the map
        registerSerializableType(typeName, createSerializable<T>);
    }
};

} // SerializationUtilities
}
