#include "StreamOperators.h"

#include "StreamReadStorage.h"
#include "StreamWriteStorage.h"
#include "Serialize.h"

#include <memory>

using namespace simpson;
using namespace serialize;

std::ostream& simpson::operator<<(std::ostream& outStream, ISerializable& obj)
{
    StreamWriteStorage storage(outStream);
    serializeToStorage(&obj, storage);
    return outStream;
}

std::istream& simpson::operator>>(std::istream& inStream, ISerializable* obj)
{
    StreamReadStorage storage(inStream);
    obj = deserializeFromStorage(storage);
    return inStream;
}
