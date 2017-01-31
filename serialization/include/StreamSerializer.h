#pragma once

#include "ISerializer.h"
#include "StreamStorageOut.h"

#include <iostream>

//! \brief Serializes serializable to a stream
class StreamSerializer : public ISerializer
{
public:
    StreamSerializer(std::ostream& outStream);
    // ISerializer interface
    virtual void serialize(ISerializable* obj) override;
private:
    StreamStorageOut m_storage;
};

std::ostream& operator<<(std::ostream& outStream, ISerializable& obj);
