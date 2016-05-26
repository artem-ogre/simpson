#pragma once

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