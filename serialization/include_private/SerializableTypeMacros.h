/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

namespace simpson
{
template <typename T> struct AutoTypeNames {};
}

#define SIMPSON_REGISTER_AUTO_TYPE_NAME(T)                                                                        \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct AutoTypeNames<T>                                                                            \
    {                                                                                                        \
        static constexpr const char* name = #T;                                                              \
    };                                                                                                       \
    }

#define SIMPSON_ADD_TYPE(T, typeName)                                                                        \
    SerializationUtilities::registerType(typeName, SerializationUtilities::createSerializable<T>);

#define SIMPSON_ADD_TYPE_WITH_REGISTERED_NAME(T)                                                             \
    SerializationUtilities::registerType(                                                                    \
        AutoTypeNames<T>::name, SerializationUtilities::createSerializable<T>);
