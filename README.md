# SIMPSON: A <b>Sim</b>ple <b>P</b>olymorphic <b>S</b>erializati<b>on</b> Library

## Overview
SIMPSON's goal is to provide **polymorphic serialization** in C++ with simple and clean code, that can be easily understood. It is written using **C++14**. SIMPSON is a small hobby project and is not meant to compete with industy-strength libraries as boost::serialization or cereal. Its functionality is rather limited.
This repository contains SIMPSON library itself and a couple of examples.

## What is polymorphic serialization?
Polymorphic serialization enables concrete-class serialization and deserialization using common base-class interface:
```c++
Derived a;
Derived b;
Base * ptrA = &a;
Base * ptrB = &b;
file << ptrA;
file >> ptrB;
```
This code will result in `a == b`.

## What are SIMPSON's strong points?
- Minimalistic
- Simple
- Does not require RTTI
- Works with template classes

## How about a simple example?
```c++
struct Point2D : simpson::ISerializable
{
    float x;
    float y;
private:
    // simpson::ISerializable interface
    virtual void serialize(simpson::IStorage &storage) override
    {
        storage | x | y;
    }
    virtual std::string getSerializableName() const override;
};
SIMPSON_REGISTER_TYPE(Point2D)
std::string Point2D::getSerializableName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point2D);
}
```
This is all that's needed to make `Point2D` polymorphically serializable.

## How about a more complex example?
```c++
template <typename TCoord>
struct Point2D : simpson::ISerializable
{
    TCoord x;
    TCoord y;
protected:
    virtual void serialize(simpson::IStorage &storage) override
    {
        storage | x | y;
    }
private:
    virtual std::string getSerializableName() const override;
};
SIMPSON_REGISTER_TYPE(Point2D<float>)
template <typename TCoord>
std::string Point2D<TCoord>::getSerializableName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point2D<TCoord>);
}

template <typename TCoord>
struct Point3D final : Point2D<TCoord>
{
    TCoord z;
private:
    virtual void serialize(simpson::IStorage &storage) override
    {
        Point2D<TCoord>::serialize(storage);
        storage | z;
    }
    virtual std::string getSerializableName() const override;
};
SIMPSON_REGISTER_TYPE(Point3D<float>)
template <typename TCoord>
std::string Point3D<TCoord>::getSerializableName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point3D<TCoord>);
}
```
Now you can:
```c++
// serialize
Point3D<float> p2d = ...;
Point3D<float> p3d = ...;
fileStream << p2d << p3d;
// deserialize
Point3D<float> p2d_2;
Point3D<float> p3d_2;
fileStream >> p2d_2 >> p3d_2;
```
