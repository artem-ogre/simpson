#include "Serialization.h"

#include "ISerializable.h"
#include "IStorage.h"
#include "SerializationUtilities.h"

using namespace simpson;
using namespace SerializationUtilities;

void simpson::serializeToStorage(ISerializable *obj, IStorage &storage)
{
    std::string typeName = obj->getSerializableName();
    storage | typeName;
    obj->serialize(storage);
}

ISerializable *simpson::deserializeFromStorage(IStorage &storage)
{
    std::string typeName;
    storage | typeName;
    ISerializable *serializable = createByTypeName(typeName);
    serializable->serialize(storage);
    return serializable;
}
