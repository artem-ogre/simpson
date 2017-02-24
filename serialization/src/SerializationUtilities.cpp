#include "SerializationUtilities.h"
#include "ISerializable.h"

#include <map>

using namespace simpson;

namespace
{

const std::runtime_error notRegistered("The class identificator is not registered in the map");
const std::runtime_error alreadyRegistered("The class identificator is already registered in the map");

using FactoryFunctionMap = std::map<std::string, SerializationUtilities::SerializableFactoryFunction>;
FactoryFunctionMap &factoryMap()
{
    static FactoryFunctionMap _factoryMap;
    return _factoryMap;
}

} // namespace

void SerializationUtilities::registerType(
    const std::string &typeName,
    SerializableFactoryFunction factoryFunction)
{
    auto search = factoryMap().find(typeName);
    if(search != factoryMap().end())
        throw alreadyRegistered;
    factoryMap()[typeName] = factoryFunction;
}

ISerializable *SerializationUtilities::create(const std::string &typeName)
{
    auto search = factoryMap().find(typeName);
    if(search == factoryMap().end())
        throw notRegistered;
    return search->second();
}
