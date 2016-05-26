#pragma once

#define REGISTER_TYPE(klass)						\
class klass##Factory : public IStreamableFactory	\
{													\
public:												\
	klass##Factory()								\
	{												\
		IStreamable::registerClass(#klass, this);	\
	}												\
	virtual IStreamable *create() const override	\
	{												\
		return new klass();							\
	}												\
};													\
static klass##Factory global_##klass##Factory;		\
													\
std::string klass::getClassName() const				\
{													\
	return #klass;									\
}