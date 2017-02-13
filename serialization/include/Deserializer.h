#pragma once

#include "IDeserializer.h"

#include <iostream>

//! \brief Deserializes a serializable object using a provided storage read class
//! \tparam TStorageRead storage type used for deserialization
template <typename TStorageRead>
class Deserializer : public IDeserializer
{
public:
    explicit Deserializer(std::istream& inStream);
    // IDeserializer interface
    virtual ISerializable* deserialize() override;

private:
    TStorageRead m_storage;
};

#include "Deserializer.tpp"
