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
    virtual void serialize(IStorageWrite &outStream) const override { outStream << x << y; }
    virtual void deserialize(IStorageRead &inStream) override { inStream >> x >> y; }
private:
    virtual std::string getClassName() const override { return RegisteredTypes<Point2D<TCoord>>::name; }
};

template <typename TCoord>
struct Point3D : Point2D<TCoord>
{
    TCoord z;
    static ISerializable *create() { return new Point3D<TCoord>(); }

    // ISerializable interface
private:
    virtual void serialize(IStorageWrite &outStream) const override
    {
        Point2D<TCoord>::serialize(outStream);
        outStream << z;
    }
    virtual void deserialize(IStorageRead &inStream) override
    {
        Point2D<TCoord>::deserialize(inStream);
        inStream >> z;
    }
    virtual std::string getClassName() const override { return RegisteredTypes<Point3D<TCoord>>::name; }
};

using Point2DFloat = Point2D<float>;
using Point3DFloat = Point3D<float>;

SIMPSON_REGISTER_TEMPLATE_TYPE_ALIAS(Point2DFloat)
SIMPSON_REGISTER_TEMPLATE_TYPE_ALIAS(Point3DFloat)

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
    }

    std::cout << p2d << p3d << std::endl;

    {
        std::ifstream inFile("out_test.txt");
        if(!inFile.is_open())
            throw std::runtime_error("can't open the input file");
        inFile >> &p2d >> &p3d;
        inFile.close();
    }

    std::cout << p2d << p3d << std::endl;
}
