#include "Serialization.h"

#include "ISerializable.h"
#include "IStorage.h"
#include "SerializationUtilities.h"

using namespace simpson;
using namespace SerializationUtilities;

void simpson::serialize(ISerializable *obj, IStorage &storage)
{
    std::string typeName = obj->typeName();
    storage | typeName;
    obj->serialize(storage);
}

ISerializable *simpson::deserialize(IStorage &storage)
{
    std::string typeName;
    storage | typeName;
    ISerializable *serializable = createByTypeName(typeName);
    serializable->serialize(storage);
    return serializable;
}
