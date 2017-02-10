#pragma once

#include "Deserializer.h"
#include "ISerializable.h"
#include "SerializationUtilities.h"

template <typename TStorageRead>
Deserializer<TStorageRead>::Deserializer(std::istream& inStream)
    : m_storage(inStream)
{}

template <typename TStorageRead>
ISerializable* Deserializer<TStorageRead>::deserialize()
{
    std::string typeName;
    m_storage >> typeName;
    ISerializable* result = SerializationUtilities::create(typeName);
    result->loadFrom(m_storage);
    return result;
}
