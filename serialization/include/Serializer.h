#pragma once

#include "ISerializer.h"

#include <iostream>

namespace simpson {

//! \brief Serializes a serializable object using a provided storage write class.
//! \tparam TStorageWrite storage type used for serialization
template <typename TStorage>
class Serializer : public ISerializer
{
public:
    explicit Serializer(std::ostream& outStream);
    explicit Serializer(std::istream& inStream);
    // ISerializer interface
    virtual void serialize(ISerializable* obj) override;
    virtual ISerializable* deserialize() override;

private:
    TStorage m_storage;
};

} // simpson

#include "Serializer.tpp"
