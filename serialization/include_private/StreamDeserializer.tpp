#pragma once

#include "ISerializable.h"
#include "IStorage.h"
#include "SerializationUtilities.h"

namespace simpson
{

template <typename TStreamStorage>
StreamDeserializer<TStreamStorage>::StreamDeserializer(std::istream& inStream)
    : m_storage(inStream)
{}

template <typename TStreamStorage>
void StreamDeserializer<TStreamStorage>::serialize(ISerializable* obj)
{
    throw std::runtime_error("Calling serialize on read-only serializer");
}

template <typename TStreamStorage>
ISerializable* StreamDeserializer<TStreamStorage>::deserialize()
{
    std::string typeName;
    IStorage & storageRef = m_storage;
    storageRef | typeName;
    ISerializable* serializable = SerializationUtilities::createByTypeName(typeName);
    serializable->serialize(storageRef);
    return serializable;
}

}
