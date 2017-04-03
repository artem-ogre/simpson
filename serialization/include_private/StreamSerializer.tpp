#pragma once

#include "ISerializable.h"
#include "IStorage.h"

namespace simpson
{

template <typename TStreamStorage>
StreamSerializer<TStreamStorage>::StreamSerializer(std::ostream& outStream)
    : m_storage(outStream)
{}

template <typename TStreamStorage>
void StreamSerializer<TStreamStorage>::serialize(ISerializable* obj)
{
    std::string typeName = obj->typeName();
    IStorage & storageRef = m_storage;
    storageRef | typeName;
    obj->serialize(storageRef);
}

template <typename TStreamStorage>
ISerializable* StreamSerializer<TStreamStorage>::deserialize()
{
    throw std::runtime_error("Calling deserialize on write-only serializer");
}

}
