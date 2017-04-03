#pragma once

#include "ISerializer.h"

#include <iostream>

namespace simpson
{

//! \brief Serializes a serializable object using a provided storage write class.
//! \tparam TStorageWrite storage type used for serialization
template <typename TStreamStorage>
class StreamSerializer final : public ISerializer
{
public:
    explicit StreamSerializer(std::ostream& outStream);

private:
    // ISerializer interface
    virtual void serialize(ISerializable* obj) override;
    virtual ISerializable* deserialize() override;

private:
    TStreamStorage m_storage;
};

} // simpson

#include "StreamSerializer.tpp"
