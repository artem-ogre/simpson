/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

#define __SIMPSON_ENABLE_TYPE_NAME(type_name)                                                                \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct TypeName<type_name>                                                                               \
    {                                                                                                        \
        static const char* Get() { return #type_name; }                                                      \
    };                                                                                                       \
    }

#define __SIMPSON_REGISTER_TYPE(type_name)                                                                   \
    static SerializableFactory<type_name> global_##type_name##Factory(#type_name);

#define SIMPLE_TYPE_NAME(type_name) #type_name

#define TEMPLATED_TYPE_NAME(type_name) TypeName<type_name>::Get()

#define SIMPSON_REGISTER_SIMPLE_TYPE(type_name) __SIMPSON_REGISTER_TYPE(type_name)

#define SIMPSON_REGISTER_TEMPLATED_TYPE_ALIAS(type_name)                                                           \
    __SIMPSON_REGISTER_TYPE(type_name)                                                                       \
    __SIMPSON_ENABLE_TYPE_NAME(type_name)
