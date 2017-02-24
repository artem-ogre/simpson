/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

namespace simpson
{
template <typename T> struct RegisteredTypeNames {};
}

#define SIMPSON_REGISTER_TYPE_NAME(type_name)                                                                \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct RegisteredTypeNames<type_name>                                                                        \
    {                                                                                                        \
        static constexpr const char* name = #type_name;                                                      \
    };                                                                                                       \
    }

#define SIMPSON_ADD_TYPE(T, type_name)                                                                  \
    SerializationUtilities::registerType(type_name, SerializationUtilities::createSerializable<T>);

#define SIMPSON_ADD_TYPE_WITH_REGISTERED_NAME(T)                                                                  \
    SerializationUtilities::registerType(RegisteredTypeNames<T>::name, SerializationUtilities::createSerializable<T>);
