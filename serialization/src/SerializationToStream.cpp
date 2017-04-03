#include "SerializationToStream.h"

#include "StorageReadStream.h"
#include "StorageWriteStream.h"
#include "StreamDeserializer.h"
#include "StreamSerializer.h"

#include <memory>

namespace simpson
{
std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    using StreamWrite = StreamSerializer<StorageWriteStream>;
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamWrite>(outStream);
    serializer->serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    using StreamRead = StreamDeserializer<StorageReadStream>;
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamRead>(inStream);
    obj = serializer->deserialize();
    return inStream;
}
}
