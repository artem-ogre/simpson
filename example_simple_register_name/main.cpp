// serialization
#include <Serialization.h>
#include <SerializationToStream.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace simpson;

struct Point2D : ISerializable
{
    float x;
    float y;

    // ISerializable interface
private:
    virtual void serialize(IStorageWrite &outStream) const override { outStream << x << y; }
    virtual void deserialize(IStorageRead &inStream) override { inStream >> x >> y; }
    virtual std::string typeName() const override;
};

SIMPSON_REGISTER_AUTO_TYPE_NAME(Point2D)
std::string Point2D::typeName() const { return AutoTypeNames<Point2D>::name; }

int main(int argc, char *argv[])
{
    SIMPSON_ADD_TYPE_WITH_AUTO_TYPE_NAME(Point2D);
    Point2D p2d;
    p2d.x = 1.0f;
    p2d.y = 2.0f;
    { // serialize
        std::ofstream outFile("out_test.txt");
        if(!outFile.is_open())
            throw std::runtime_error("can't open the output file");
        outFile << p2d;
        outFile.close();
        std::cout << p2d << std::endl;
    }
    { // deserialize
        std::ifstream inFile("out_test.txt");
        if(!inFile.is_open())
            throw std::runtime_error("can't open the input file");
        inFile >> &p2d;
        inFile.close();
        std::cout << p2d << std::endl;
    }
}
