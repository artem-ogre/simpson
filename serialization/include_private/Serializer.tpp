#pragma once

#include "ISerializable.h"
#include "Serializer.h"

namespace simpson
{

template <typename TStorageWrite>
Serializer<TStorageWrite>::Serializer(std::ostream& outStream)
    : m_storage(outStream)
{}

template <typename TStorageWrite>
void Serializer<TStorageWrite>::serialize(ISerializable* obj)
{
    m_storage << obj->typeName();
    obj->serialize(m_storage);
}

}
