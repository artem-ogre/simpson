/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

#include "SerializationUtilities.h"

// Registers type with its type as with type-as-name
#define SIMPSON_REGISTER_TYPE(T) SIMPSON_REGISTER_TYPE_WITH_NAME(T, #T)

// Registers type with its provided type name
#define SIMPSON_REGISTER_TYPE_WITH_NAME(T, typeName)                                                         \
    SIMPSON_REGISTER_TYPE_NAME(T, typeName)                                                                  \
    namespace                                                                                                \
    {                                                                                                        \
    static simpson::utilities::SerializableRegistrar<T>                                         \
        SIMPSON_UNIQUE_IDENTIFIER(simpson::AutoTypeNames<T>::name);                                          \
    }

// Attaches line-number to fixed identifier
#define SIMPSON_UNIQUE_IDENTIFIER SIMPSON_CREATE_UNIQUE_IDENTIFIER(__LINE__)
#define SIMPSON_CREATE_UNIQUE_IDENTIFIER(line) SIMPSON_MERGE(unique_identifier_on_line_, line)
#define SIMPSON_MERGE(A, B) A##B

// Registers given type name for a type using partial template specialization
#define SIMPSON_REGISTER_TYPE_NAME(T, typeName)                                                              \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct AutoTypeNames<T>                                                                                  \
    {                                                                                                        \
        static constexpr const char* name = typeName;                                                        \
    };                                                                                                       \
    }

// Name of type that is already registered
#define SIMPSON_REGISTERED_TYPE_NAME(T) simpson::AutoTypeNames<T>::name

namespace simpson
{
/// Holds registered type names using partial template specialization
template <typename T> struct AutoTypeNames {};
}
