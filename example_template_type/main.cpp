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

    // ISerializable interface
protected:
    virtual void serialize(IStorage &outStream) override { outStream | x | y; }
private:
    virtual std::string typeName() const override;
};

template <typename TCoord>
struct Point3D : Point2D<TCoord>
{
    TCoord z;
    static ISerializable *create() { return new Point3D<TCoord>(); }

    // ISerializable interface
private:
    virtual void serialize(IStorage &outStream) override
    {
        Point2D<TCoord>::serialize(outStream);
        outStream | z;
    }

    virtual std::string typeName() const override;
};

using Point2DFloat = Point2D<float>; // defining an alias
using Point3DFloat = Point3D<float>; // defining an alias

SIMPSON_REGISTER_TYPE(Point2D<float>)  // registering template specialization with alias name
template<typename TCoord>
std::string Point2D<TCoord>::typeName() const { return AutoTypeNames<Point2D<TCoord>>::name; }

SIMPSON_REGISTER_TYPE(Point3D<float>)  // registering template specialization with alias name
template<typename TCoord>
std::string Point3D<TCoord>::typeName() const { return AutoTypeNames<Point3D<TCoord>>::name; }

int main(int argc, char *argv[])
{
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
