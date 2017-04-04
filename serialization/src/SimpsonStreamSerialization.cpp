#include "SimpsonStreamSerialization.h"

#include "StorageReadStream.h"
#include "StorageWriteStream.h"
#include "Serialize.h"

#include <memory>

using namespace simpson;
using namespace serialize;

std::ostream& simpson::operator<<(std::ostream& outStream, ISerializable& obj)
{
    StorageWriteStream storage(outStream);
    serializeToStorage(&obj, storage);
    return outStream;
}

std::istream& simpson::operator>>(std::istream& inStream, ISerializable* obj)
{
    StorageReadStream storage(inStream);
    obj = deserializeFromStorage(storage);
    return inStream;
}
