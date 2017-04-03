// serialization
#include <Serialization.h>
#include <SerializationToStream.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace simpson;

template <typename TCoord>
struct Point2D : ISerializable
{
    TCoord x;
    TCoord y;

protected:
    // ISerializable interface
    virtual void serialize(IStorage &storage) override
    {
        storage | x | y;
    }

private:
    virtual std::string typeName() const override;
};

template <typename TCoord>
struct Point3D final : Point2D<TCoord>
{
    TCoord z;

private:
    // ISerializable interface
    virtual void serialize(IStorage &storage) override
    {
        Point2D<TCoord>::serialize(storage);
        storage | z;
    }

    virtual std::string typeName() const override;
};

SIMPSON_REGISTER_TYPE(Point2D<float>) // registering template specialization with alias name
template <typename TCoord>
std::string Point2D<TCoord>::typeName() const
{
    return AutoTypeNames<Point2D<TCoord> >::name;
}

SIMPSON_REGISTER_TYPE(Point3D<float>) // registering template specialization with alias name
template <typename TCoord>
std::string Point3D<TCoord>::typeName() const
{
    return AutoTypeNames<Point3D<TCoord> >::name;
}

int main(int argc, char *argv[])
{
    using Point2DFloat = Point2D<float>;
    using Point3DFloat = Point3D<float>;
    Point2DFloat p2d;
    p2d.x = 1.0f;
    p2d.y = 2.0f;
    Point3DFloat p3d;
    p3d.x = 1.1f;
    p3d.y = 2.1f;
    p3d.z = 3.1f;
    {
        std::ofstream outFile("out_test.txt");
        if(!outFile.is_open())
            throw std::runtime_error("can't open the output file");
        outFile << p2d << p3d;
        outFile.close();
        std::cout << p2d << p3d << std::endl;
    }
    {
        std::ifstream inFile("out_test.txt");
        if(!inFile.is_open())
            throw std::runtime_error("can't open the input file");
        inFile >> &p2d >> &p3d;
        inFile.close();
        std::cout << p2d << p3d << std::endl;
    }
}
