#pragma once

#include "Deserializer.h"
#include "ISerializable.h"
#include "SerializationUtilities.h"

namespace simpson {

template <typename TStorageRead>
Deserializer<TStorageRead>::Deserializer(std::istream& inStream)
    : m_storage(inStream)
{}

template <typename TStorageRead>
ISerializable* Deserializer<TStorageRead>::deserialize()
{
    std::string typeName;
    m_storage >> typeName;
    ISerializable* result = SerializationUtilities::createByTypeName(typeName);
    result->deserialize(m_storage);
    return result;
}

}
