#include "Serialize.h"

#include "ISerializable.h"
#include "IStorage.h"
#include "SimpsonUtilities.h"

using namespace simpson;
using namespace utilities;
using namespace serialize;

void simpson::serialize::serializeToStorage(ISerializable *obj, IStorage &storage)
{
    std::string typeName = obj->getSerializableName();
    storage | typeName;
    obj->serialize(storage);
}

ISerializable *simpson::serialize::deserializeFromStorage(IStorage &storage)
{
    std::string typeName;
    storage | typeName;
    ISerializable *serializable = createByTypeName(typeName);
    serializable->serialize(storage);
    return serializable;
}
