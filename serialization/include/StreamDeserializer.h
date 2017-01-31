#pragma once

#include "IDeserializer.h"
#include "StreamStorageIn.h"

#include <iostream>

//! \brief Deserializes serializable from a stream
class StreamDeserializer : public IDeserializer
{
public:
    StreamDeserializer(std::istream& inStream);
    // IDeserializer interface
    virtual ISerializable* deserialize() override;
private:
    StreamStorageIn m_storage;
};

std::istream& operator>>(std::istream& inStream, ISerializable& obj);
