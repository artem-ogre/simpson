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
public:
    virtual void serialize(IStorageWrite &outStream) const override { outStream << x << y; }
    virtual void deserialize(IStorageRead &inStream) override { inStream >> x >> y; }
    virtual std::string getClassName() const override;
};

SIMPSON_REGISTER_TYPE(Point2D)
std::string Point2D::getClassName() const { return RegisteredTypes<Point2D>::name; }

int main(int argc, char *argv[])
{
    Point2D p2d;
    p2d.x = 1.0f;
    p2d.y = 2.0f;
    {
        std::ofstream outFile("out_test.txt");
        if(!outFile.is_open())
            throw std::runtime_error("can't open the output file");
        outFile << p2d;
        outFile.close();
    }
    std::cout << p2d << std::endl;

    {
        std::ifstream inFile("out_test.txt");
        if(!inFile.is_open())
            throw std::runtime_error("can't open the input file");
        inFile >> &p2d;
        inFile.close();
    }
    std::cout << p2d << std::endl;
}
