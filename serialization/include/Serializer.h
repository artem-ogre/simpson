#pragma once

#include "ISerializer.h"

#include <iostream>

//! \brief Serializes a serializable object using a provided storage write class
//! \tparam TStorageWrite storage type used for serialization
template <typename TStorageWrite>
class Serializer : public ISerializer
{
public:
    Serializer(std::ostream& outStream);
    // ISerializer interface
    virtual void serialize(ISerializable* obj) override;

private:
    TStorageWrite m_storage;
};

#include "Serializer.tpp"
