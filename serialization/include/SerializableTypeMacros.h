#pragma once

/*!
*  Macro must be inserted in the beginning of the class declaration in order for the type to be serializable
*/
#define SERIALIZABLE_TYPE                                                                                    \
    public:                                                                                                  \
        virtual std::string getClassName() const override;                                                   \
        virtual void saveTo(std::ostream& outStream) const override;                                         \
        virtual void loadFrom(IStorageIn& inStream) override;                                              \
    private:
/*!
*   Automatically generates a factory for the serializable type
*   and defines a getClassName function returning serializable type name.
*   Must be inserted in the implementation file.
*/
#define REGISTER_SERIALIZABLE_TYPE(type_name)                                                                \
    struct type_name##Factory : ISerializableFactory                                                         \
    {                                                                                                        \
        type_name##Factory() { SerializableTypes::registerType(#type_name, this); }                          \
        virtual ISerializable* create() const override { return new type_name; }                             \
    };                                                                                                       \
    static type_name##Factory global_##type_name##Factory;                                                   \
    std::string type_name::getClassName() const { return #type_name; }
