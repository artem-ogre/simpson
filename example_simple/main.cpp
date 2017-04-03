// serialization
#include <Serialization.h>
#include <SerializationToStream.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace simpson;

struct Point2D final : ISerializable
{
    float x;
    float y;

    // ISerializable interface
private:
    virtual void serialize(IStorage &outStream) override
    {
        outStream | x | y;
    }
    virtual std::string typeName() const override { return "point_2d"; }
};

SIMPSON_REGISTER_TYPE_WITH_NAME(Point2D, "point_2d")

int main(int argc, char *argv[])
{
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
