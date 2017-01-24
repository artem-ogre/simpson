#pragma once

#include "VirtualBase.h"
#include "ISerializable.h"

#include <iostream>

//! \brief Interface for serializable object serializer
struct ISerializer : VirtualBase
{
    virtual void serialize(const ISerializable* obj) const = 0;
};

//! \brief Interface for serializable object deserializer
struct IDeserializer : VirtualBase
{
    virtual ISerializablePtr deserialize() const = 0;
};

//! \brief Serializes serializable to a stream
class StreamSerializer : public ISerializer
{
public:
    StreamSerializer(std::ostream& outStream);
    // ISerializer interface
    virtual void serialize(const ISerializable *obj) const;
private:
    std::ostream& m_outStream;
};

//! \brief Deserializes serializable from a stream
class StreamDeserializer : public IDeserializer
{
public:
    StreamDeserializer(std::istream& inStream);
    // IDeserializer interface
    virtual ISerializablePtr deserialize() const;
private:
    std::istream& m_inStream;
};

std::ostream& operator<<(std::ostream& outStream, const ISerializable& obj);
std::istream& operator>>(std::istream& inStream, ISerializable& obj);
