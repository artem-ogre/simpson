/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

namespace simpson
{
template <typename T> struct RegisteredTypes {};
}

#define SIMPSON_REGISTER_TYPE_NAME(type_name)                                                                \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct RegisteredTypes<type_name>                                                                        \
    {                                                                                                        \
        static constexpr const char* name = #type_name;                                                      \
    };                                                                                                       \
    }

#define SIMPSON_TYPE_NAME(type_name)                                                                         \
    virtual std::string getClassName() const override { return RegisteredTypes<type_name>::name; };

#define SIMPSON_ADD_TYPE_FACTORY_FUNCTION(type_name)                                                                  \
    SerializationUtilities::registerType(RegisteredTypes<type_name>::name, SerializationUtilities::createSerializable<type_name>);
