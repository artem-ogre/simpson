#include "StreamSerialization.h"

#include "StorageReadStream.h"
#include "StorageWriteStream.h"
#include "Serialization.h"

#include <memory>

namespace simpson
{
std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    StorageWriteStream storage(outStream);
    serializeToStorage(&obj, storage);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    StorageReadStream storage(inStream);
    obj = deserializeFromStorage(storage);
    return inStream;
}
}
