#include "SerializationUtilities.h"
#include "ISerializable.h"
#include "ISerializableFactory.h"

#include <map>

namespace
{

const std::runtime_error notRegistered("The class identificator is not registered in the map");
const std::runtime_error alreadyRegistered("The class identificator is already registered in the map");

using FactoryMap = std::map<std::string, ISerializableFactory *>;
FactoryMap &factoryMap()
{
    static FactoryMap _factoryMap;
    return _factoryMap;
}

} // namespace

void SerializationUtilities::registerType(const std::string &typeName, ISerializableFactory *factory)
{
    auto search = factoryMap().find(typeName);
    if(search != factoryMap().end())
        throw alreadyRegistered;
    factoryMap()[typeName] = factory;
}

ISerializable *SerializationUtilities::create(const std::string &typeName)
{
    auto search = factoryMap().find(typeName);
    if(search == factoryMap().end())
        throw notRegistered;
    return search->second->create();
}
