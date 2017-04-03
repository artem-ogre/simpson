#pragma once

#include "ISerializable.h"
#include "Serializer.h"
#include "SerializationUtilities.h"

namespace simpson
{

template <typename TStorage>
Serializer<TStorage>::Serializer(std::ostream& outStream)
    : m_storage(outStream)
{}

template <typename TStorage>
Serializer<TStorage>::Serializer(std::istream& inStream)
    : m_storage(inStream)
{}

template <typename TStorage>
void Serializer<TStorage>::serialize(ISerializable* obj)
{
    std::string typeName = obj->typeName();
    m_storage | typeName;
    obj->serialize(m_storage);
}

template <typename TStorage>
ISerializable* Serializer<TStorage>::deserialize()
{
    std::string typeName;
    m_storage | typeName;
    ISerializable* serializable = SerializationUtilities::createByTypeName(typeName);
    serializable->serialize(m_storage);
    return serializable;
}

}
