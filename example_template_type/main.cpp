// serialization
#include <Simpson.h>
#include <StreamSerialization.h>

#include <fstream>
#include <iostream>
#include <string>

template <typename TCoord>
struct Point2D : simpson::ISerializable
{
    TCoord x;
    TCoord y;

protected:
    // ISerializable interface
    virtual void serialize(simpson::IStorage &storage) override
    {
        storage | x | y;
    }

private:
    virtual std::string typeName() const override;
};
SIMPSON_REGISTER_TYPE(Point2D<float>)
template <typename TCoord>
std::string Point2D<TCoord>::typeName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point2D<TCoord>);
}

template <typename TCoord>
struct Point3D final : Point2D<TCoord>
{
    TCoord z;

private:
    // ISerializable interface
    virtual void serialize(simpson::IStorage &storage) override
    {
        Point2D<TCoord>::serialize(storage);
        storage | z;
    }
    virtual std::string typeName() const override;
};
SIMPSON_REGISTER_TYPE(Point3D<float>)
template <typename TCoord>
std::string Point3D<TCoord>::typeName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point3D<TCoord>);
}

void serialize()
{
    Point3D<float> p2d;
    p2d.x = 1.0f;
    p2d.y = 2.0f;
    Point3D<float> p3d;
    p3d.x = 1.1f;
    p3d.y = 2.1f;
    p3d.z = 3.1f;

    std::ofstream outFile("out_test.txt");
    if(!outFile.is_open())
        throw std::runtime_error("can't open the output file");
    outFile << p2d << p3d;
    outFile.close();
    std::cout << p2d << p3d << std::endl;
}

void deserialize()
{
    Point3D<float> p2d;
    Point3D<float> p3d;

    std::ifstream inFile("out_test.txt");
    if(!inFile.is_open())
        throw std::runtime_error("can't open the input file");
    inFile >> &p2d >> &p3d;
    inFile.close();
    std::cout << p2d << p3d << std::endl;
}

int main(int argc, char *argv[])
{
    serialize();
    deserialize();
}
