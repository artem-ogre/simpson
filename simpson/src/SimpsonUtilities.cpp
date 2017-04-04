#include "SimpsonUtilities.h"
#include "ISerializable.h"

#include <map>

using namespace simpson;
using namespace utilities;

namespace
{
const std::runtime_error notRegistered("The class identificator is not registered in the map");
const std::runtime_error alreadyRegistered("The class identificator is already registered in the map");

using FactoryFunctionMap = std::map<std::string, SerializableFactoryFunction>;
FactoryFunctionMap &factoryFunctionMap()
{
    static FactoryFunctionMap _factoryFunctionMap;
    return _factoryFunctionMap;
}
}

void utilities::registerSerializableType(
    const std::string &typeName,
    SerializableFactoryFunction factoryFunction)
{
    auto search = factoryFunctionMap().find(typeName);
    if(search != factoryFunctionMap().end())
        throw alreadyRegistered;
    factoryFunctionMap()[typeName] = factoryFunction;
}

ISerializable *utilities::createByTypeName(const std::string &typeName)
{
    auto search = factoryFunctionMap().find(typeName);
    if(search == factoryFunctionMap().end())
        throw notRegistered;
    return search->second();
}
