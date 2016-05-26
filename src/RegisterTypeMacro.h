#pragma once

/*!
*  Macro must be inserted in the beginning of the class declaration in order for the type to be serializable
*/
#define SERIALIZABLE_TYPE												\
public:																	\
	virtual std::string getClassName() const override;					\
	virtual void writeState( std::ostream& outStream ) const override;	\
	virtual void readState( std::istream& inStream ) override;			\
private:

/*!
*   Automatically generates a factory class for the serializable class
*   and defines a consistent getClassName function.
*   Must be inserted in the implementation file.
*/
#define REGISTER_TYPE(class_name)								\
class class_name##Factory : public IStreamableFactory			\
{																\
public:															\
	class_name##Factory()										\
	{															\
		IStreamable::registerType(#class_name, this);			\
	}															\
	virtual IStreamable *create() const override				\
	{															\
		return new class_name();								\
	}															\
};																\
static class_name##Factory global_##class_name##Factory;		\
																\
std::string class_name::getClassName() const					\
{																\
	return #class_name;											\
}