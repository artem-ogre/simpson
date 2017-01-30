#pragma once

#include "ISerializer.h"

#include <iostream>

//! \brief Serializes serializable to a stream
class StreamSerializer : public ISerializer
{
public:
    StreamSerializer(std::ostream& outStream);
    // ISerializer interface
    virtual void serialize(const ISerializable* obj) const;
private:
    std::ostream& m_outStream;
};

std::ostream& operator<<(std::ostream& outStream, const ISerializable& obj);
