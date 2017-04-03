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

#define SIMPSON_REGISTER_TYPE_NAME(T, typeName)                                                              \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct AutoTypeNames<T>                                                                                  \
    {                                                                                                        \
        static constexpr const char* name = typeName;                                                        \
    };                                                                                                       \
    }

#define SIMPSON_MERGE(A, B) A##B
#define SIMPSON_CREATE_UNIQUE_IDENTIFIER(line) SIMPSON_MERGE(unique_identifier_on_line_, line)
#define SIMPSON_UNIQUE_IDENTIFIER SIMPSON_CREATE_UNIQUE_IDENTIFIER(__LINE__)

#define SIMPSON_REGISTER_TYPE_WITH_NAME(T, typeName)                                                         \
    SIMPSON_REGISTER_TYPE_NAME(T, typeName)                                                                  \
    namespace                                                                                                \
    {                                                                                                        \
    static SerializationUtilities::SerializableRegistrar<T>                                                  \
        SIMPSON_UNIQUE_IDENTIFIER(AutoTypeNames<T>::name);                                                   \
    }

#define SIMPSON_REGISTER_TYPE(T) SIMPSON_REGISTER_TYPE_WITH_NAME(T, #T)
