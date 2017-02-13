#pragma once

#include "ISerializer.h"

#include <iostream>

namespace simpson {

//! \brief Serializes a serializable object using a provided storage write class.
//! \tparam TStorageWrite storage type used for serialization
template <typename TStorageWrite>
class Serializer : public ISerializer
{
public:
    explicit Serializer(std::ostream& outStream);
    // ISerializer interface
    virtual void serialize(ISerializable* obj) override;

private:
    TStorageWrite m_storage;
};

} // simpson

#include "Serializer.tpp"
