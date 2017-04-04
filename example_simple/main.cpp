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
    std::string getSerializableName() const override;
};
SIMPSON_REGISTER_TYPE_WITH_NAME(Point2D, "point_2d")
std::string Point2D::getSerializableName() const
{
    return SIMPSON_REGISTERED_TYPE_NAME(Point2D);
}

void serialize()
{
    Point2D p2d;
    p2d.x = 1.0f;
    p2d.y = 2.0f;
    std::ofstream outFile("out_test.txt");
    if(!outFile.is_open())
        throw std::runtime_error("can't open the output file");
    outFile << p2d;
    outFile.close();
    std::cout << p2d << std::endl;
}

void deserialize()
{
    Point2D p2d;
    std::ifstream inFile("out_test.txt");
    if(!inFile.is_open())
        throw std::runtime_error("can't open the input file");
    inFile >> &p2d;
    inFile.close();
    std::cout << p2d << std::endl;
}

int main(int argc, char *argv[])
{
    serialize();
    deserialize();
}
