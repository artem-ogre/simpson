#pragma once

#include "ISerializable.h"
#include "Serializer.h"

template <typename TStorageWrite>
Serializer<TStorageWrite>::Serializer(std::ostream& outStream)
    : m_storage(outStream)
{}

template <typename TStorageWrite>
void Serializer<TStorageWrite>::serialize(ISerializable* obj)
{
    m_storage << " " << obj->getClassName();
    obj->saveTo(m_storage);
}
