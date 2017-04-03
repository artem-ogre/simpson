#pragma once

#include "ISerializable.h"
#include "IStorage.h"
#include "SerializationUtilities.h"
#include "Serializer.h"

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
    IStorage & storageRef = m_storage;
    storageRef | typeName;
    obj->serialize(storageRef);
}

template <typename TStorage>
ISerializable* Serializer<TStorage>::deserialize()
{
    std::string typeName;
    IStorage & storageRef = m_storage;
    storageRef | typeName;
    ISerializable* serializable = SerializationUtilities::createByTypeName(typeName);
    serializable->serialize(storageRef);
    return serializable;
}

}
