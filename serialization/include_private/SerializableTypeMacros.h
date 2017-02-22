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

#define SIMPSON_PRIVATE_ENABLE_TYPE_NAME(type_name)                                                          \
    namespace simpson                                                                                        \
    {                                                                                                        \
    template <>                                                                                              \
    struct RegisteredTypes<type_name>                                                                        \
    {                                                                                                        \
        static constexpr const char* name = #type_name;                                                      \
    };                                                                                                       \
    }

#define SIMPSON_PRIVATE_REGISTER_TYPE(type_name)                                                             \
    static SerializableFactory<type_name> global_##type_name##Factory(#type_name);

#define SIMPSON_PRIVATE_DEFINE_GET_CLASS_NAME(type_name)                                                     \
    std::string type_name::getClassName() const { return RegisteredTypes<type_name>::name; }

#define SIMPSON_REGISTER_TEMPLATE_TYPE_ALIAS(type_name)                                                      \
    SIMPSON_PRIVATE_REGISTER_TYPE(type_name)                                                                 \
    SIMPSON_PRIVATE_ENABLE_TYPE_NAME(type_name)

#define SIMPSON_REGISTER_NONTEMPLATE_TYPE(type_name)                                                         \
    SIMPSON_PRIVATE_REGISTER_TYPE(type_name)                                                                 \
    SIMPSON_PRIVATE_ENABLE_TYPE_NAME(type_name)                                                              \
    SIMPSON_PRIVATE_DEFINE_GET_CLASS_NAME(type_name)
