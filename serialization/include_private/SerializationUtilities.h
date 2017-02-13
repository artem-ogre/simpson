#pragma once

#include <string>

namespace simpson {

struct ISerializableFactory;
struct ISerializable;

namespace SerializationUtilities
{
/*!
     * \brief Registers a new serializable type with its class name and a factory
     * \param className name of the serializable type class
     * \param factory serializable type factory
     */
void registerType(const std::string& className, ISerializableFactory* factory);
/*!
     * \brief Creates a concrete serializable type by its class name
     * \param className name of the serializable type class
     * \return serializable base pointer holding a concrete serializable type
     */
ISerializable* create(const std::string& className);
};

}
