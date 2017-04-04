// serialization
#include <Simpson.h>
#include <StreamSerialization.h>

#include <fstream>
#include <iostream>
#include <string>

struct Point2D final : simpson::ISerializable
{
    float x;
    float y;

private:
    // ISerializable interface
    virtual void serialize(simpson::IStorage &storage) override
    {
        storage | x | y;
    }
    virtual std::string typeName() const override;
};

SIMPSON_REGISTER_TYPE(Point2D)
std::string Point2D::typeName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point2D);
}

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
