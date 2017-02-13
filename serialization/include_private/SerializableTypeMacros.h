/*!
 * \file
 * \brief This header contains important helper macros that can be used for developing your serializable
 * classes.
 */

#pragma once

/// Macro must be inserted in the beginning of the class declaration in order for the type to be serializable
#define SIMPSON_IS_A_SERIALIZABLE_TYPE                                                                       \
public:                                                                                                      \
    virtual std::string getClassName() const override;                                                       \
    virtual void serialize(simpson::IStorageWrite& outStream) const override;                                \
    virtual void deserialize(simpson::IStorageRead& inStream) override;                                      \
                                                                                                             \
private:

/// Automatically generates a factory for the serializable type and defines a getClassName function returning
/// serializable type name. Must be inserted in the implementation file.
#define SIMPSON_REGISTER_A_SERIALIZABLE_TYPE(type_name)                                                  \
struct type_name##Factory : simpson::ISerializableFactory                                                \
{                                                                                                        \
    type_name##Factory() { simpson::SerializationUtilities::registerType(#type_name, this); }            \
    virtual simpson::ISerializable* create() const override { return new type_name; }                    \
};                                                                                                       \
static type_name##Factory global_##type_name##Factory;                                                   \
std::string type_name::getClassName() const { return #type_name; }
